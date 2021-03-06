#pragma once

#include "modules/audio/audio.h"
#include "objects/source/wrap_source.h"
#include "objects/sounddata/sounddata.h"
#include "objects/filedata/filedata.h"
#include "objects/file/file.h"

namespace Wrap_Audio
{
    int _UpdateAudio();

    int GetVolume(lua_State * L);

    int NewSource(lua_State * L);

    int Pause(lua_State * L);

    int Play(lua_State * L);

    int SetVolume(lua_State * L);

    int Stop(lua_State * L);

    int Register(lua_State * L);
}
