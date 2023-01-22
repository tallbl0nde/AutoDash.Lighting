#ifndef WEBSERVER_WEBSERVER_HPP
#define WEBSERVER_WEBSERVER_HPP

#include <vector>

#include "httpserver.hpp"

class WebServer {
    private:
        // Web server object.
        httpserver::webserver server;

        // Resources.
        std::vector<httpserver::http_resource *> resources;

    public:
        // Constructs a new web server.
        WebServer(const int port);

        // Destroys the web server.
        ~WebServer();
};

#endif