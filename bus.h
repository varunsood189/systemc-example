// bus.h
#ifndef BUS_H
#define BUS_H

#include "device_if.h"
#include <map>
#include <systemc>

struct bus : public sc_module, public device_if {
    std::map<uint32_t, device_if*> slaves;

    SC_CTOR(bus) {}

    void map_device(uint32_t base_addr, device_if* dev) {
        slaves[base_addr] = dev;
    }

    void write(uint32_t addr, uint8_t data) override {
        for (auto& [base, dev] : slaves) {
            if (addr >= base && addr < base + 0x10) {
                dev->write(addr - base, data);
                return;
            }
        }
    }

    uint8_t read(uint32_t addr) override {
        for (auto& [base, dev] : slaves) {
            if (addr >= base && addr < base + 0x10) {
                return dev->read(addr - base);
            }
        }
        return 0xFF;
    }
};

#endif
