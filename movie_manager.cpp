#include "movie_manager.h"
#include <algorithm>
#include <iostream>

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

Movie* MovieManager::findByTitle(const std::string& title) {
    for (Movie& m : movies) {
        if (m.getTitle() == title)
            return &m;
    }
    return nullptr;
}

void MovieManager::sortByRating() {
    std::sort(movies.begin(), movies.end());
}

void MovieManager::printAll() const {
    if (movies.empty()) {
        std::cout << "  (등록된 영화가 없습니다)\n";
        return;
    }
    for (const Movie& m : movies)
        std::cout << "  " << m << "\n";
}

int MovieManager::size() const {
    return static_cast<int>(movies.size());
}

void MovieManager::addRatingEntry(int userId, int movieId, double score) {
    ratings.push_back(Rating(userId, movieId, score));
    for (Movie& m : movies) {
        if (m.getId() == movieId) {
            m.addRating(score);
            break;
        }
    }
}

void MovieManager::printRatingsByMovie(int movieId) const {
    std::string movieTitle = "(알 수 없음)";
    for (const Movie& m : movies) {
        if (m.getId() == movieId) {
            movieTitle = m.getTitle();
            break;
        }
    }
    std::cout << "  [" << movieTitle << "] 평점 목록:\n";
    bool found = false;
    for (const Rating& r : ratings) {
        if (r.getMovieId() == movieId) {
            r.display();
            found = true;
        }
    }
    if (!found)
        std::cout << "  (등록된 평점이 없습니다)\n";
}
