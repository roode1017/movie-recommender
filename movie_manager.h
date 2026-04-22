#pragma once
#include <string>
#include <vector>
#include "movie.h"
#include "rating.h"
#include "manager.h"

class UserManager;

class MovieManager : public Manager {
private:
    std::vector<Movie>  movies;
    std::vector<Rating> ratings;

public:
    void   addMovie(const Movie& movie);
    Movie* findByTitle(const std::string& title);
    Movie* findById(int id);
    void   sortByRating();
    void   printAll() const override;
    int    size() const;

    bool addRatingEntry(int userId, int movieId, double score);
    void printRatingsByMovie(int movieId, const UserManager& userMgr) const;
};
