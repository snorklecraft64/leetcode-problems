IDIR=headers
CC=g++
CFLAGS=-I$(IDIR) -Itests -Itests/headers

ODIR=obj
TDIR=tests
LDIR =../lib
OUTDIR=out

LIBS=-lm

_TESTS = candy traprain romantoint inttoroman longestcommonprefix reversewords zigzagconversion needleinhaystack fulljustify ispalindrome issubsequence twosum2 maxwater threesum minsubarraysum longestnonrepeatingsubstring
TESTS = $(patsubst %,$(TDIR)/$(ODIR)/test_%.o,$(_TESTS))

_OBJ = utilities.o problems.o run_tests.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_DEPS = problems.h utilities.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_TESTDEPS = test.h test_include.h
TESTDEPS = $(patsubst %,$(TDIR)/$(IDIR)/%,$(_TESTDEPS))

_dummy := $(@shell mkdir $(OUTDIR))
_dummy := $(@shell mkdir $(ODIR))
_dummy := $(@shell mkdir $(TDIR)\$(ODIR))

all: test

debug: CFLAGS += -g
debug: test

$(ODIR)/run_tests.o: run_tests.cpp $(TDIR)/$(ODIR)/test.o $(TESTS) $(IDIR)/run_tests.h $(TDIR)/$(IDIR)/all_tests.h $(IDIR)/utilities.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/utilities.o: utilities.cpp $(IDIR)/utilities.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(TDIR)/$(ODIR)/%.o: $(TDIR)/%.cpp $(TESTDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ) $(TDIR)/$(ODIR)/test.o $(TESTS)
	$(CC) -o $(OUTDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	del $(ODIR)\*.o | del $(TDIR)\$(ODIR)\*.o | del $(OUTDIR)\*.exe