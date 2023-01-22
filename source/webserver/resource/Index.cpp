#include "webserver/resource/Index.hpp"

namespace Resource {
    std::shared_ptr<httpserver::http_response> Index::render(const httpserver::http_request & req) {
        return std::shared_ptr<httpserver::http_response>(new httpserver::string_response("Hello!"));
    }
};