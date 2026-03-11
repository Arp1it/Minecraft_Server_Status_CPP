#pragma once

#include <string>

namespace minecraft_server_status {

    struct Server_Status {
        bool online;
        int players_online;
        int players_max;
        std::string version;
    };

    Server_Status java(const std::string& server);

    Server_Status bedrock(const std::string& server);

}