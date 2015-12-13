all:
	-mkdir build
	cd build && cmake .. && make

release:
	-mkdir build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make

.PHONY:
rm:
	-rm -rf ./build

