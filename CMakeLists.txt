cmake_minimum_required(VERSION 3.16.3)
# or use: /opt/devkitpro/portlibs/switch/bin/aarch64-none-elf-cmake
include(/opt/devkitpro/cmake/Switch.cmake)
project(switch-ftp-client VERSION 1.0.3 LANGUAGES C CXX)
set(TITLE_NAME "Switch FTP Client")
set(PROJECT_AUTHOR "cy33hc")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

set(TARGET ${PROJECT_NAME})
set(IMGUI_DIR third_parties/imgui)

add_executable(${TARGET}
  src/main.cpp
  src/inifile.c
  src/lang.cpp
  src/fs.cpp
  src/ftpclient.cpp
  src/textures.cpp
  src/actions.cpp
  src/gui.cpp
  src/windows.cpp
  src/config.cpp
  src/ime_dialog.cpp
  src/imgui_impl_deko3d.cpp
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  )
  
target_compile_features(${TARGET} PUBLIC cxx_std_17)
target_compile_definitions(${TARGET} PUBLIC
  IMGUI_DISABLE_OBSOLETE_KEYIO
  IMGUI_DISABLE_OBSOLETE_FUNCTIONS
  IMGUI_IMPL_OPENGL_LOADER_GLAD
  )

target_link_libraries(${TARGET} PUBLIC
  deko3dd
  deko3d
  png
  m
  z
  glad
)

target_include_directories(${TARGET} PUBLIC
  ${DEVKITPRO}/portlibs/switch/include
  ${IMGUI_DIR})

file(COPY icons DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs)
file(COPY lang DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs)
nx_add_shader_program(imgui_vsh src/imgui_vsh.glsl vert)
nx_add_shader_program(imgui_fsh src/imgui_fsh.glsl frag)
dkp_add_asset_target(${TARGET}_romfs ${CMAKE_CURRENT_BINARY_DIR}/romfs)
dkp_install_assets(${TARGET}_romfs
  DESTINATION shaders
  TARGETS imgui_vsh imgui_fsh)

nx_generate_nacp(${TARGET}.nacp
  NAME ${TITLE_NAME}
  AUTHOR ${PROJECT_AUTHOR}
  )
nx_create_nro(${TARGET}
  NACP ${TARGET}.nacp
  ROMFS ${TARGET}_romfs
  ICON ${CMAKE_SOURCE_DIR}/icon.jpg
  )
