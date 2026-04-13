cmake_minimum_required(VERSION 3.15)

project(minecraft_server_status VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_library(minecraft_server_status
    src/java.cpp
    src/bedrock.cpp
)

add_library(minecraft-server-status::minecraft_server_status ALIAS minecraft_server_status)

target_include_directories(minecraft_server_status
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(minecraft_server_status
    PUBLIC
        cpr::cpr
        nlohmann_json::nlohmann_json
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/minecraft_server_statusConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(TARGETS minecraft_server_status
    EXPORT minecraft_server_statusTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/
    DESTINATION include
)

install(EXPORT minecraft_server_statusTargets
    FILE minecraft_server_statusTargets.cmake
    NAMESPACE minecraft-server-status::
    DESTINATION share/minecraft-server-status
)

install(FILES
    cmake/minecraft_server_statusConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/minecraft_server_statusConfigVersion.cmake"
    DESTINATION share/minecraft-server-status
)