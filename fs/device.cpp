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

bool Device::ioctl(uint32_t, void*)
{
    return true;
}

} // namespace Filesystem
