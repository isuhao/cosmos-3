////////////////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author     Kuba Sejdak
/// @date       20.07.2016
///
/// @copyright  This file is a part of cosmos OS. All rights reserved.
///
////////////////////////////////////////////////////////////////////////////////////////////////

#include "regions.h"

#include <os/assert.h>

extern int _memoryRegions_pa;

namespace Memory {

MemoryRegions::MemoryRegions()
    : regions(nullptr)
    , m_count(0)
{
    regions = (struct MemoryRegionEntry *) &_memoryRegions_pa;

    for (struct MemoryRegionEntry *it = regions; it->totalSize != 0; ++it)
        ++m_count;
}

int MemoryRegions::count()
{
    return m_count;
}

uint32_t MemoryRegions::physicalAddress(int index)
{
    assert(index < m_count);
    return regions[index].physicalAddress;
}

uint32_t MemoryRegions::totalSize(int index)
{
    assert(index < m_count);
    return regions[index].totalSize;
}

uint32_t MemoryRegions::usedSize(int index)
{
    assert(index < m_count);
    return regions[index].usedSize;
}

} // namespace Memory
