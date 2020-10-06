#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <memory>
#include <string>

class Injection
{
public:
	auto load_library(const std::string& str_dll_path) -> bool;
};

inline std::unique_ptr<Injection> injection = std::make_unique<Injection>();