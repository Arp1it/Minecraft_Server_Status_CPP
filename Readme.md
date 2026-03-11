# Minecraft Server Status C++ Library

A lightweight **C++17 library** for retrieving **Minecraft Java and Bedrock server status** using the public API from **mcstatus.io**.

The library provides a simple interface to check whether a server is online and retrieve useful information such as player count and server version.

The project is designed as a **modern CMake package** and integrates easily with existing C++ projects.

---

## Features

* Check **Minecraft Java Edition server status**
* Check **Minecraft Bedrock Edition server status**
* Simple structured API
* Modern **C++17** implementation
* Easy **CMake integration**
* Designed to be packaged for **vcpkg**

---

## Dependencies

This library requires the following dependencies:

* **CPR** — HTTP client library
* **nlohmann-json** — JSON parsing library

Both dependencies can be installed using **vcpkg**.

---

## Installing Dependencies (vcpkg)

If you do not already have **vcpkg**, install it first.

### Clone vcpkg

```bash
git clone https://github.com/microsoft/vcpkg
cd vcpkg
```

### Bootstrap vcpkg

Windows

```bash
bootstrap-vcpkg.bat
```

Linux / macOS

```bash
./bootstrap-vcpkg.sh
```

### Install required libraries

```bash
vcpkg install cpr
vcpkg install nlohmann-json
```

---

## Building the Library

Clone the repository:

```bash
git clone https://github.com/Arp1it/Minecraft_Server_Status_CPP.git
cd Minecraft_Server_Status_CPP
```

Configure the project with CMake:

```bash
cmake -B build -S . \
-DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
```

Build the project:

```bash
cmake --build build
```

Install the package:

```bash
cmake --install build
```

After installation, the library can be discovered automatically by **CMake**.

---

## Using the Library

### CMake Integration

Add the package to your `CMakeLists.txt`:

```cmake
find_package(minecraft_api REQUIRED)

target_link_libraries(my_app
    PRIVATE minecraft_api::minecraft_api
)
```

---

## Example

```cpp
#include <iostream>
#include "minecraft_server_status/minecraft_server_status.hpp"

int main() {

    auto status = minecraft_server_status::java("hypixel.net");

    std::cout << "Online: " << status.online << std::endl;
    std::cout << "Players: "
              << status.players_online
              << "/"
              << status.players_max
              << std::endl;
    std::cout << "Version: "
              << status.version
              << std::endl;
}
```

---

## Bedrock Server Example

```cpp
auto status = minecraft_server_status::bedrock("play.example.com");
```

---

## Returned Structure

```cpp
struct Server_Status {
    bool online;
    int players_online;
    int players_max;
    std::string version;
};
```

---

## Error Handling

If the API request fails, the library throws:

```
std::runtime_error
```

Example message:

```
Failed to fetch Minecraft server status
```

---

## Packaging

This project is structured as a **CMake package**, allowing it to be discovered using:

```
find_package(minecraft_api REQUIRED)
```

The exported target is:

```
minecraft_api::minecraft_api
```

This makes the library easy to integrate into modern **CMake-based C++ projects** and simplifies packaging for **vcpkg**.

---

## Project Structure

```
Minecraft_Server_Status_CPP
│
├── include/
│   └── minecraft_server_status/
│       └── minecraft_server_status.hpp
│
├── src/
│   ├── java.cpp
│   └── bedrock.cpp
│
├── cmake/
│   └── minecraft_apiConfig.cmake
│
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

## API Source

This library uses the public Minecraft server status API provided by:

https://api.mcstatus.io