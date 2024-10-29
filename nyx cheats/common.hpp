#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define CURL_STATICLIB

#include <windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>
#include <minwindef.h>
#include <filesystem>
#include <mutex>
#include <functional>

#include <vector>

using namespace std::chrono_literals;

#define NAME "Virtual X"

inline bool g_running = true;

enum class eLoadingScreenState : std::int32_t
{
	Invalid = -1,
	Finished,
	PreLegal,
	Unknown_2,
	Legals,
	Unknown_4,
	LandingPage,
	Transition,
	Unknown_7,
	Unknown_8,
	Unknown_9,
	SessionStartLeave
};

inline void message(std::string content, std::string title, UINT uType) {
	MessageBoxA(NULL, content.c_str(), title.c_str(), uType);
}