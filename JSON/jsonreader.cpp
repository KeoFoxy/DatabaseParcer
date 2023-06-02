#include "jsonreader.h"

JSONReader::JSONReader(const QString &fileName) {
    fin.open(fileName.toLatin1().data());
}

std::vector<Films> JSONReader::readAll() {
    std::vector<Films> result;

    nlohmann::json json;

    fin >> json;

    for(const auto & j: json) {
        try {
        Films film;

        film.setTitle(j["title"]);
        film.setTargetId(j["target_id"]);
        film.setTargetType(j["target_type"]);
        film.setRating(j["rating"]);
        film.setStatus(j["status"]);
        film.setRewatches(j["rewatches"]);
        film.setEpisodes(j["episodes"]);

        result.push_back(film);
        } catch( nlohmann::json::parse_error& error ) {
                std::cout << error.what() << std::endl;
        }
    }

    return result;
}
