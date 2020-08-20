#ifndef __HELPER_H
#define __HELPER_H

#include <windows.h>
#include <iostream>

/*
 * Wrapper class to provide RAII implementation for HANDLER object.
 * Using Pavel Yosifovich example from "Windows 10 system programming", Part 1, Page 59.
 * Supply Destructor function whenever the object isn't required anymore.
*/
struct SafeHandle {
	explicit SafeHandle(HANDLE h = nullptr) : _h(h) {}

	~SafeHandle() {
		Close();
	}

	// delete copy-ctor and copy-assignment
	SafeHandle(const SafeHandle&) = delete;
	SafeHandle& operator=(const SafeHandle&) = delete;

	// allow move (transfer ownership)
	SafeHandle(SafeHandle&& other) : _h(other._h) {
		other._h = nullptr;
	}

	SafeHandle& operator=(SafeHandle&& other) {
		if (this != &other) {
			Close();
			_h = other._h;
			other._h = nullptr;
		}
		return *this;
	}

	operator bool() const {
		return _h != nullptr && _h != INVALID_HANDLE_VALUE;
	}

	HANDLE Get() const {
		return _h;
	}

	void Close() {
		if (_h) {
			::CloseHandle(_h);
			_h = nullptr;
		}
	}

private:
	HANDLE _h;
};

#pragma once
class Helper
{
public:
	static std::string GetLastErrorAsString();
	static bool IsDirectoryExist(const std::string& dirName) throw (int, const char*);
};

#endif // !__HELPER_H