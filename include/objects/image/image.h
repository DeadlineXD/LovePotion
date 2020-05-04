#pragma once

#include "common/mmath.h"
#include "objects/texture/texture.h"

#if defined (_3DS)
    typedef C2D_SpriteSheet TextureSheet;
#elif defined (__SWITCH__)
    typedef struct _SpriteSheet TextureSheet;
#endif

namespace love
{
    class Image : public Texture
    {
        public:
            static love::Type type;

            Image(const std::string & path);
            ~Image();

            void Draw(const DrawArgs & args, const Color & color);
            void Draw(const DrawArgs & args, Quad * quad, const Color & color);

        private:
            TextureType textureType;
            TextureHandle texture;
            TextureSheet sheet;
    };
}
