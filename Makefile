CXX      = g++
CXXFLAGS = -std=c++17 -Wall -g

TARGET = movie_recommender
OBJS   = main.o movie.o user.o rating.o movie_manager.o user_manager.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp movie.h user.h movie_manager.h user_manager.h
	$(CXX) $(CXXFLAGS) -c $<

movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) -c $<

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c $<

rating.o: rating.cpp rating.h
	$(CXX) $(CXXFLAGS) -c $<

movie_manager.o: movie_manager.cpp movie_manager.h movie.h
	$(CXX) $(CXXFLAGS) -c $<

user_manager.o: user_manager.cpp user_manager.h user.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
