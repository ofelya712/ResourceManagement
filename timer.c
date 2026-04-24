#include "timer.h"

volatile uint16_t g_seconds   = 0;
volatile uint16_t g_counter   = 0;
volatile uint8_t  g_tick_flag = 0;

void timer_init(void)
{
    TCCR1A = 0;  TCCR1B = 0;  TCNT1 = 0;
    OCR1A  = TIMER_100MS;
    TCCR1B |= (1 << WGM12);         /* CTC mode */
    TCCR1B |= (1 << CS12);          /* Prescaler 256 */
    TIMSK1 |= (1 << OCIE1A);        /* Enable Compare Match Interrupt */
    sei();                          /* Enable Global Interrupts */
}

ISR(TIMER1_COMPA_vect)
{
    g_tick_flag++;     /* Increment tick counter */
    g_counter++;
    if (g_counter >= 10) {
        g_counter = 0;
        g_seconds++;   /* Increment seconds every 10 ticks */
    }
}
