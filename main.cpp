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
    if (title.empty()) {
        std::cout << "  제목을 입력해야 합니다.\n";
        return;
    }
    std::string genre = getLine("  장르: ");
    if (genre.empty()) {
        std::cout << "  장르를 입력해야 합니다.\n";
        return;
    }
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
    if (title.empty()) {
        std::cout << "  제목을 입력해야 합니다.\n";
        return;
    }
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
    std::string name = getLine("  이름: ");
    if (name.empty()) {
        std::cout << "  이름을 입력해야 합니다.\n";
        return;
    }
    std::string email = getLine("  이메일: ");
    if (email.empty()) {
        std::cout << "  이메일을 입력해야 합니다.\n";
        return;
    }
    int id = umgr.size() + 1;
    umgr.addUser(User(id, name, email));
    std::cout << "  사용자가 추가되었습니다.\n";
}

void menuPrintUsers(UserManager& umgr) {
    std::cout << "\n-- 전체 사용자 목록 (" << umgr.size() << "명) --\n";
    umgr.printAll();
}

void menuAddRating(MovieManager& mmgr, UserManager& umgr) {
    std::cout << "\n-- 평점 입력 --\n";
    if (umgr.size() == 0) {
        std::cout << "  등록된 사용자가 없습니다. 먼저 사용자를 추가하세요.\n";
        return;
    }
    if (mmgr.size() == 0) {
        std::cout << "  등록된 영화가 없습니다. 먼저 영화를 추가하세요.\n";
        return;
    }
    std::cout << "[ 사용자 목록 ]\n";
    umgr.printAll();
    int userId = getValidInt("  사용자 ID: ");
    if (!umgr.findById(userId)) {
        std::cout << "  해당 ID의 사용자를 찾을 수 없습니다.\n";
        return;
    }

    std::cout << "[ 영화 목록 ]\n";
    mmgr.printAll();
    int movieId = getValidInt("  영화 ID: ");
    if (!mmgr.findById(movieId)) {
        std::cout << "  해당 ID의 영화를 찾을 수 없습니다.\n";
        return;
    }

    double score;
    while (true) {
        score = getValidDouble("  평점 (0.0 ~ 5.0): ");
        if (score >= 0.0 && score <= 5.0) break;
        std::cout << "  0.0 ~ 5.0 사이의 값을 입력하세요.\n";
    }
    mmgr.addRatingEntry(userId, movieId, score);
    std::cout << "  평점이 입력되었습니다.\n";
}

void menuRatingsByMovie(MovieManager& mmgr, UserManager& umgr) {
    std::cout << "\n-- 영화별 평점 보기 --\n";
    if (mmgr.size() == 0) {
        std::cout << "  등록된 영화가 없습니다.\n";
        return;
    }
    mmgr.printAll();
    int movieId = getValidInt("  영화 ID: ");
    mmgr.printRatingsByMovie(movieId, umgr);
}

int main() {
    MovieManager movieMgr;
    UserManager  userMgr;

    movieMgr.addMovie(Movie(1, "Inception",    "Sci-Fi",   2010));
    movieMgr.addMovie(Movie(2, "Parasite",     "Thriller", 2019));
    movieMgr.addMovie(Movie(3, "Interstellar", "Sci-Fi",   2014));
    userMgr.addUser(User(1, "Alice", "alice@example.com"));
    userMgr.addUser(User(2, "Bob",   "bob@example.com"));

    movieMgr.addRatingEntry(1, 1, 4.8);  // Alice → Inception
    movieMgr.addRatingEntry(2, 1, 4.5);  // Bob   → Inception
    movieMgr.addRatingEntry(1, 2, 5.0);  // Alice → Parasite
    movieMgr.addRatingEntry(2, 3, 4.0);  // Bob   → Interstellar

    int choice;
    do {
        std::cout << "\n=== Movie Recommender ===\n"
                  << "\n[ 영화 ]\n"
                  << "  1. 영화 추가\n"
                  << "  2. 제목으로 검색\n"
                  << "  3. 전체 목록 출력\n"
                  << "  4. 평점순 정렬 출력\n"
                  << "\n[ 사용자 ]\n"
                  << "  5. 사용자 추가\n"
                  << "  6. 사용자 목록 출력\n"
                  << "\n[ 평점 ]\n"
                  << "  7. 평점 입력\n"
                  << "  8. 영화별 평점 보기\n"
                  << "\n  0. 종료\n"
                  << "선택 > ";

        choice = getValidInt("");

        switch (choice) {
            case 1: menuAddMovie(movieMgr);                    break;
            case 2: menuFindMovie(movieMgr);                   break;
            case 3: menuPrintAll(movieMgr);                    break;
            case 4: menuSortAndPrint(movieMgr);                break;
            case 5: menuAddUser(userMgr);                      break;
            case 6: menuPrintUsers(userMgr);                   break;
            case 7: menuAddRating(movieMgr, userMgr);          break;
            case 8: menuRatingsByMovie(movieMgr, userMgr);    break;
            case 0: std::cout << "종료합니다.\n";              break;
            default: std::cout << "  0~8 사이의 번호를 선택하세요.\n";
        }
    } while (choice != 0);

    return 0;
}
