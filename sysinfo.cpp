#include "sysinfo.h"

#include "sysinfowindowsimpl.h"

SysInfo& SysInfo::instance()
{
    static SysInfoWindowsImpl instance;
    return instance;
}
