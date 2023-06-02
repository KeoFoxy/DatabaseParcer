#include "csvwriter.h"

#include <QFile>

CSVWriter::CSVWriter(const QString &fileName) {
    fout.open(fileName.toLatin1().data());
}

void CSVWriter::writeAll(const std::vector<Films> &films) {

    size_t i = 0;
    if (fout.is_open()) {
        for (auto &film : films) {
            if (i != films.size() - 1) {
                fout << film.getTitle() << "," << film.getRating() << "," << film.getTargetId() << "," << film.getEpisodes() << "," << film.getRewatches() << "," << film.getStatus() << "," << film.getTargetType() << std::endl;
                ++i;
            } else
                fout << film.getTitle() << "," << film.getRating() << "," << film.getTargetId() << "," << film.getEpisodes() << "," << film.getRewatches() << "," << film.getStatus() << "," << film.getTargetType();
        }
    } else
        std::cout << "Error! File has not been opened!" << std::endl;
}
