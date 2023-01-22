#include "webserver/resource/Index.hpp"
#include "webserver/Utils.hpp"

#include <iostream>

namespace Resource {
    std::shared_ptr<httpserver::http_response> Index::render(const httpserver::http_request & req) {
        std::cout << "Received request: " << req.get_method() << " " << req.get_path() << std::endl;

        if (req.get_path().find("index.css") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.css"), 200, "text/css"));
        } else if (req.get_path().find("index.js") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.js"), 200, "text/javascript"));
        }

        return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.html"), 200, "text/html"));
    }
};