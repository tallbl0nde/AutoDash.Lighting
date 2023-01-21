#ifndef LIGHTINGFRAME_HPP
#define LIGHTINGFRAME_HPP

#include "interface/template/IHeaderPage.hpp"

// Main frame for displaying lighting controls
class LightingFrame : public QWidget {
    Q_OBJECT

    public:
        // Constructs the frame.
        LightingFrame(Template::IHeaderPage * parent);
};

#endif
