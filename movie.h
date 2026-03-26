#pragma once
#include <string>

class Movie {
private:
    int         id;
    std::string title;
    std::string genre;
    int         releaseYear;
    double      totalRating;   // 누적 평점
    int         ratingCount;   // 평점 개수

public:
    Movie();                   // 기본 생성자
    Movie(int id, const std::string& title,
          const std::string& genre, int year);

    int         getId()            const;
    std::string getTitle()         const;
    std::string getGenre()         const;
    int         getReleaseYear()   const;
    double      getAverageRating() const;  // 평균 평점 반환
    int         getRatingCount()   const;

    void addRating(double r);    // 평점 추가
    void display()         const;
};
