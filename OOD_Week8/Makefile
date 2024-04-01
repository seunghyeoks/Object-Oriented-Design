#TODO: Set your googletest directory path
GTEST_DIR = /Users/BookShelf/WorkSpace/git/googletest/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)


#TODO edit hw and .o file
all : hw8


hw8: hw8.cc car_builder.o car_parts_factory.o car.o door.o hyundai_parts_factory.o kia_parts_factory.o part.o roof.o wheel.o
	$(CC) --std=c++17 $^ -o $@

car_builder.o : car_builder.cc
	$(CC) --std=c++17 -c $^ -o $@

car_parts_factory.o : car_parts_factory.cc
	$(CC) --std=c++17 -c $^ -o $@

car.o : car.cc
	$(CC) --std=c++17 -c $^ -o $@

door.o : door.cc
	$(CC) --std=c++17 -c $^ -o $@

hyundai_parts_factory.o : hyundai_parts_factory.cc
	$(CC) --std=c++17 -c $^ -o $@

kia_parts_factory.o : kia_parts_factory.cc
	$(CC) --std=c++17 -c $^ -o $@

part.o : part.cc
	$(CC) --std=c++17 -c $^ -o $@

roof.o : roof.cc
	$(CC) --std=c++17 -c $^ -o $@

wheel.o : wheel.cc
	$(CC) --std=c++17 -c $^ -o $@




test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO : edit .o file name
test: test.o gtest_main.a car_builder.o car_parts_factory.o car.o door.o hyundai_parts_factory.o kia_parts_factory.o part.o roof.o wheel.o
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@



#TODO : edit hw
clean:
	rm -f gtest.a gtest_main.a *.o hw8 test 


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


