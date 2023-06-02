#include "csvreader.h"
#include "films.h"

#include <fstream>

CSVReader::CSVReader(const QString &fileName) {
    fin.open(fileName.toLatin1().data());
}

std::vector<std::string> CSVReader::split_line(const std::string &str, char devider) {
    std::vector<std::string> tokens;

    if (!str.empty()) {
        size_t start = 0, end;

        do {
            end = str.find(devider, start);
            tokens.push_back(str.substr(start, (str.find(devider, start) - start)));
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}

std::vector<Films> CSVReader::readAll() {
    std::vector<Films> result;

    while (!fin.eof()) {
        try {
        std::string line;
        std::getline(fin, line);

        auto f = split_line(line, ',');

        Films film;

        film.setTitle(f[0]);
        film.setRating(std::stoi(f[1]));
        film.setTargetId(std::stoi(f[2]));
        film.setEpisodes(std::stoi(f[3]));
        film.setRewatches(std::stoi(f[4]));
        film.setStatus(f[5]);
        film.setTargetType(f[6]);

        result.push_back(film);

        } catch(const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return result;
}
