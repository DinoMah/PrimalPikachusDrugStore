app:
	g++ -o ./bin/debug/program main.cpp src/*.cpp && ./bin/debug/program
clean:
	rm ./bin/debug/program