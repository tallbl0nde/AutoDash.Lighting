#ifndef WEBSERVER_RESOURCE_INDEX_HPP
#define WEBSERVER_RESOURCE_INDEX_HPP

#include <httpserver.hpp>

namespace Resource {
    class Index : public httpserver::http_resource {
        public:
            std::shared_ptr<httpserver::http_response> render_GET(const httpserver::http_request & req) override;
    };
};

#endif