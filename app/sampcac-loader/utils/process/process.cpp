#include "process.hpp"

auto Process::attach() -> bool
{
	m_process = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, m_process_id);
	if (!m_process)
		return false;
	
	return true;
}

auto Process::detach() -> void
{
	if (m_process)
		CloseHandle(m_process);

	m_process = nullptr;
	m_process_id = NULL;
}

auto Process::write(const LPVOID& dw_address, const LPCVOID& lpc_buffer, const DWORD_PTR& dw_size) -> bool
{
	return (WriteProcessMemory(m_process, dw_address, lpc_buffer, dw_size, nullptr) == TRUE);
}