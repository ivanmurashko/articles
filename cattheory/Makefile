all: pdf ps

ps: cattheory.tex 
	latex cattheory.tex

pdf: cattheory.tex
	pdflatex cattheory.tex
	bibtex cattheory
	pdflatex cattheory.tex

clean:
	rm -rf *.aux cattheory.bbl *.dvi *.blg *.toc *.out *.idx
	find . \( -name "*.log" -o -name "*~" -o -name "*.ind" -o -name "*.ilg" \) -exec rm -rf {} \; 
