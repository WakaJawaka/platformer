#ifndef __PLATFORM_H
#define __PLATFORM_H

#include <sstream>

#ifdef _WIN32

#include <Windows.h>

#define MAIN CALLBACK WinMain(_In_  HINSTANCE hInstance, _In_  HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  int nCmdShow)

#else

#define MAIN main(int argc, char** argv)

#endif

#define SAFE_DELETE(ptr) if(ptr) { delete ptr; ptr = 0; }

namespace pf
{
	template<class t> inline std::string toString(t value)
	{
		std::ostringstream ss;
		ss << value;

		return ss.str();
	}

	inline std::string intToString(int value)
	{
		return toString<int>(value);
	}

	inline std::string longToString(long value)
	{
		return toString<long>(value);
	}

	inline int strToInt(std::string str)
	{
		return ::atoi(str.c_str());
	}

	inline float strToFloat(std::string str)
	{
		return (float) ::atof(str.c_str());
	}
}

#endif