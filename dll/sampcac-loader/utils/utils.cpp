#include "utils.hpp"
#include "boost/algorithm/string.hpp"

auto Utils::convert_to_hex(uint64_t hex) -> std::string
{
	std::stringstream ss;
	ss << std::hex << hex;
	return boost::to_upper_copy<std::string>(std::string(ss.str()));
}