#include <QGridLayout>
#include <QSvgWidget>
#include <QWebEngineView>

#include "LightingFrame.hpp"

LightingFrame::LightingFrame(Template::IHeaderPage * parent) : QWidget(parent->widget()) {
    parent->setHeadingText("Lighting");
    parent->setIcon(new QSvgWidget(":/Lighting/icons/light-bulb.svg"));

    QWebEngineView * webEngineView = new QWebEngineView(parent->widget());
    webEngineView->setAttribute(Qt::WA_TranslucentBackground);
    webEngineView->page()->setBackgroundColor(Qt::transparent);
    webEngineView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    webEngineView->setStyleSheet("background: transparent");
    webEngineView->setUrl(QUrl("http://localhost:1234"));

    parent->setMainWidget(webEngineView);
}