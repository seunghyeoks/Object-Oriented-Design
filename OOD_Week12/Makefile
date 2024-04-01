#TODO: Set your googletest directory path
GTEST_DIR = /Users/BookShelf/WorkSpace/git/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


#TODO edit hw and .o file
all : hw12


hw12: hw12.cc safe_math.o divide_by_zero_exception.o empty_container_exception.o
	$(CC) --std=c++17 $^ -o $@

safe_math.o : safe_math.cc
	$(CC) --std=c++17 -c $^ -o $@

divide_by_zero_exception.o : divide_by_zero_exception.cc
	$(CC) --std=c++17 -c $^ -o $@

empty_container_exception.o : empty_container_exception.cc
	$(CC) --std=c++17 -c $^ -o $@

test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO : edit .o file name
test: test.o gtest_main.a safe_math.o divide_by_zero_exception.o empty_container_exception.o
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@



#TODO : edit hw
clean:
	rm -f gtest.a gtest_main.a *.o hw12 test 


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


