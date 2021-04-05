#pragma once

#include <vector>

#include "Disk.hpp"
#include "IOSystem.hpp"

namespace FS {

class Descriptors
{
public:
    Descriptors(IOSystem& iosystem);
    ~Descriptors();
    const Entity::FileDescriptor& get(std::size_t index);
    void set(size_t index, const Entity::FileDescriptor& value);
    void reset();
    inline size_t size() const { return Disk::bitmap_size_bits; }

private:
    std::vector<Entity::FileDescriptor> data;
    IOSystem& iosystem;
    bool first_use;
    void loadDescriptors();
    void unloadDescriptors();
};

} // namespace FS