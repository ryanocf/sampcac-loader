#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#include <iostream>
#include <cstdint>
#include <thread>
#include <chrono>
#include <istream>

#include "inject/inject.hpp"
#include "utils/console/console.hpp"
#include "utils/process/process.hpp"

unsigned long WINAPI initialize(void* instance) {

	console->initialize("loader console");

	try {
		Inject::initialize();
	}
	catch (const std::runtime_error& error) {
		MessageBoxA(nullptr, error.what(), "error!", MB_OK | MB_ICONERROR);
		FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
	}

	while (process->samp == NULL)
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
}

unsigned long WINAPI release() {
	Inject::release();
	console->release();

	return true;
}

std::int32_t WINAPI DllMain(const HMODULE instance, const unsigned long reason, const void* reserved) {
	DisableThreadLibraryCalls(instance);

	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		if (const auto handle = CreateThread(nullptr, NULL, initialize, instance, NULL, nullptr))
			CloseHandle(handle);

		break;

	case DLL_PROCESS_DETACH:
		release();
		break;

	default:;
	}

	return true;
}