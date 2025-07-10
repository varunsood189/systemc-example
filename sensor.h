// sensor.h
#ifndef SENSOR_H
#define SENSOR_H

#include "device_if.h"
#include <systemc>

struct sensor : public sc_module, public device_if {
    uint8_t data;

    SC_CTOR(sensor) : data(0) {
        SC_THREAD(generate);
    }

    void generate() {
        while (true) {
            data = rand() % 100;
            wait(5, SC_NS);
        }
    }

    void write(uint32_t, uint8_t) override {} // Not writable
    uint8_t read(uint32_t) override { return data; }
};

#endif
