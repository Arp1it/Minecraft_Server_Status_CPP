cmake_minimum_required(VERSION 3.15)

project(minecraft_api VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_library(minecraft_api
src/java.cpp
src/bedrock.cpp
)

add_library(minecraft_api::minecraft_api ALIAS minecraft_api)

target_include_directories(minecraft_api
PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

target_link_libraries(minecraft_api
PUBLIC
cpr::cpr
nlohmann_json::nlohmann_json
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
"${CMAKE_CURRENT_BINARY_DIR}/minecraft_apiConfigVersion.cmake"
VERSION ${PROJECT_VERSION}
COMPATIBILITY SameMajorVersion
)

include(GNUInstallDirs)

install(TARGETS minecraft_api
        EXPORT minecraft_api_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                CONFIGURATIONS Release RelWithDebInfo MinSizeRel
        ARCHIVE DESTINATION debug/${CMAKE_INSTALL_LIBDIR}
                CONFIGURATIONS Debug
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                CONFIGURATIONS Release RelWithDebInfo MinSizeRel
        LIBRARY DESTINATION debug/${CMAKE_INSTALL_LIBDIR}
                CONFIGURATIONS Debug
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
DESTINATION include
)

install(EXPORT minecraft_api_Targets
FILE minecraft_api_Targets.cmake
NAMESPACE minecraft_api::
DESTINATION lib/cmake/minecraft_api
)

install(FILES
cmake/minecraft_apiConfig.cmake
"${CMAKE_CURRENT_BINARY_DIR}/minecraft_apiConfigVersion.cmake"
DESTINATION lib/cmake/minecraft_api
)