#include "imgui_impl_deko3d.h"
#include <stdio.h>
#include <switch.h>
#include "windows.h"
#include "gui.h"
#include "textures.h"
#include "ftpclient.h"

bool done = false;
int gui_mode = GUI_MODE_BROWSER;

namespace GUI
{
	int RenderLoop(void)
	{
		Windows::Init();
		while (!done)
		{
			u64 up = ImGui_ImplDeko3d_UpdatePad();

			if (gui_mode == GUI_MODE_BROWSER)
			{
				ImGui_ImplDeko3d_NewFrame();
				ImGui::NewFrame();
				Windows::HandleWindowInput(up);
				Windows::MainWindow();
				Windows::ExecuteActions();
				ImGui::Render();
				ImGui_ImplDeko3d_RenderDrawData(ImGui::GetDrawData());
			}
			else if (gui_mode == GUI_MODE_IME)
			{
				Windows::HandleImeInput();
			}
		}

		return 0;
	}
}
