#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <memory>
#include <sstream>

#include <chrono>
#include <vector>

class Utils
{
public:
    auto timer_start(std::vector<std::string> details = {}) -> void;
    auto timer_stop(std::vector<std::string> details = {}) -> void;
	
	auto convert_to_hex(uint64_t hex) -> std::string;

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> timer_begin;
};

inline std::unique_ptr<Utils> utils = std::make_unique<Utils>();