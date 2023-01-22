#include "LightingFrame.hpp"
#include "LightingModule.hpp"
#include "webserver/WebServer.hpp"
#include "Version.hpp"

#define WEBSERVER_PORT 1234

LightingModule::LightingModule() : IModule() {
    this->webServer = new WebServer(WEBSERVER_PORT);
}

std::string LightingModule::versionCompiledFor() {
    return AUTODASH_VERSION;
}

void LightingModule::initialize(IResolver * resolver) {
    this->resolver = resolver;
}

IModule::Metadata LightingModule::metadata() {
    return Metadata {
        "Lighting",                               // Name
        "tallbl0nde",                             // Author
        ":/Lighting/icons/light-bulb.svg",        // Icon
        "0.0.1"                                   // Version
    };
}

std::vector<ISettingEntry *> LightingModule::settingEntries(ISettingEntryFactory * settingEntryFactory) {
    // TODO: Return actual settings
    return std::vector<ISettingEntry *>();
}

QWidget * LightingModule::widget(QWidget * parent) {
    Template::IHeaderPage * headerPage = this->resolver->templateProvider()->createHeaderPage();
    LightingFrame * lightingFrame = new LightingFrame(headerPage);
    return headerPage->widget();
}

LightingModule::~LightingModule() {
    delete this->webServer;
}
