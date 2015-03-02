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

#ifdef WIN32
#define OS(X) Win##X
namespace std
{
    typedef wstring tstring;
}

typedef wchar_t tchar;
#define T(x)    L##x

#elif defined(__linux__)
#define OS(X) Linux##X
namespace std
{
    typedef string  tstring;
}

typedef char    tchar;
#define T(x)    x

#else
#error NOT IMPLEMENTED!
#endif


void doX();
