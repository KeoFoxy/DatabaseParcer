#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicle.h"
#include "csvreader.h"
#include "csvwriter.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CSVReader csv("E:/VSCode/CPP/build-LAB_2_OOP-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/Database.csv");

    if(csv.is_open())
    {
        vehicles = csv.readAll();

        std::sort(vehicles.begin(), vehicles.end(), [](const Vehicle &vehicle_1, const Vehicle &vehicle_2){
            return vehicle_1.year > vehicle_2.year;
        });
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


void MainWindow::addToVector()
{
    Vehicle vehicle;

    vehicle.ID = (ui->edit_ID->text().toInt());
    vehicle.brand_and_model = ui->edit_Model->text();
    vehicle.year = (ui->edit_Year->text()).toInt();
    vehicle.color = static_cast<Color>(ui->colorBox->currentIndex());
    vehicles.push_back(vehicle);

}

