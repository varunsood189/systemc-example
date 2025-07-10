    #include "bus.h"
#include "cpu.h"
#include "sensor.h"
#include "actuator.h"
#include "memory.h"

int sc_main(int, char*[]) {
    // Instantiate modules
    cpu CPU("cpu");
    bus BUS("bus");
    sensor SENSOR("sensor");
    actuator ACT("actuator");
    memory MEM("memory");

    // Connect CPU to bus
    CPU.bus(BUS);

    // Map devices to bus
    BUS.map_device(0x10, &SENSOR);  // Sensor at 0x10
    BUS.map_device(0x20, &MEM);     // Memory at 0x20
    BUS.map_device(0x30, &ACT);     // Actuator at 0x30

    sc_start(100, SC_NS);
    return 0;
}
