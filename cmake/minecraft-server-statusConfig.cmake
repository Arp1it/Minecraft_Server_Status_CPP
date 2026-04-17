include(CMakeFindDependencyMacro)

find_dependency(cpr CONFIG REQUIRED)
find_dependency(nlohmann_json CONFIG REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/minecraft_server_statusTargets.cmake")