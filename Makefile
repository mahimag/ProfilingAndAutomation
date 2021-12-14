CC=gcc
CFLAGS=-pg
CPPFLAGS=-I. -g -std=c++11
DEPS =
ODDOBJ = oddinacci.o
MATOBJ = matrix.o
MAT0OBJ = mat0.o
MAT1OBJ = mat1.o
MEASUREOBJ = measure.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CPPFLAGS)

default: $(ODDOBJ) $(MATOBJ) $(MAT0OBJ) $(MAT1OBJ) $(MEASUREOBJ) oddinacci_main.o mat0_main.o mat1_main.o
	$(CC) -o odd oddinacci_main.o $(ODDOBJ) $(MEASUREOBJ) $(CFLAGS)
	$(CC) -o mat0 mat0_main.o $(MATOBJ) $(MAT0BJ) $(MAT0OBJ) $(MEASUREOBJ) $(CFLAGS)
	$(CC) -o mat1 mat1_main.o $(MATOBJ) $(MAT0BJ) $(MAT1OBJ)  $(MEASUREOBJ) $(CFLAGS)

clean:
	rm -f $(ODDOBJ) *.out test/*.o

run: default
	./odd

test-build: $(ODDOBJ) $(MATOBJ) $(MAT0OBJ) $(MAT1OBJ) $(MEASUREOBJ) test/test_main.o
	g++ test/test_main.o $(ODDOBJ) $(MATOBJ) $(MAT0OBJ) $(MAT1OBJ) $(MEASUREOBJ) \
		-o opt_test -lgtest -lgtest_main -lpthread

test-odd: test-build
	./opt_test --gtest_filter=Oddinacci.Test

test-mat0: test-build
	./opt_test --gtest_filter=Matrix.Mat0

test-mat1: test-build
	./opt_test --gtest_filter=Matrix.Mat1

test: test-build
	./opt-test
