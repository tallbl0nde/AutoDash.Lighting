#ifndef LIGHTINGFRAME_HPP
#define LIGHTINGFRAME_HPP

#include <QWidget>

// Main frame for displaying lighting controls
class LightingFrame : public QWidget {
    Q_OBJECT

    public:
        // Constructs the frame.
        LightingFrame(QWidget * = nullptr);
};

#endif
