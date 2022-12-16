#include <cstdlib>

#include <imgui.h>
#include <switch.h>

#include "imgui_impl_deko3d.h"
#include "util.h"
#include "config.h"
#include "lang.h"
#include "textures.h"
#include "gui.h"

static SetLanguage lang;

extern "C" void userAppInit() {
  plInitialize(PlServiceType_User);
  romfsInit();
  socketInitializeDefault();
  setInitialize();
  u64 lang_code = -1;
  setGetSystemLanguage(&lang_code);
  setMakeLanguage(lang_code, &lang);
  setExit();
}

extern "C" void userAppExit() {
  socketExit();
  plExit();
  romfsExit();
}

namespace Services
{
  int InitImGui(void)
  {
    IMGUI_CHECKVERSION();
    // Setup ImGui binding
    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    io.MouseDrawCursor = false;
    ImGui::StyleColorsDark();
    auto &style = ImGui::GetStyle();
    ImGui::GetIO().Fonts->Clear();

    style.AntiAliasedLinesUseTex = false;
    style.AntiAliasedLines = true;
    style.AntiAliasedFill = true;
    style.WindowRounding = 0.0f;
    style.FrameRounding = 2.0f;
    style.GrabRounding = 2.0f;

    ImVec4 *colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.39f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.18f, 0.22f, 0.25f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.09f, 0.21f, 0.31f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_Separator] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.00f, 0.50f, 0.50f, 1.0f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

    DeckoFontType fontType = DECKO_FONT_TYPE_LATIN;
    if (strcasecmp(language, "Simplified Chinese") == 0)
    {
      fontType = DECKO_FONT_TYPE_SIMPLIFIED_CHINESE;
    } 
    else if (strcasecmp(language, "Traditional Chinese") == 0)
    {
      fontType = DECKO_FONT_TYPE_TRADITIONAL_CHINESE;
    }
    else if (strcasecmp(language, "Korean") == 0)
    {
      fontType = DECKO_FONT_TYPE_KOREAN;
    }
    else if (strcasecmp(language, "Japanese") == 0 || strcasecmp(language, "Ryukyuan") == 0)
    {
      fontType = DECKO_FONT_TYPE_JAPANESE;
    }
    ImGui_ImplDeko3d_Init(fontType);

    ImGui_ImplDeko3d_DisableButtons(HidNpadButton_Y);

    return 0;
  }

  void ExitImGui(void)
  {
    // Cleanup
    ImGui_ImplDeko3d_Shutdown();
    ImGui::DestroyContext();
  }

  int Init(void)
  {
    CONFIG::LoadConfig();
    Lang::SetTranslation(lang);

    return 0;
  }

  void Exit(void)
  {
  }
} // namespace Services

int main(int argc, char *argv[])
{
  Services::Init();
  Services::InitImGui();

  GUI::RenderLoop();

  Services::ExitImGui();
  Services::Exit();
  return 0;
}
