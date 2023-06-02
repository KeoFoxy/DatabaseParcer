#include "films.h"

void Films::setRating(int rating) {
    this->rating = rating;
}

void Films::setYear(int year) {
    this->year = year;
}

void Films::setTitle(std::string title) {
    this->title = title;
}

void Films::setGenre(std::string genre) {
    this->genre = genre;
}

void Films::setTargetId(int targetId){
    this->target_id = targetId;
}

void Films::setRewatches(int rewatches) {
    this->rewatches = rewatches;
}

void Films::setEpisodes(int episodes) {
    this->episodes = episodes;
}

void Films::setTargetType(std::string targetType) {
    this->target_type = targetType;
}

void Films::setStatus(std::string status) {
    this->status = status;
}

void Films::setText(std::string text) {
    this->text = text;
}

int Films::getRating() const {
    return rating;
}

int Films::getYear() const {
    return year;
}

int Films::getTargetId() const {
    return target_id;
}

int Films::getRewatches() const {
    return rewatches;
}

int Films::getEpisodes() const {
    return episodes;
}

std::string Films::getTitle() const{
    return title;
}

std::string Films::getGenre() const {
    return genre;
}

std::string Films::getTargetType() const {
    return target_type;
}

std::string Films::getStatus() const {
    return status;
}

std::string Films::getText() const {
    return text;
}


