#pragma once

#if defined(_WIN32) && defined(_WIN64) && defined(_MSC_VER)
#include "Platform/NT/PCH.h"
#elif defined(__APPLE__)
#include "TargetConditionals.h"
#ifndef TARGET_OS_OSX
#error "Unsupported Apple platform. Please define the precompiled header for your platform."
#endif
#include "Platform/Darwin/PCH.h"
#else
#error "Unsupported platform. Please define the precompiled header for your platform."
#endif

#include "Platform/InternalPCHBase.h"