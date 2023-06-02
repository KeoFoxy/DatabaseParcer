#include "customtextbrowser.h"

void CustomTextBrowser::appendGreen(const QString &text) {
    auto Color = textColor();
    setTextColor(QColor(qRgb(187,255,204)));
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendRed(const QString &text) {
    auto Color = textColor();
    setTextColor(QColor(qRgb(255,179,186)));
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendBlue(const QString &text) {
    auto Color = textColor();
    setTextColor(QColor(qRgb(198,226,255)));
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendBlack(const QString &text) {
    auto Color = textColor();
    setTextColor(Qt::black);
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendPink(const QString &text) {
    auto Color = textColor();
    setTextColor(QColor(qRgb(255,218,244)));
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendWhite(const QString &text) {
    auto Color = textColor();
    setTextColor(Qt::white);
    append(text);
    setTextColor(Color);
}

void CustomTextBrowser::appendOrange(const QString &text) {
    auto Color = textColor();
    setTextColor(QColor(qRgb(255,223,186)));
    append(text);
    setTextColor(Color);
}
