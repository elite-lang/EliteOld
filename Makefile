all:
	./scripts/build_all.sh

all-debug:
	./scripts/build_all_debug.sh

self:
	./scripts/build.sh


.PHONY:
rm:
	-rm -rf ./build

.PHONY:
rm-all:
	./scripts/clean_all.sh
