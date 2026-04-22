#pragma once
#include <string>
#include <vector>
#include "movie.h"
#include "rating.h"
#include "manager.h"

class MovieManager : public Manager {
private:
    std::vector<Movie>  movies;
    std::vector<Rating> ratings;

public:
    void   addMovie(const Movie& movie);
    Movie* findByTitle(const std::string& title);
    void   sortByRating();
    void   printAll() const override;
    int    size() const;

    void addRatingEntry(int userId, int movieId, double score);
    void printRatingsByMovie(int movieId) const;
};
