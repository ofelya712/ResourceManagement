#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <stdint.h>
#define MAX_TASKS  5

typedef struct {
    void     (*func)(void); /* Կատարվող ֆունկցիայի ցուցիչ       */
    uint16_t period;        /* Կատարման պարբերականությունը (100մվ) */
    uint16_t counter;       /* Ներքին հաշվիչ                     */
    uint8_t  priority;      /* 1 = ամենաբարձր առաջնահերթություն  */
    uint8_t  enabled;       /* 1 = ակտիվ, 0 = անջատված           */
} Task;

#ifdef __cplusplus
extern "C" {
#endif

void scheduler_init(void);
void scheduler_add_task(void (*func)(void), uint16_t period,
                        uint8_t priority);
void scheduler_run(void);

#ifdef __cplusplus
}
#endif

#endif /* SCHEDULER_H */
