#ifndef __GPU_COMPUTE_GPU_RENDER_DRIVER_HH__
#define __GPU_COMPUTE_GPU_RENDER_DRIVER_HH__

#include "cpu/thread_context.hh"
#include "sim/emul_driver.hh"
#include "sim/process.hh"

struct GPURenderDriverParams;

class GPURenderDriver final : public EmulatedDriver
{
  public:
    GPURenderDriver(const GPURenderDriverParams &p);

    int open(ThreadContext *tc, int mode, int flags) override;

    int ioctl(ThreadContext *tc, unsigned req, Addr buf)
             { return -EBADF; }
};

#endif
