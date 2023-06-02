#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QFont font("MonoLisa");
    font.setBold(true);
    a.setFont(font);
    w.setWindowTitle("Database");
    w.show();
    return a.exec();
}
