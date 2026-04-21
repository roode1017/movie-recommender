#include <iostream>
#include <string>
#include "movie.h"
#include "user.h"
#include "movie_manager.h"
#include "user_manager.h"

int getValidInt(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        std::cin >> val;
        if (!std::cin.fail()) {
            std::cin.ignore(1000, '\n');
            return val;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "  숫자를 입력하세요.\n";
    }
}

double getValidDouble(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        std::cin >> val;
        if (!std::cin.fail()) {
            std::cin.ignore(1000, '\n');
            return val;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "  숫자를 입력하세요.\n";
    }
}

std::string getLine(const std::string& prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

void menuAddMovie(MovieManager& mgr) {
    std::cout << "\n-- 영화 추가 --\n";
    std::string title = getLine("  제목: ");
    std::string genre = getLine("  장르: ");
    int year = getValidInt("  개봉 연도 (1888~2100): ");
    if (year < 1888 || year > 2100) {
        std::cout << "  유효하지 않은 연도입니다.\n";
        return;
    }
    int id = mgr.size() + 1;
    mgr.addMovie(Movie(id, title, genre, year));
    std::cout << "  영화가 추가되었습니다.\n";
}

void menuFindMovie(MovieManager& mgr) {
    std::cout << "\n-- 영화 검색 --\n";
    std::string title = getLine("  검색할 제목: ");
    Movie* found = mgr.findByTitle(title);
    if (found)
        std::cout << "  찾았습니다: " << *found << "\n";
    else
        std::cout << "  \"" << title << "\" 을(를) 찾을 수 없습니다.\n";
}

void menuSortAndPrint(MovieManager& mgr) {
    std::cout << "\n-- 평점순 정렬 (낮은 → 높은) --\n";
    mgr.sortByRating();
    mgr.printAll();
}

void menuPrintAll(MovieManager& mgr) {
    std::cout << "\n-- 전체 영화 목록 (" << mgr.size() << "편) --\n";
    mgr.printAll();
}

void menuAddUser(UserManager& umgr) {
    std::cout << "\n-- 사용자 추가 --\n";
    std::string name  = getLine("  이름: ");
    std::string email = getLine("  이메일: ");
    int id = umgr.size() + 1;
    umgr.addUser(User(id, name, email));
    std::cout << "  사용자가 추가되었습니다.\n";
}

void menuPrintUsers(UserManager& umgr) {
    std::cout << "\n-- 전체 사용자 목록 (" << umgr.size() << "명) --\n";
    umgr.printAll();
}

int main() {
    MovieManager movieMgr;
    UserManager  userMgr;

    movieMgr.addMovie(Movie(1, "Inception",    "Sci-Fi",   2010));
    movieMgr.addMovie(Movie(2, "Parasite",     "Thriller", 2019));
    movieMgr.addMovie(Movie(3, "Interstellar", "Sci-Fi",   2014));
    userMgr.addUser(User(1, "Alice", "alice@example.com"));
    userMgr.addUser(User(2, "Bob",   "bob@example.com"));

    // 초기 평점 데이터 추가 (정렬 테스트용)
    if (Movie* m = movieMgr.findByTitle("Inception")) {
        m->addRating(4.8);
        m->addRating(4.5); // 평균 4.65
    }
    if (Movie* m = movieMgr.findByTitle("Parasite")) {
        m->addRating(5.0); // 평균 5.0
    }
    if (Movie* m = movieMgr.findByTitle("Interstellar")) {
        m->addRating(4.0); // 평균 4.0
    }

    int choice;
    do {
        std::cout << "\n=== Movie Recommender ===\n"
                  << "  1. 영화 추가\n"
                  << "  2. 영화 검색\n"
                  << "  3. 평점순 정렬\n"
                  << "  4. 전체 출력\n"
                  << "  5. 사용자 추가\n"
                  << "  6. 사용자 목록\n"
                  << "  0. 종료\n"
                  << "선택: ";

        choice = getValidInt("");

        switch (choice) {
            case 1: menuAddMovie(movieMgr);          break;
            case 2: menuFindMovie(movieMgr);         break;
            case 3: menuSortAndPrint(movieMgr);      break;
            case 4: menuPrintAll(movieMgr);          break;
            case 5: menuAddUser(userMgr);            break;
            case 6: menuPrintUsers(userMgr);         break;
            case 0: std::cout << "종료합니다.\n";    break;
            default: std::cout << "  0~6 사이의 번호를 선택하세요.\n";
        }
    } while (choice != 0);

    return 0;
}
