////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       27.12.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "gpio.h"

namespace Device {

IGPIOPort::IGPIOPort(int portNo)
    : m_portNo(portNo)
{
}

GPIOPin::GPIOPin(int id)
    : GPIOPin(pinmux[id].portNo, pinmux[id].pinNo)
{
}

GPIOPin::GPIOPin(int portNo, int pinNo)
    : m_port(IGPIOManager::instance()->getPort(portNo))
    , m_pinNo(pinNo)
    , m_id(-1)
{
    for (int i = 0; i < pinmuxSize; ++i) {
        if (pinmux[i].portNo == portNo && pinmux[i].pinNo == pinNo) {
            m_id = i;
            break;
        }
    }

    m_port.init();
}

bool GPIOPin::setFunction(int function)
{
    return m_port.setFunction(m_id, function);
}

void GPIOPin::setDirection(GPIODirection_t direction)
{
    m_port.setDirection(m_pinNo, direction);
}

void GPIOPin::setResistor(GPIOResitor_t resistor)
{
    m_port.setResistor(m_id, resistor);
}

bool GPIOPin::read()
{
    return (m_port.read() & PIN_MASK(m_pinNo));
}

bool GPIOPin::write(bool state)
{
    return m_port.writePin(m_pinNo, state);
}

void GPIOPin::toggle()
{
    volatile bool state = read();
    write(!state);
}

} // namespace Device
