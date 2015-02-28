#pragma once

#include <string>

#if !WIN32
#error This file must be included only on Windows!
#endif

namespace Zen
{
	class WinDir
	{
	public:
		// Creates a Directory with the path. If a directory with the same name already exists, the function returns false.
		// If there is an error, an exception is thrown. If the directory is created, it returns true.
		static bool Create(const std::wstring& path);
		static void Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);
	};
}