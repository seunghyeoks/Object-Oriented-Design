#TODO: Set your googletest directory path
GTEST_DIR = /Users/BookShelf/WorkSpace/git/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


#TODO edit hw and .o file
all : hw13


hw13: hw13.cc node.o int_node.o string_node.o postorder_traversal.o preorder_traversal.o
	$(CC) --std=c++17 $^ -o $@


node.o : node.cc
	$(CC) --std=c++17 -c $^ -o $@

int_node.o : int_node.cc
	$(CC) --std=c++17 -c $^ -o $@

string_node.o : string_node.cc
	$(CC) --std=c++17 -c $^ -o $@

postorder_traversal.o : postorder_traversal.cc
	$(CC) --std=c++17 -c $^ -o $@

preorder_traversal.o : preorder_traversal.cc
	$(CC) --std=c++17 -c $^ -o $@





test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO : edit .o file name
test: test.o gtest_main.a node.o int_node.o string_node.o postorder_traversal.o preorder_traversal.o
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@



#TODO : edit hw
clean:
	rm -f gtest.a gtest_main.a *.o hw13 test 


# No need to edit
gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean


