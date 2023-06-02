#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QTextBrowser>

class CustomTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    CustomTextBrowser(QWidget *parent = nullptr) : QTextBrowser(parent){};

    void appendGreen(const QString &text); //Новые цвета
    void appendRed(const QString &text);
    void appendBlue(const QString &text);
    void appendBlack(const QString &text);
    void appendPink(const QString &text);
    void appendWhite(const QString &text);
    void appendOrange(const QString &text);

signals:

};

#endif // CUSTOMTEXTBROWSER_H
