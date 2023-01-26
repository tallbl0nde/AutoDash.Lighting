#ifndef WEBSERVER_RESOURCE_SOLID_HPP
#define WEBSERVER_RESOURCE_SOLID_HPP

#include <httpserver.hpp>

namespace Resource {
    class Solid : public httpserver::http_resource {
        public:
            std::shared_ptr<httpserver::http_response> render_GET(const httpserver::http_request & req) override;
            std::shared_ptr<httpserver::http_response> render_POST(const httpserver::http_request & req) override;
    };
};

#endif