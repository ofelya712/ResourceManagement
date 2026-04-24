#ifndef TIMER_H
#define TIMER_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#ifndef F_CPU
#define F_CPU       16000000UL
#endif

#define PRESCALER   256
#define TIMER_100MS ((F_CPU / (PRESCALER * 10)) - 1)  /* Exact value for 10Hz */

#ifdef __cplusplus
extern "C" {
#endif

extern volatile uint16_t g_seconds;
extern volatile uint16_t g_counter;
extern volatile uint8_t  g_tick_flag;

void timer_init(void);

#ifdef __cplusplus
}
#endif

#endif /* TIMER_H */
