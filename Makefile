BINDIR=bin
BINS+=$(BINDIR)/test

.PHONY: directories

all: $(BINS) directories

directories:
	@mkdir -p ${BINDIR}


%.o: %.cpp %.h
	g++ -fmax-errors=2 --std=c++11 -c $< -o $@

$(BINS) : $(BINDIR)/%: %.cpp DictString.o
	g++ -O0 -fmax-errors=2 --std=c++11 DictString.o $< -o $@

clean:
	rm -f *.o $(BINS)
