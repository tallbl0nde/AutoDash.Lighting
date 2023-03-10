#include "webserver/WebServer.hpp"

#include "webserver/resource/Index.hpp"
#include "webserver/resource/Solid.hpp"

WebServer::WebServer(const int port) : server(httpserver::create_webserver(port)) {
    // Initialize resources
    this->resources.push_back(new Resource::Index());
    this->server.register_resource("/",                  this->resources[this->resources.size() - 1]);
    this->server.register_resource("/bootstrap.min.css", this->resources[this->resources.size() - 1]);
    this->server.register_resource("/bootstrap.min.js",  this->resources[this->resources.size() - 1]);
    this->server.register_resource("/index.css",         this->resources[this->resources.size() - 1]);
    this->server.register_resource("/index.js",          this->resources[this->resources.size() - 1]);
    this->server.register_resource("/Rubik.ttf",         this->resources[this->resources.size() - 1]);

    this->resources.push_back(new Resource::Solid());
    this->server.register_resource("/solid",             this->resources[this->resources.size() - 1]);

    this->server.start();
}

WebServer::~WebServer() {
    this->server.stop();

    for (auto resource : this->resources) {
        delete resource;
    }
    this->resources.clear();
}