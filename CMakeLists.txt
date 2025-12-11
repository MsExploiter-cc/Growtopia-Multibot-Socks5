cmake_minimum_required(VERSION 3.10)
project(GrowtopiBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add definition for console mode
add_compile_definitions(_CONSOLE=1)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/New-Project)
include_directories(${CMAKE_SOURCE_DIR}/New-Project/src)
include_directories(${CMAKE_SOURCE_DIR}/New-Project/vendor)
include_directories(${CMAKE_SOURCE_DIR}/New-Project/vendor/imgui)
include_directories(${CMAKE_SOURCE_DIR}/New-Project/vendor/lua)
include_directories(${CMAKE_SOURCE_DIR}/New-Project/vendor/enet/include)

# Find required packages
find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

# Source files - Core (without GUI/DirectX dependent files for now)
set(CORE_SOURCES
    New-Project/src/ENetClient.cpp
    New-Project/src/Lua_Functions.cpp
    New-Project/src/ItemInfoManager.cpp
    New-Project/src/Bot_Local.cpp
    New-Project/src/Utils.cpp
    New-Project/src/wrapper/TextEditor.cpp
    New-Project/src/misc/Functions.cpp
    New-Project/src/misc/Logger.cpp
)

# ENet library sources
set(ENET_SOURCES
    New-Project/vendor/enet/callbacks.c
    New-Project/vendor/enet/compress.c
    New-Project/vendor/enet/host.c
    New-Project/vendor/enet/list.c
    New-Project/vendor/enet/packet.c
    New-Project/vendor/enet/peer.c
    New-Project/vendor/enet/protocol.c
    New-Project/vendor/enet/unix.c
)

# ImGui sources (minimal - only core)
set(IMGUI_SOURCES
    New-Project/vendor/imgui/imgui.cpp
    New-Project/vendor/imgui/imgui_draw.cpp
    New-Project/vendor/imgui/imgui_tables.cpp
    New-Project/vendor/imgui/imgui_widgets.cpp
)

# Lua sources
set(LUA_SOURCES
    New-Project/vendor/lua/lapi.c
    New-Project/vendor/lua/lauxlib.c
    New-Project/vendor/lua/lbaselib.c
    New-Project/vendor/lua/lcode.c
    New-Project/vendor/lua/lcorolib.c
    New-Project/vendor/lua/lctype.c
    New-Project/vendor/lua/ldblib.c
    New-Project/vendor/lua/ldebug.c
    New-Project/vendor/lua/ldo.c
    New-Project/vendor/lua/ldump.c
    New-Project/vendor/lua/lfunc.c
    New-Project/vendor/lua/lgc.c
    New-Project/vendor/lua/linit.c
    New-Project/vendor/lua/liolib.c
    New-Project/vendor/lua/llex.c
    New-Project/vendor/lua/lmathlib.c
    New-Project/vendor/lua/lmem.c
    New-Project/vendor/lua/loadlib.c
    New-Project/vendor/lua/lobject.c
    New-Project/vendor/lua/lopcodes.c
    New-Project/vendor/lua/loslib.c
    New-Project/vendor/lua/lparser.c
    New-Project/vendor/lua/lstate.c
    New-Project/vendor/lua/lstring.c
    New-Project/vendor/lua/lstrlib.c
    New-Project/vendor/lua/ltable.c
    New-Project/vendor/lua/ltablib.c
    New-Project/vendor/lua/ltm.c
    New-Project/vendor/lua/lundump.c
    New-Project/vendor/lua/lutf8lib.c
    New-Project/vendor/lua/lvm.c
    New-Project/vendor/lua/lzio.c
)

# Create simple console main
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/main_console.cpp"
"#include <iostream>
#include <thread>
#include <chrono>
extern \"C\" {
    int enet_initialize(void);
    void enet_deinitialize(void);
}
int main() {
    std::cout << \"Growtopia Bot - Linux Console Version\" << std::endl;
    int eStatus = enet_initialize();
    std::cout << \"ENet initialize status: \" << eStatus << std::endl;
    if (eStatus == 0) {
        std::cout << \"ENet initialized successfully!\" << std::endl;
        std::cout << \"Bot is running in console mode...\" << std::endl;
        std::cout << \"(This is a minimal test build without GUI)\" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        enet_deinitialize();
    }
    return 0;
}
")

# Create executable
add_executable(GrowtopiBot
    ${CORE_SOURCES}
    ${ENET_SOURCES}
    ${IMGUI_SOURCES}
    ${LUA_SOURCES}
    "${CMAKE_CURRENT_BINARY_DIR}/main_console.cpp"
)

# Compiler flags
target_compile_options(GrowtopiBot PRIVATE
    -Wall
    -Wextra
    -O2
    -fPIC
)

# Add defines
target_compile_definitions(GrowtopiBot PRIVATE
    _CONSOLE
    CPPHTTPLIB_OPENSSL_SUPPORT
)

# Link libraries
target_link_libraries(GrowtopiBot PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
    CURL::libcurl
    Threads::Threads
)
