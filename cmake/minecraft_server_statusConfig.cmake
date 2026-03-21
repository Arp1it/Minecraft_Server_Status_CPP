include(CMakeFindDependencyMacro)

find_dependency(cpr)
find_dependency(nlohmann_json)

include("${CMAKE_CURRENT_LIST_DIR}/minecraft_server_statusTargets.cmake")