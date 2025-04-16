#include "ApostatePCH.h"

#include "Singleton/EngineSingletons.h"

#include "Platform/CommandLineOptions/CommandLineOptions.h"

int main(int argc, char* argv[])
{
    apostate::ParseCommandLine(argv, argc);
    apostate::EngineSingletons::Construct();

    apostate::EngineSingletons::Destruct();
    return 0;
}