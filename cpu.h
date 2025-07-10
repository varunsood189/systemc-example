// cpu.h
#ifndef CPU_H
#define CPU_H

#include "device_if.h"
#include <systemc>

struct cpu : public sc_module {
    sc_port<device_if> bus;

    SC_CTOR(cpu) {
        SC_THREAD(run);
    }

    void run() {
        while (true) {
            // Read from sensor at 0x10
            uint8_t val = bus->read(0x10);
            std::cout << "CPU read sensor value: " << (int)val << " at " << sc_time_stamp() << "\n";

            // Write to memory at 0x20
            bus->write(0x20, val);

            // Control actuator at 0x30
            bus->write(0x30, val > 50 ? 1 : 0);

            wait(10, SC_NS);
        }
    }
};

#endif
