
all:
	git submodule update --init --recursive
	cmake -S . -B build
	cmake --build build
	./build/src/MainProject
clean:
	rm -rf build