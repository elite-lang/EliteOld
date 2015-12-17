elite:
	-mkdir build
	cd build && cmake .. && make elite

release:
	-mkdir build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make deps && make elite

test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON && make deps && make elite

only_test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON && make elite

deps:
	-mkdir build
	cd build && cmake .. && make deps

.PHONY:
rm:
	-rm -rf ./build
	-rm -rf ./extlib

