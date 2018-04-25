all: pdf ps

ps: main.tex main.bib
	latex main.tex

pdf: main.tex
	pdflatex main.tex

clean:
	rm -rf main.aux main.bbl main.dvi main.pdf crypto.pdf crypto.dvi 
	rm -rf main.blg main.toc main.out main.idx main.ilg main.ind
	rm -rf algorithmic.sty  algorithm.sty
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
