#pragma once

#include <string>
#include <vector>



struct PreloaderConfig {
    std::string tf2Path;
    std::vector<std::string> modPaths;
    bool dryRun = false;
};



extern "C" {
    int RunPreloader(const PreloaderConfig* config);
}
