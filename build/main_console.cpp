#include <iostream>
#include <thread>
#include <chrono>
extern "C" {
    int enet_initialize(void);
    void enet_deinitialize(void);
}
int main() {
    std::cout << "Growtopia Bot - Linux Console Version" << std::endl;
    int eStatus = enet_initialize();
    std::cout << "ENet initialize status: " << eStatus << std::endl;
    if (eStatus == 0) {
        std::cout << "ENet initialized successfully!" << std::endl;
        std::cout << "Bot is running in console mode..." << std::endl;
        std::cout << "(This is a minimal test build without GUI)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        enet_deinitialize();
    }
    return 0;
}
