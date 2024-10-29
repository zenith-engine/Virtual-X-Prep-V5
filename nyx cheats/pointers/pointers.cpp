#include "pointers.hpp"
#include "../hooking/hooking.hpp"
#include "../memory/all.hpp"

namespace VX {

	pointers g_pointers;

	void pointers::initialize() {

		get_batch()->add("ISS", "48 89 5C 24 18 48 89 74 24 20 55 57 41 56 48 8B EC 48 81 EC 80 00 00 00 48 8D", [this](memory::handle ptr) {
			this->m_news_story_request_handle_received_data = ptr.as<news_story_request_handle_received_data>();
			});

		get_batch()->add("ISS", "83 3D ? ? ? ? ? 75 17 8B 43 20 25", [this](memory::handle ptr) {
			this->m_loading_screen_state = ptr.add(2).rip().add(1).as<eLoadingScreenState*>();
			});

		m_window = FindWindowA("grcWindow", "Grand Theft Auto V");

		get_batch()->initialize(memory::module(nullptr));
	}

	void pointers::cleanup() {
		get_batch()->cleanup();
	}
	pointers* get_pointers() { return &g_pointers; }
}