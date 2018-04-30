
all: cppabi.tex
	pdflatex -interaction=nonstopmode -shell-escape cppabi.tex
	bibtex cppabi
	pdflatex -interaction=nonstopmode -shell-escape cppabi.tex

	cd presentation && $(MAKE)
	cd src && $(MAKE)


clean:
	rm -rf cppabi.aux cppabi.bbl cppabi.dvi cppabi.pdf crypto.pdf crypto.dvi 
	rm -rf cppabi.blg cppabi.toc cppabi.out cppabi.idx cppabi.ilg cppabi.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-cppabi
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
	cd src && $(MAKE) clean
