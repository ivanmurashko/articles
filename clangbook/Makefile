all: clangbook.tex
	pdflatex -shell-escape clangbook.tex
	bibtex clangbook
	pdflatex -shell-escape clangbook.tex

clean:
	rm -rf clangbook*.aux clangbook*.bbl clangbook*.dvi 
	rm -rf clangbook*.blg clangbook*.toc clangbook*.out clangbook*.idx clangbook*.ilg clangbook*.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \;
	cd src; make clean
