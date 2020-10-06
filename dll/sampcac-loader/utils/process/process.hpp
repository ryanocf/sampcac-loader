#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memory>
#include <BlackBone/Process/Process.h>
#pragma comment(lib, "BlackBone.lib")

class Process
{	
public:
	blackbone::Process process;
	HWND window = nullptr;
	uintptr_t samp = NULL;
};

inline std::unique_ptr<Process> process = std::make_unique<Process>();