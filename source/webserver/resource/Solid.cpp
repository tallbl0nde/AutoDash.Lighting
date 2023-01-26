#include "webserver/resource/Solid.hpp"

#include <iostream>

namespace Resource {
    std::shared_ptr<httpserver::http_response> Solid::render_GET(const httpserver::http_request & req) {
        std::cout << "Received request: " << req.get_method() << " " << req.get_path() << std::endl;

        return std::shared_ptr<httpserver::http_response>(new httpserver::string_response("", httpserver::http::http_utils::http_not_implemented));
    }

    std::shared_ptr<httpserver::http_response> Solid::render_POST(const httpserver::http_request & req) {
        std::cout << "Received request: " << req.get_method() << " " << req.get_path() << std::endl;

        std::string_view r = req.get_arg("r");
        std::string_view g = req.get_arg("g");
        std::string_view b = req.get_arg("b");
        std::cout << "    Setting solid colour with parameters (r: " << r << ", g: " << g << ", b: " << b << ")" << std::endl;

        return std::shared_ptr<httpserver::http_response>(new httpserver::string_response("", httpserver::http::http_utils::http_ok));
    }
};