/*
*  Copyright 2015 Samuel Ghineț
*  
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*  
*      http://www.apache.org/licenses/LICENSE-2.0
*  
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

#pragma once

#include <string>
#include "XLib.h"

namespace Zen
{
	class Dir
	{
	public:
		Dir() = default;
		Dir(Dir&& other);
        explicit Dir(const std::tstring& path) : m_path(path) {}

		Dir& operator=(Dir&& other);

		bool Exists() const;
		bool Create();
		bool Remove();
        std::tstring FullPath() const;

	public:
        static Dir Create(const std::tstring& path);
        static bool Remove(const std::tstring& path);
        static bool Exists(const std::tstring& path);
		static Dir GetCurrent();

	private:
        std::tstring m_path;
	};
}
