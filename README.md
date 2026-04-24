# Resource Management Library

A lightweight, non-preemptive task scheduler designed for AVR microcontrollers (like Arduino Uno/Nano).

## Features
- **100ms Resolution**: Timer-driven ticks (10Hz) for precise task execution.
- **Priority Support**: Tasks are sorted and executed based on priority (lower value = higher priority).
- **Power Efficiency**: Automatically enters **Sleep Mode (IDLE)** when no tasks are pending to save power.
- **Robustness**: Handles multiple pending ticks if a task execution takes longer than the tick interval.

## How to Use
1. **Initialize**: Call `scheduler_init()` and `timer_init()` in your `setup()` function.
2. **Define Tasks**: Create functions for the tasks you want to run.
3. **Add Tasks**: Use `scheduler_add_task(function_ptr, period, priority)`.
   - `period`: Time in 100ms units (e.g., `10` = 1 second, `20` = 2 seconds).
   - `priority`: Lower number = higher priority (e.g., 1 is higher than 5).
4. **Run**: Call `scheduler_run()` inside your `loop()`.

### Example
```cpp
void myTask() {
    Serial.println("Running every 1 second");
}

void setup() {
    Serial.begin(115200);
    scheduler_init();
    timer_init();
    // Add task: run myTask every 10 ticks (10 * 100ms = 1s) with priority 1
    scheduler_add_task(myTask, 10, 1); 
}

void loop() {
    scheduler_run();
}
```

---

# Ռեսուրսների Կառավարման Գրադարան (Resource Management)

Թեթև և արդյունավետ առաջադրանքների պլանավորող (scheduler) նախատեսված AVR միկրոկոնտրոլերների համար (օրինակ՝ Arduino Uno/Nano)։

## Հնարավորություններ
- **100մվ Ճշտություն**: Թայմերի վրա հիմնված աշխատանք (10Հց) ճշգրիտ կատարման համար։
- **Առաջնահերթություն**: Առաջադրանքները դասավորվում և կատարվում են ըստ առաջնահերթության (փոքր արժեքը = բարձր առաջնահերթություն)։
- **Էներգախնայողություն**: Ավտոմատ անցնում է քնի ռեժիմի (**Sleep Mode - IDLE**), երբ չկան կատարվող առաջադրանքներ։
- **Կայունություն**: Ճիշտ է կառավարում կուտակված «թիքերը», եթե առաջադրանքը տևում է 100մվ-ից ավել։

## Ինչպես օգտագործել
1. **Ինիցիալիզացիա**: Կանչեք `scheduler_init()` և `timer_init()` ֆունկցիաները `setup()`-ում։
2. **Սահմանել առաջադրանքներ**: Ստեղծեք ֆունկցիաներ այն գործողությունների համար, որոնք պետք է կատարվեն։
3. **Ավելացնել առաջադրանք**: Օգտագործեք `scheduler_add_task(ֆունկցիայի_հասցե, պարբերականություն, առաջնահերթություն)`։
   - `պարբերականություն`: Ժամանակը 100մվ միավորներով (օրինակ՝ `10` = 1 վայրկյան, `20` = 2 վայրկյան)։
   - `առաջնահերթություն`: Փոքր թիվը նշանակում է բարձր առաջնահերթություն (օրինակ՝ 1-ը ավելի բարձր է, քան 5-ը)։
4. **Գործարկում**: Կանչեք `scheduler_run()` ֆունկցիան `loop()`-ի մեջ։

### Օրինակ
```cpp
void myTask() {
    Serial.println("Աշխատում է ամեն 1 վայրկյանը մեկ");
}

void setup() {
    Serial.begin(115200);
    scheduler_init();
    timer_init();
    // Ավելացնել առաջադրանք: կատարել myTask-ը ամեն 10 թիքը մեկ (10 * 100մվ = 1վ) 1 առաջնահերթությամբ
    scheduler_add_task(myTask, 10, 1); 
}

void loop() {
    scheduler_run();
}
```
