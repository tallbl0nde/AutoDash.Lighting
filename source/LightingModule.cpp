#include "LightingFrame.hpp"
#include "LightingModule.hpp"
#include "Version.hpp"

LightingModule::LightingModule() : IModule() {

}

std::string LightingModule::versionCompiledFor() {
    return AUTODASH_VERSION;
}

void LightingModule::initialize(IResolver * resolver) {

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
     return new LightingFrame(parent);
}

LightingModule::~LightingModule() {

}
