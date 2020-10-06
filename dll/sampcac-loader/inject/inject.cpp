#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>

#include "inject.hpp"

#include "../utils/process/process.hpp"
#include "../utils/utils.hpp"

#include "../utils/console/console.hpp"

#include <BlackBone/Process/Process.h>

namespace Inject
{	
    auto initialize() -> void
    {
        console->log("[ryano.cf] Looking for lpClassName: \"Grand theft auto San Andreas\"\n");
    	while(!process->window)
    	{
            process->window = FindWindowA("Grand theft auto San Andreas", nullptr);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
    	}
        console->log("[ryano.cf] lpClassName found!\n");

        process->process.Attach(GetCurrentProcessId(), PROCESS_ALL_ACCESS);
        while (process->process.modules().GetModule(L"samp.dll", blackbone::eModSeachType::PEHeaders) == nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        process->samp = static_cast<uintptr_t>(process->process.modules().GetModule(L"samp.dll", blackbone::eModSeachType::PEHeaders)->baseAddress);
        console->log("[ryano.cf] samp.dll base_address = %s\n", std::string(utils->convert_to_hex(process->samp)).c_str());

        std::ofstream file;
        file.open("samp.dat", std::ios::out | std::ios::trunc);
        file << std::hex << process->samp << std::endl;
        file.close();

        console->log("[ryano.cf] closing in 3 seconds. glhf!\n");
    }

	auto release() -> void
    {
        
    }
}