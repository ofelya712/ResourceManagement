#include <Arduino.h>
#include "scheduler.h"
#include "timer.h"

uint8_t tick_ctr = 0;

void PrintHello() {
  Serial.print("Hello ");
 Serial.println(tick_ctr++);
}


void SensorTask() {
  Serial.println("Sensor Task");
}

void ScreenTask() {
  Serial.println("Screen Task");
}

void MonitoringTask() {
  Serial.println("Monitoring Task");
}


void setup() {
  Serial.begin(115200);
 
  // Resource management init
  scheduler_init();
  timer_init();

  // Task initialization
  scheduler_add_task(SensorTask, 5, 0);
  scheduler_add_task(ScreenTask, 50, 2);
  scheduler_add_task(MonitoringTask, 10, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  scheduler_run();

}
