BINS := unsigned_abs unsigned_abs_stdlib_h unsigned_abs_std_abs
all: $(BINS)

CXXFLAGS := -g -Wall -Werror -m32

unsigned_abs: unsigned_abs.cc
	g++ -o $@ $< $(CXXFLAGS)

unsigned_abs_stdlib_h: unsigned_abs.cc
	g++ -o $@ $< $(CXXFLAGS) -DSTDLIB_H_VERSION

unsigned_abs_std_abs: unsigned_abs.cc
	g++ -o $@ $< $(CXXFLAGS) -DSHOW_AMBIGUOUS_STD_ABS


clean:
	rm -rf *~ $(BINS)