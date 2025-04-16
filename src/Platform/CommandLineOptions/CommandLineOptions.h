#pragma once

namespace apostate
{
    inline aposBool g_cmdlineHeadless = false;

    auto ParseCommandLine(char* argv[], int count) -> void;
}