#ifndef FILMS_H
#define FILMS_H

#include <iostream>

class Films {
private:
    int rating;
    int year;
    int target_id;
    int rewatches;
    int episodes;
    std::string title;
    std::string genre;
    std::string target_type;
    std::string status;
    std::string text;


public:
    void setRating(int rating);
    void setYear(int year);
    void setTitle(std::string title);
    void setGenre(std::string genre);
    void setTargetId(int targetId);
    void setRewatches(int rewatches);
    void setEpisodes(int episodes);
    void setTargetType(std::string targetType);
    void setStatus(std::string status);
    void setText(std::string text);

    int getRating() const;
    int getYear() const;
    int getTargetId() const;
    int getRewatches() const;
    int getEpisodes() const;

    std::string getTitle() const;
    std::string getGenre() const;
    std::string getTargetType() const;
    std::string getStatus() const;
    std::string getText() const;
};

#endif // FILMS_H
