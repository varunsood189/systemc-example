// actuator.h
#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "device_if.h"
#include <systemc>
#include <iostream>

struct actuator : public sc_module, public device_if {
    uint8_t state;

    SC_CTOR(actuator) : state(0) {}

    void write(uint32_t, uint8_t data) override {
        state = data;
        std::cout << "Actuator received command: " << (int)state << " at " << sc_time_stamp() << "\n";
    }

    uint8_t read(uint32_t) override { return state; }
};

#endif
