
#include <stdio.h>
#include <stdbool.h>

// Step 1: Define function pointer types
typedef float (*ReadTemperature)(void);
typedef void (*SetFanSpeed)(int speed);
typedef void (*SetHeater)(bool enable);
typedef void (*EmergencyShutdown)(void);

// Step 2: Structure holding function pointers
typedef struct
{
    ReadTemperature read_temp;
    SetFanSpeed set_fan;
    SetHeater set_heater;
    EmergencyShutdown shutdown;

} ThermalOps;

// Step 3: Thermal manager structure
typedef struct
{
    float current_temp;
    const ThermalOps *ops;

} ThermalManager;

// Step 4: Simulated hardware implementation

static float simulated_temperature = 25.0f;

float sensor_read(void)
{
    return simulated_temperature;
}

void fan_control(int speed)
{
    printf("Fan speed: %d%%\n", speed);
}

void heater_control(bool enable)
{
    printf("Heater: %s\n",
           enable ? "ON" : "OFF");
}

void system_shutdown(void)
{
    printf("CRITICAL: Emergency shutdown requested!\n");
}

// Step 5: Assign function addresses
const ThermalOps hardware_ops = {
    .read_temp = sensor_read,
    .set_fan = fan_control,
    .set_heater = heater_control,
    .shutdown = system_shutdown
};

// Step 6: Thermal management algorithm
void thermal_manage(ThermalManager *manager)
{
    float temp = manager->ops->read_temp();

    manager->current_temp = temp;

    printf("\nTemperature: %.1f C\n", temp);

    if (temp < 10.0f)
    {
        manager->ops->set_fan(0);
        manager->ops->set_heater(true);
    }
    else if (temp < 40.0f)
    {
        manager->ops->set_heater(false);
        manager->ops->set_fan(0);
    }
    else if (temp < 60.0f)
    {
        manager->ops->set_heater(false);
        manager->ops->set_fan(40);
    }
    else if (temp < 80.0f)
    {
        manager->ops->set_heater(false);
        manager->ops->set_fan(80);
    }
    else
    {
        manager->ops->set_heater(false);
        manager->ops->set_fan(100);
        manager->ops->shutdown();
    }
}

// Step 7: Main application
int main(void)
{
    ThermalManager manager = {
        .current_temp = 0.0f,
        .ops = &hardware_ops
    };

    float test_temperatures[] = {
        5.0f, 25.0f, 45.0f, 65.0f, 85.0f
    };

    int count = sizeof(test_temperatures) /
                sizeof(test_temperatures[0]);

    for (int i = 0; i < count; i++)
    {
        simulated_temperature = test_temperatures[i];

        thermal_manage(&manager);
    }

    return 0;
}
