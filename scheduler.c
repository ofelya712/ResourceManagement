#include "scheduler.h"
#include "timer.h"
#include <avr/sleep.h>
#include <util/atomic.h>

static Task    task_list[MAX_TASKS];
static uint8_t task_count = 0;

void scheduler_init(void)
{
    task_count = 0;
    for (uint8_t i = 0; i < MAX_TASKS; i++) {
        task_list[i].func     = 0;
        task_list[i].period   = 0;
        task_list[i].counter  = 0;
        task_list[i].priority = 0;
        task_list[i].enabled  = 0;
    }
}

void scheduler_add_task(void (*func)(void), uint16_t period,
                         uint8_t priority)
{
    if (task_count >= MAX_TASKS) return;
    task_list[task_count].func     = func;
    task_list[task_count].period   = period;
    task_list[task_count].counter  = 0;
    task_list[task_count].priority = priority;
    task_list[task_count].enabled  = 1;
    task_count++;
    
    for (uint8_t i = task_count-1; i > 0; i--) {
        if (task_list[i].priority < task_list[i-1].priority) {
            Task tmp       = task_list[i];
            task_list[i]   = task_list[i-1];
            task_list[i-1] = tmp;
        } else break;
    }
}

void scheduler_run(void)
{
    uint8_t pending_ticks = 0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        pending_ticks = g_tick_flag;
        g_tick_flag = 0;
    }

    if (pending_ticks > 0) {
        while (pending_ticks--) {
            for (uint8_t i = 0; i < task_count; i++) {
                if (!task_list[i].enabled) continue;
                task_list[i].counter++;
                if (task_list[i].counter >= task_list[i].period) {
                    task_list[i].counter = 0;
                    task_list[i].func();
                }
            }
        }
    } else {
        set_sleep_mode(SLEEP_MODE_IDLE);
        sleep_enable();
        sleep_cpu();
        sleep_disable();
    }
}
