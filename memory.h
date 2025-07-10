// memory.h
#ifndef MEMORY_H
#define MEMORY_H

#include "device_if.h"
#include <systemc>

struct memory : public sc_module, public device_if {
    uint8_t mem[16];

    SC_CTOR(memory) {
        for (int i = 0; i < 16; ++i) mem[i] = 0;
    }

    void write(uint32_t addr, uint8_t data) override {
        if (addr < 16) mem[addr] = data;
    }

    uint8_t read(uint32_t addr) override {
        if (addr < 16) return mem[addr];
        return 0xFF;
    }
};

#endif
