#pragma once

class Rating {
private:
    int    userId;   // 사용자 ID
    int    movieId;  // 영화 ID
    double score;    // 0.0 ~ 5.0

public:
    Rating();
    Rating(int userId, int movieId, double score);

    int    getUserId()  const;
    int    getMovieId() const;
    double getScore()   const;

    void display() const;
};
