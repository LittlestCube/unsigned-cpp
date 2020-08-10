all:
	rm -rf build/ || continue
	mkdir build
	cd build && g++ -c -fPIC ../source/*.cpp