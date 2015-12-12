all:
	./scripts/build_all.sh

all-debug:
	./scripts/build_all_debug.sh

self:
	./scripts/build.sh



rm:
	-rm -rf ./build

rm-all:
	./scripts/clear_all.sh
