elite:
	-mkdir build
	cd build && cmake .. && make elite

release:
	-mkdir build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make deps && make elite  && make runtime

test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON -DCOVERAGE_FLAG=ON && make deps && make elite && make runtime

only_test:
	-mkdir build
	cd build && cmake .. -DBUILD_TEST=ON && make

deps:
	-mkdir build
	cd build && cmake .. && make deps

package:
	-mkdir build
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make package

.PHONY:
clean:
	-rm -rf ./build ./bin ./lib ./runtime ./extlib
