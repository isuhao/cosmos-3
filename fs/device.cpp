////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       21.08.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "device.h"

namespace Filesystem {

Device::Device()
    : File(DEVICE_FILE)
    , m_initialized(false)
{
}

void Device::init()
{
    m_initialized = true;
}

size_t Device::read(void*, size_t)
{
    return 0;
}

size_t Device::write(const void*, size_t)
{
    return 0;
}

bool Device::ioctl(uint32_t, void*)
{
    return true;
}

} // namespace Filesystem
