#pragma once

#include <memory>

class Console
{
public:
	auto initialize(const char* title) -> void;
	auto release() -> void;

	template <typename ... Args>
	auto log(char const* const format, Args const& ... args) -> void
	{
		printf(format, args ...);
	}
};

inline std::unique_ptr<Console> console = std::make_unique<Console>();