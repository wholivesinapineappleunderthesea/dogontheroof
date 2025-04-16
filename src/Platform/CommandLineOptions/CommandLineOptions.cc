#include "ApostatePCH.h"
#include "CommandLineOptions.h"
#include "Platform/Log/Log.h"

namespace apostate
{
    auto ParseCommandLine(char* argv[], int count) -> void
    {
        for (int i = 0; i < count; ++i)
        {
            std::string_view arg = argv[i];
            if (arg == "--headless" || arg == "-headless" || arg == "headless" || arg == "/headless")
            {
                g_cmdlineHeadless = true;
                LogMessage(std::format("Headless mode enabled: {}", arg));
            }
        }
    }
};