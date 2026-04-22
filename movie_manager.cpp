#include "movie_manager.h"
#include "user_manager.h"
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

Movie* MovieManager::findById(int id) {
    for (Movie& m : movies) {
        if (m.getId() == id)
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

bool MovieManager::addRatingEntry(int userId, int movieId, double score) {
    for (Movie& m : movies) {
        if (m.getId() == movieId) {
            m.addRating(score);
            ratings.push_back(Rating(userId, movieId, score));
            return true;
        }
    }
    return false;
}

void MovieManager::printRatingsByMovie(int movieId, const UserManager& userMgr) const {
    std::string movieTitle;
    for (const Movie& m : movies) {
        if (m.getId() == movieId) {
            movieTitle = m.getTitle();
            break;
        }
    }
    if (movieTitle.empty()) {
        std::cout << "  해당 ID의 영화를 찾을 수 없습니다.\n";
        return;
    }
    std::cout << "  [" << movieTitle << "] 평점 목록:\n";
    bool found = false;
    for (const Rating& r : ratings) {
        if (r.getMovieId() == movieId) {
            const User* u = userMgr.findById(r.getUserId());
            std::string name = u ? u->getName() : "알 수 없음";
            std::cout << "  " << name << " : " << r.getScore() << "점\n";
            found = true;
        }
    }
    if (!found)
        std::cout << "  (등록된 평점이 없습니다)\n";
}
