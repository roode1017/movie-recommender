// main.cpp
#include <iostream>
#include <vector>
#include "movie.h"
#include "user.h"
#include "rating.h"

int main() {
    // ── 영화 목록 ──────────────────────────────────────
    std::vector<Movie> movies;
    movies.push_back(Movie(1, "Inception",    "Sci-Fi",   2010));
    movies.push_back(Movie(2, "Parasite",     "Thriller", 2019));
    movies.push_back(Movie(3, "Interstellar", "Sci-Fi",   2014));

    // ── 사용자 목록 ────────────────────────────────────
    std::vector<User> users;
    users.push_back(User(1, "Alice", "alice@example.com"));
    users.push_back(User(2, "Bob",   "bob@example.com"));

    // ── 평점 목록 ──────────────────────────────────────
    std::vector<Rating> ratings;
    ratings.push_back(Rating(1, 1, 4.8));  // Alice → Inception
    ratings.push_back(Rating(1, 2, 5.0));  // Alice → Parasite
    ratings.push_back(Rating(2, 1, 4.5));  // Bob   → Inception
    ratings.push_back(Rating(2, 3, 4.0));  // Bob   → Interstellar

    // 평점을 Movie에 반영
    for (const Rating& r : ratings) {
        for (Movie& m : movies) {
            if (m.getId() == r.getMovieId()) {
                m.addRating(r.getScore());
                break;
            }
        }
    }

    // ── 출력 ───────────────────────────────────────────
    std::cout << "=== 영화 목록 ===" << std::endl;
    for (const Movie& m : movies) {
        m.display();
    }
    std::cout << "총 " << movies.size() << "편" << std::endl;

    std::cout << "\n=== 사용자 목록 ===" << std::endl;
    for (const User& u : users) {
        u.display();
    }

    std::cout << "\n=== 평점 기록 ===" << std::endl;
    for (const Rating& r : ratings) {
        r.display();
    }

    return 0;
}
