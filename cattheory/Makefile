all: pdf
	cd src/cpp && $(MAKE)


pdf: cattheory.tex
	pdflatex  -interaction=nonstopmode -shell-escape cattheory.tex
	bibtex cattheory
	pdflatex  -interaction=nonstopmode -shell-escape cattheory.tex

clean:
	rm -rf *.aux cattheory.bbl *.dvi *.blg *.toc *.out *.idx
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" -o -name "*.ind" -o -name "*.ilg" \) -exec rm -rf {} \;
	cd src/cpp && $(MAKE) clean

