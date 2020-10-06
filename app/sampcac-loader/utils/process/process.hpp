#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <memory>
#include <string>
#pragma once

class Process
{
public:
	auto attach() -> bool;
	auto detach() -> void;
	auto write(const LPVOID& dw_address, const LPCVOID& lpc_buffer, const DWORD_PTR& dw_size) -> bool;

	template<typename T>
	auto write(const DWORD_PTR& dw_address, const T& t_value) -> bool
	{
		return write(dw_address, &t_value, sizeof(T));
	}

public:
	HWND window = nullptr;
	HANDLE m_process = nullptr;
	DWORD m_process_id = NULL;
};

inline std::unique_ptr<Process> process = std::make_unique<Process>();