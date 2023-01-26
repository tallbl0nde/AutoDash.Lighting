#include "webserver/resource/Index.hpp"
#include "webserver/Utils.hpp"

#include <iostream>

namespace Resource {
    std::shared_ptr<httpserver::http_response> Index::render_GET(const httpserver::http_request & req) {
        std::cout << "Received request: " << req.get_method() << " " << req.get_path() << std::endl;

        if (req.get_path().find("bootstrap.min.css") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("bootstrap.min.css"), httpserver::http::http_utils::http_ok, "text/css"));
        } else if (req.get_path().find("bootstrap.min.js") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("bootstrap.min.js"), httpserver::http::http_utils::http_ok, "text/javascript"));
        } else if (req.get_path().find("index.css") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.css"), httpserver::http::http_utils::http_ok, "text/css"));
        } else if (req.get_path().find("index.js") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.js"), httpserver::http::http_utils::http_ok, "text/javascript"));
        } else if (req.get_path().find("Rubik.ttf") != std::string::npos) {
            return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("Rubik.ttf"), httpserver::http::http_utils::http_ok, "application/octet-stream"));
        }

        return std::shared_ptr<httpserver::http_response>(new httpserver::file_response(Utils::getWebServerFilePath("index.html"), httpserver::http::http_utils::http_ok, "text/html"));
    }
};