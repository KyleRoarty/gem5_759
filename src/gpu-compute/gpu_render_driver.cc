#include "gpu-compute/gpu_render_driver.hh"

#include "params/GPURenderDriver.hh"
#include "sim/fd_entry.hh"

GPURenderDriver::GPURenderDriver(const GPURenderDriverParams &p)
    : EmulatedDriver(p)
{
}

int GPURenderDriver::open(ThreadContext *tc, int mode, int flags)
{
    auto process = tc->getProcessPtr();
    auto device_fd_entry = std::make_shared<DeviceFDEntry>(this, filename);
    int tgt_fd = process->fds->allocFD(device_fd_entry);
    return tgt_fd;
}

