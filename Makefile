CMD = clang++ src/Base.cpp -o


ALL:
	$(CMD) bin/nodenull src/prtNull.cpp
	$(CMD) bin/node0 src/init.cpp
	$(CMD) bin/node1 src/init.cpp 
	$(CMD) bin/node2gen src/genIn.cpp
	$(CMD) bin/node3gen src/genIn.cpp
	$(CMD) bin/node2 src/node2.cpp
	$(CMD) bin/node3 src/node3.cpp
	$(CMD) bin/resgen src/genIn.cpp
