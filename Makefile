elite:
	-mkdir build
	cd build && cmake .. && make

release:
	-mkdir build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make deps && make

test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON && make deps && make


only_test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON && make

deps:
	-mkdir build
	cd build && cmake .. && make deps

.PHONY:
rm:
	-rm -rf ./build
	-rm -rf ./extlib

