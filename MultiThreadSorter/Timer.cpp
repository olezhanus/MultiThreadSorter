// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Timer.h"

void Timer::start()
{
	_begin = std::chrono::steady_clock::now();
}

void Timer::stop()
{
	_end = std::chrono::steady_clock::now();
	_duration = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _begin);
}

auto Timer::duration() -> std::chrono::milliseconds
{
	return _duration;
}
