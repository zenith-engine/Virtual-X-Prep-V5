#include "core.hpp"
#include "../pointers/pointers.hpp"
#include "../hooking/hooking.hpp"
#include "../common.hpp"
#include <memory>
#include <Psapi.h>

namespace VX {

	core g_core;

	void core::initialize() {
		get_core()->m_steam = (uint64_t)GetModuleHandleA("steam_api64.dll") > 0;
		get_pointers()->initialize();
		get_hooking()->initialize();

		SetWindowTextA(get_pointers()->m_window, NAME);
	}

	void core::cleanup() {
		std::this_thread::sleep_for(500ms);
		get_pointers()->cleanup();
		get_hooking()->cleanup();
		SetWindowTextA(get_pointers()->m_window, "Grand Theft Auto V");
	}

	core* get_core() { return &g_core; };
}
