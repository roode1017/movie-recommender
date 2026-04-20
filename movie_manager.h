#pragma once
#include <string>
#include <vector>
#include "movie.h"

class MovieManager {
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& movie);
    Movie* findByTitle(const std::string& title);
    void sortByRating();
    void printAll() const;
    int size() const;
};
