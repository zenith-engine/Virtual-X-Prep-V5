#pragma once
#include <Windows.h>
#include "../pointers/pointers.hpp"


namespace VX {

	class core {
	public:
		void initialize();
		void cleanup();
	public:
		HMODULE m_module{};
		HANDLE m_main_thread;
		bool m_steam;
		DWORD m_main_thread_id;
		std::vector<HMODULE> module_handles;
		bool inject = false;

	public:
		void get_loading_screen()
		{
			if (*get_pointers()->m_loading_screen_state != eLoadingScreenState::Finished)
			{
				while (*get_pointers()->m_loading_screen_state != eLoadingScreenState::Finished)
				{
					std::this_thread::sleep_for(1000ms);
				}
			}
		}
	};
	core* get_core();
};