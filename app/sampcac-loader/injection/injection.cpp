#include "injection.hpp"
#include "../utils/process/process.hpp"

auto Injection::load_library(const std::string& str_dll_path) -> bool
{
	const auto proc_address = static_cast<LPVOID>(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"));
	if (!proc_address)
		return false;

	const auto write_address = VirtualAllocEx(process->m_process, nullptr, str_dll_path.length(), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	
	process->write(write_address, str_dll_path.c_str(), str_dll_path.length());
	CreateRemoteThread(process->m_process, nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(proc_address), static_cast<LPVOID>(write_address), NULL, nullptr);
	
	process->detach();

	return true;
}