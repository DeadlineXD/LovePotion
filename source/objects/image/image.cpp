#include "common/runtime.h"

#include "objects/file/file.h"

#include "common/drawable.h"
#include "objects/image/image.h"
#include "modules/window.h"

#include "warn_png.h"
#include "plus_png.h"

#include "dog_png.h"
#include "head_png.h"
#include "dogshadow_png.h"
#include "shadow_png.h"
#include "tail_png.h"
#include "cloud_png.h"
#include "tongue_png.h"

Image::Image(const char * path, bool memory) : Drawable("Image")
{
    uint texture;
    u32 * buffer = nullptr;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if (!memory)
        buffer = this->LoadPNG(path, nullptr, -1);
    else
        LOG("[ERR] MEMORY IMAGES NOT DONE");//tempSurface = this->GetMemoryImage(path);

    if (buffer != nullptr)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
        glGenerateMipmap(GL_TEXTURE_2D);

        delete[] buffer;
    }
    this->textureHandle = texture;

    this->viewport = {0, 0, 1, 1, this->width, this->height};
}

uint Image::GetMemoryImage(const char * path)
{
    string name = path;
    name = name.substr(name.find(":") + 1);

    SDL_Surface * returnSurface = NULL;

    if (name == "dog")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)dog_png, dog_png_size), 1);
    else if (name == "head")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)head_png, head_png_size), 1);
    else if (name == "dogshadow")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)dogshadow_png, dogshadow_png_size), 1);
    else if (name == "shadow")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)shadow_png, shadow_png_size), 1);
    else if (name == "tail")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)tail_png, tail_png_size), 1);
    else if (name == "tongue")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)tongue_png, tongue_png_size), 1);
    else if (name == "cloud")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)cloud_png, cloud_png_size), 1);
    else if (name == "warn")
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)warn_png, warn_png_size), 1);
    else
        returnSurface = IMG_Load_RW(SDL_RWFromMem((void *)plus_png, plus_png_size), 1);

    return 0;
}