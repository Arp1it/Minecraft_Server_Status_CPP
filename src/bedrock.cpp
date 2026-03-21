#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "minecraft_server_status/minecraft_server_status.hpp"

namespace minecraft_server_status {

    Server_Status bedrock(const std::string& server) {

        std::string url = "https://api.mcstatus.io/v2/status/bedrock/" + server;

        auto response = cpr::Get(cpr::Url{url});

        if (response.status_code != 200) {
            throw std::runtime_error("Failed to fetch Minecraft server status");
        }

        auto json = nlohmann::json::parse(response.text);

        Server_Status status{};

        status.online = json["online"];

        if (json.contains("players")) {
            status.players_online = json["players"]["online"];
            status.players_max = json["players"]["max"];
        }

        if (json.contains("version")) {
            status.version = json["version"]["name_clean"];
        }

        return status;
    }

}