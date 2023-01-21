#include <QGridLayout>

#include "LightingFrame.hpp"

LightingFrame::LightingFrame(QWidget * parent) : QWidget(parent) {
    // Create stacked widget to swap between connect message
    // and actual stream
    this->setGeometry(parent->rect());
    QGridLayout * layout = new QGridLayout(this);
    layout->setMargin(0);

    // TODO: Implement webview
}