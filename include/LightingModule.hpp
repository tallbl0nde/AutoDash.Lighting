#ifndef LIGHTINGMODULE_HPP
#define LIGHTINGMODULE_HPP

#include "interface/IModule.hpp"

// Unique identifier for module.
#define LIGHTINGMODULE_IID "tallbl0nde.AutoDash.LightingModule"

// AutoDash module for controlling lighting.
class LightingModule : public QObject, IModule {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID LIGHTINGMODULE_IID)
    Q_INTERFACES(IModule)

    public:
        // Constructs the module.
        LightingModule();

        // Implement IModule.
        std::string versionCompiledFor() override;
        void initialize(IResolver * resolver) override;
        Metadata metadata() override;
        std::vector<ISettingEntry *> settingEntries(ISettingEntryFactory * settingEntryFactory) override;
        QWidget * widget(QWidget * parent = nullptr) override;

        // Destroys the module object.
        ~LightingModule();
};

#endif
