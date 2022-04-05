#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicle.h"
#include "csvreader.h"
#include "csvwriter.h"
#include "jsonreader.h"
#include <QFileDialog>
#include <QFileInfo>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString filePath = getFilePath();

    QFileInfo inf(filePath);
    QString file_extenstion = inf.suffix();

    if(file_extenstion == "csv")
    {
        CSVReader csv(filePath);
        absRead(csv);
    }
    if(file_extenstion == "json")
    {
        JSONReader json(filePath);
        absRead(json);
    }


    for (const auto& v: vehicles)
        {
            ui->textBrowser_lisfOfSearchedData->appendGreen(QString::number(v.ID) + "," + v.brand_and_model + "," + QString::number(v.color) + "," + QString::number(v.year));
        }
}


MainWindow::~MainWindow()
{
    csvwriter csv_out("E:/VSCode/CPP/build-LAB_2_OOP-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/DatabaseOutput.csv");
    csv_out.writeAll(vehicles);
    delete ui;
}

void MainWindow::findVehicle()
{
    int kostil = 0;
        int palka = -1;
        for (const auto& v: vehicles)
        {
            if((v.brand_and_model).right(v.brand_and_model.size() - 1) == ui->dataEntry->text())
            {
                ui->textBrowser_lisfOfSearchedData->appendGreen(QString::number(v.ID) + "," + v.brand_and_model + "," + QString::number(v.color) + "," + QString::number(v.year));
            palka = 1;
            }
            kostil +=1;
            if(kostil == int(vehicles.size()) && palka == -1)
            {
            ui->textBrowser_lisfOfSearchedData->appendRed("Information hasn't been found");

            }
        }
}

QString MainWindow::getFilePath()
{
      return QFileDialog::getOpenFileName(0, "Open File", "", "*.csv *.json");
}




void MainWindow::addToVector()
{
    Vehicle vehicle;

    vehicle.ID = (ui->edit_ID->text().toInt());
    vehicle.brand_and_model = ui->edit_Model->text();
    vehicle.year = (ui->edit_Year->text()).toInt();
    vehicle.color = static_cast<Color>(ui->colorBox->currentIndex());
    vehicles.push_back(vehicle);

}



void MainWindow::absRead(AbstractReader& reader)
{
    if(reader.is_open())
    {
        vehicles = reader.readAll();
    }
}

