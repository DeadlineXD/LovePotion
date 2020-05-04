#pragma once

#include "socket/objects/socket/socket.h"

class UDP : public Socket
{
    public:
        UDP();

        int SetPeerName(const Socket::Address & host);

        int SetSockName(const Socket::Address & peer);

        int TryDisconnect();
};
