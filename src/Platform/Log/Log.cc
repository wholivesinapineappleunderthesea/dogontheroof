#include "ApostatePCH.h"
#include "Log.h"

#include <print>

namespace apostate
{
    auto LogMessage(std::string_view message) -> void
    {
        std::print("{}\n", message);
    }
}