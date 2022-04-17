HEADERS=$(wildcard ./*.h)
PCHS=$(HEADERS:.h=.pch)
%.pch: %.h
	clang -x c++-header $< -o $@

pch: $(PCHS)

exe: main.cpp pch
	clang -include-pch header.pch main.cpp -o main -lstdc++


all: pch exe

clean:
	rm -rf *~ *.dSYM *.pch main
