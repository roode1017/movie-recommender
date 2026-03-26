#include "rating.h"
#include <iostream>


// 기본 생성자
Rating::Rating()
    : userId(0), movieId(0), score(0.0) {}


// 3인자 생성자
Rating::Rating(int userId, int movieId, double score)
    : userId(userId), movieId(movieId), score(0.0) {
    if (score >= 0.0 && score <= 5.0)  // 유효성 검사
        this->score = score;
}


int    Rating::getUserId()  const { return userId; }
int    Rating::getMovieId() const { return movieId; }
double Rating::getScore()   const { return score; }


void Rating::display() const {
    std::cout << "사용자 " << userId
              << " → 영화 " << movieId
              << " : " << score << "점"
              << std::endl;
}
