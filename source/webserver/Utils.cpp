#include "webserver/Utils.hpp"

std::string Utils::getWebServerFilesDirectory() {
    static std::string path = __FILE__;
    return path.substr(0, path.rfind("/")) + "/../../files/";
}

std::string Utils::getWebServerFilePath(const std::string & file) {
    return getWebServerFilesDirectory() + file;
}