all: pdf ps

algorithmic.sty: algorithms.ins algorithms.dtx
	latex algorithms.ins

ps: main.tex main.bib algorithmic.sty
	latex main.tex
	bibtex main
	latex main.tex

pdf: main.tex main.bib algorithmic.sty
	pdflatex main.tex
	bibtex main
	pdflatex main.tex

clean:
	rm -rf main.aux main.bbl main.dvi main.pdf main.blg main.toc main.out
	rm -rf algorithmic.sty  algorithm.sty
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
