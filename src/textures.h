#ifndef LAUNCHER_TEXTURES_H
#define LAUNCHER_TEXTURES_H

#include <glad/glad.h>
#include <switch.h>

#define BYTES_PER_PIXEL 4

typedef struct
{
    GLuint id = 0;
    int width = 0;
    int height = 0;
} Tex;

extern Tex connect_icon;
extern Tex disconnect_icon;
extern Tex search_icon;
extern Tex refresh_icon;

extern Tex folder_icon;
extern Tex file_icon;
extern Tex update_icon;

namespace Textures
{
    bool LoadImageFile(const std::string &path, Tex &texture);
    void Init(void);
    void Exit(void);
    void Free(Tex &texture);
}

#endif
