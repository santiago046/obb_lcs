#include <filesystem>
#include <vector>
#include <unistd.h>
#include <limits.h>
#include <stdexcept>

#include "utils.h"

const std::filesystem::path& GetApplicationPath()
{
	static std::filesystem::path path;

	if (path.empty())
	{
		std::vector<char> name(PATH_MAX);
		ssize_t count = readlink("/proc/self/exe", name.data(), name.size());
		if (count == -1) {
			throw std::runtime_error("Failed to get application path");
		}
		name[count] = '\0'; // Null-terminate the string

		path = name.data();
		path.remove_filename();
	}

	return path;
}
