#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "csvreader.h"
#include "csvwriter.h"
#include "jsonreader.h"
#include "films.h"

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
    void absRead(AbstractReader &reader);
    void newReadAll(AbstractReader &reader);

private slots:
    void on_addFilePath_clicked();
    void on_buttonFind_clicked();
    void on_addFilmButton_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<Films> films;
    QString filePath = "";
};
#endif // MAINWINDOW_H
