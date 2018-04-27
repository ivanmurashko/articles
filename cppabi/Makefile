all: pdf ps

ps: cppabi.tex cppabi.bib
	latex cppabi.tex

pdf: cppabi.tex
	pdflatex cppabi.tex

clean:
	rm -rf cppabi.aux cppabi.bbl cppabi.dvi cppabi.pdf crypto.pdf crypto.dvi 
	rm -rf cppabi.blg cppabi.toc cppabi.out cppabi.idx cppabi.ilg cppabi.ind
	rm -rf algorithmic.sty  algorithm.sty
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
