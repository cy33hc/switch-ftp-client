#pragma once

#include "imgui.h"
#include <switch.h>

enum DeckoFontType {
    DECKO_FONT_TYPE_LATIN = 1,
    DECKO_FONT_TYPE_JAPANESE = 2,
    DECKO_FONT_TYPE_TRADITIONAL_CHINESE = 4,
    DECKO_FONT_TYPE_SIMPLIFIED_CHINESE = 8,
    DECKO_FONT_TYPE_KOREAN = 16
};

IMGUI_IMPL_API void ImGui_ImplDeko3d_Init(DeckoFontType fontType);
IMGUI_IMPL_API void ImGui_ImplDeko3d_Shutdown();
IMGUI_IMPL_API void ImGui_ImplDeko3d_NewFrame();
IMGUI_IMPL_API void ImGui_ImplDeko3d_RenderDrawData(ImDrawData *drawData);

IMGUI_IMPL_API uint64_t ImGui_ImplDeko3d_UpdatePad();

IMGUI_IMPL_API void ImGui_ImplDeko3d_DisableButtons(u64 buttons);
