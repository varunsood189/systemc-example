// device_if.h
#ifndef DEVICE_IF_H
#define DEVICE_IF_H

#include <systemc.h>
using namespace sc_core;

class device_if : public sc_interface {
public:
    virtual void write(uint32_t addr, uint8_t data) = 0;
    virtual uint8_t read(uint32_t addr) = 0;
};

#endif
