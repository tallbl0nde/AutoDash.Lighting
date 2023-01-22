#ifndef WEBSERVER_UTILS_HPP
#define WEBSERVER_UTILS_HPP

#include <string>

class Utils {
    public:
        // Returns the path to the directory containing web server files
        // (.html, .css, etc.)
        static std::string getWebServerFilesDirectory();

        // Returns the path to the given file in the web server files directory.
        static std::string getWebServerFilePath(const std::string & file);
};

#endif