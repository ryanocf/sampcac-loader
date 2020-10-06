#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <filesystem>
#include <tlhelp32.h>
#include <WtsApi32.h>
#pragma comment(lib, "Wtsapi32.lib")

#include "utils/process/process.hpp"

int main()
{
    std::cout << "[ryano.cf] Looking for lpClassName \"Grand theft auto San Andreas\"..." << std::endl;

    while (!process->window)
    {
        process->window = FindWindowA("Grand theft auto San Andreas", nullptr);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "[ryano.cf] lpClassName found! -> HWND: " << process->window << std::endl;

    std::cout << "[ryano.cf] Getting ProcessID..." << std::endl;

	while (!process->m_process_id)
	{
        GetWindowThreadProcessId(process->window, &process->m_process_id);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	if (!process->m_process_id) {
        std::cout << "[ryano.cf] Getting ProcessID failed! -> Error: ProcessID -> " << process->m_process_id << std::endl;
        std::cin.get();
        ExitProcess(0);
	}
	
    std::cout << "[ryano.cf] ProcessID found! -> ID: " << process->m_process_id << std::endl;

    std::cout << "[ryano.cf] Trying to attach to process..." << std::endl;

	if (process->attach()) {
        std::cout << "[ryano.cf] Attach success! -> HANDLE: " << process->m_process << std::endl;
	} else {
        std::cout << "[ryano.cf] Attach failed! -> Error: " << GetLastError() << std::endl;
        std::cin.get();
        ExitProcess(0);
    }
	
    std::cout << "[ryano.cf] Trying to GetProcAddress..." << std::endl;
	
    const auto proc_address = static_cast<LPVOID>(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"));
    if (!proc_address) {
        std::cout << "[ryano.cf] GetProcAddress failed! -> Error: " << GetLastError() << std::endl;
        std::cin.get();
        ExitProcess(0);
    }

    std::cout << "[ryano.cf] GetProcAddress success!" << std::endl;

    auto dll_path = std::filesystem::current_path();
    auto str_dll_path = dll_path.string() + std::string("\\dll\\sampcac-loader.dll");

    std::cout << "[ryano.cf] Trying to load sampcac-loader.dll into process..." << std::endl;
	
    const auto write_address = VirtualAllocEx(process->m_process, nullptr, str_dll_path.length(), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    if (process->write(write_address, str_dll_path.c_str(), str_dll_path.length())) {
        std::cout << "[ryano.cf] sampcac-loader.dll loaded!" << std::endl;
    } else {
        std::cout << "[ryano.cf] sampcac-loader.dll load failed! Error: " << GetLastError() << std::endl;
        std::cin.get();
        ExitProcess(0);
    }
    CreateRemoteThread(process->m_process, nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(proc_address), static_cast<LPVOID>(write_address), NULL, nullptr);

    process->detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}