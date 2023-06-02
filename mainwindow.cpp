#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::absRead(AbstractReader &reader) {
    if(reader.is_open())
        newReadAll(reader);
}

void MainWindow::newReadAll(AbstractReader &reader) {
    Films film;
    films.clear();

    films = reader.readAll();
}

void MainWindow::on_addFilePath_clicked() {
    filePath = QFileDialog::getOpenFileName(0, "Open File", "", "*.csv *.json");

    QFile file(filePath);
    QFileInfo info(filePath);

    if(info.suffix() == "csv") {
        CSVReader reader(filePath);
        absRead(reader);
    } else if(info.suffix() == "json") {
        JSONReader reader(filePath);
        absRead(reader);
    } else
        ui->dataField->appendRed("Can not read file with" + info.suffix() + "extension");


    ui->dataField->appendOrange("Data from file: " + file.fileName().section("/", -1, -1) + "\n");
    for (auto &film : films) {
        ui->dataField->appendPink("Title: " + QString::fromStdString(film.getTitle()) + ", Rating: " + QString::number(film.getRating()) + "/10" + ", TargetID: " + QString::number(film.getTargetId()) + ", Episodes: " + QString::number(film.getEpisodes()) +  ", Rewatches: " + QString::number(film.getRewatches()) + ", Status: " + QString::fromStdString(film.getStatus()) + ", TargetType: "+ QString::fromStdString(film.getTargetType())); //+ ", " + QString::number(film.getYear()));
        ui->dataField->appendPink("\n");
    }

    ui->dataField->appendPink("\n");
}

void MainWindow::on_buttonFind_clicked() {
    bool flag = true;

    for (auto &film : films) {
        if (film.getTitle() == ui->dataEntry->text().toStdString()) {
            ui->dataField->appendPink("Title: " + QString::fromStdString(film.getTitle()) + ", Rating: " + QString::number(film.getRating()) + "/10" + ", TargetID: " + QString::number(film.getTargetId()) + ", Episodes: " + QString::number(film.getEpisodes()) +  ", Rewatches: " + QString::number(film.getRewatches()) + ", Status: " + QString::fromStdString(film.getStatus()) + ", TargetType: "+ QString::fromStdString(film.getTargetType()));
            flag = false;
        }
    }

    if (flag)
        ui->dataField->appendRed("Can't find '" + ui->dataEntry->text() + "' in Database!\nCheck input data.\n");

}

void MainWindow::on_addFilmButton_clicked() {
    if (ui->editRating->isModified() and ui->editTitle->isModified() and ui->editRewatch->isModified() and ui->editEpisodes->isModified() and ui->editTargetID->isModified() and ui->editTargetType->isModified()) {

        Films newFilm;

        newFilm.setTitle(ui->editTitle->text().toStdString());
        newFilm.setRating((ui->editRating->text()).toInt());
        newFilm.setTargetId((ui->editTargetID->text()).toInt());
        newFilm.setEpisodes(ui->editEpisodes->text().toInt());
        newFilm.setRewatches(ui->editRewatch->text().toInt());
        newFilm.setStatus(ui->comboStatus->currentText().toStdString());
        newFilm.setTargetType(ui->editTargetType->text().toStdString());

        films.push_back(newFilm);

        CSVWriter writer(filePath);
        writer.writeAll(films);

        ui->dataField->appendBlue("New Film added: ");
        ui->dataField->appendPink("Title: " + QString::fromStdString(newFilm.getTitle()) + ", Rating: " + QString::number(newFilm.getRating()) + "/10" + ", TargetID: " + QString::number(newFilm.getTargetId()) + ", Episodes: " + QString::number(newFilm.getEpisodes()) +  ", Rewatches: " + QString::number(newFilm.getRewatches()) + ", Status: " + QString::fromStdString(newFilm.getStatus()) + ", TargetType: "+ QString::fromStdString(newFilm.getTargetType()));
        if (filePath != "")
            ui->dataField->appendBlue("Path to updated file:" + filePath + "\n");
        else
            ui->dataField->appendRed("Please open the file where you want to save data\n");
    } else
        ui->dataField->appendRed("Before clicking 'Add' button enter data!\n");
}
