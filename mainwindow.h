#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vehicle.h>
#include "mytextbrowser.h"
#include "abstractreader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void findVehicle();
    void addToVector();
    void absRead(AbstractReader& reader);
    QString getFilePath();


private:
    Ui::MainWindow *ui;
    std::vector<Vehicle> vehicles;

    QString FilePath;
};
#endif // MAINWINDOW_H
