#include <switch.h>
#include <deko3d.hpp>
#include <png.h>
#include <cstring>
#include <string>
#include "textures.h"

Tex connect_icon;
Tex disconnect_icon;
Tex search_icon;
Tex refresh_icon;

Tex folder_icon;
Tex file_icon;
Tex update_icon;

namespace Textures
{

	bool LoadImageFile(const std::string &path, Tex &texture)
	{
		bool ret = false;
		png_image image;
		std::memset(&image, 0, (sizeof image));
		image.version = PNG_IMAGE_VERSION;

		if (png_image_begin_read_from_file(&image, path.c_str()) != 0)
		{
			png_bytep buffer;
			image.format = PNG_FORMAT_RGBA;
			buffer = new png_byte[PNG_IMAGE_SIZE(image)];

			if (buffer != nullptr && png_image_finish_read(&image, nullptr, buffer, 0, nullptr) != 0)
			{
				texture.width = image.width;
				texture.height = image.height;
				delete[] buffer;
				png_image_free(&image);
			}
			else
			{
				if (buffer == nullptr)
					png_image_free(&image);
				else
					delete[] buffer;
			}
		}

		return ret;
	}

	void Init(void)
	{
		Textures::LoadImageFile("romfs:/icons/connect.png", connect_icon);
		Textures::LoadImageFile("romfs:/icons/disconnect.png", disconnect_icon);
		Textures::LoadImageFile("romfs:/icons/search.png", search_icon);
		Textures::LoadImageFile("romfs:/icons/refresh.png", refresh_icon);
		Textures::LoadImageFile("romfs:/icons/folder.png", folder_icon);
		Textures::LoadImageFile("romfs:/icons/file.png", file_icon);
		Textures::LoadImageFile("romfs:/icons/update.png", update_icon);
	}

	void Exit(void)
	{
		Free(connect_icon);
		Free(disconnect_icon);
		Free(search_icon);
		Free(folder_icon);
		Free(file_icon);
		Free(update_icon);
	}

	void Free(Tex &texture)
	{
	}

}
