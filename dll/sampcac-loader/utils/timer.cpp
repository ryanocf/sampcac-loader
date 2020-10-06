#include "utils.hpp"
#include "console/console.hpp"

auto Utils::timer_start(const std::vector<std::string> details) -> void
{
    timer_begin = std::chrono::high_resolution_clock::now();
    console->log("[ryano.cf] Timer started\n");
	if (!details.empty()) {
		for (const auto &value : details)
		{
            console->log("[ryano.cf] %s\n", value.c_str());
		}
	}
}

auto Utils::timer_stop(const std::vector<std::string> details) -> void
{
	if (!details.empty()) {
		for (const auto &value : details)
		{
			console->log("[ryano.cf] %s\n", value.c_str());
		}
	}
	const double elapsed = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1>>>(std::chrono::high_resolution_clock::now() - timer_begin).count();
    console->log("\n[ryano.cf] Timer stopped: %f\n\n", elapsed);
}