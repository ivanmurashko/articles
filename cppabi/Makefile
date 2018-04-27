all: cppabi.tex
	pdflatex cppabi.tex
	cd presentation && $(MAKE)

clean:
	rm -rf cppabi.aux cppabi.bbl cppabi.dvi cppabi.pdf crypto.pdf crypto.dvi 
	rm -rf cppabi.blg cppabi.toc cppabi.out cppabi.idx cppabi.ilg cppabi.ind
	rm -rf algorithmic.sty  algorithm.sty
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
