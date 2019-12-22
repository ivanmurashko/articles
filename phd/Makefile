all: pdf ps

ps: main.tex
	latex main.tex
	latex main.tex
	cp main.dvi phd.dvi

pdf: main.tex 
	pdflatex main.tex
	pdflatex main.tex
	cp main.pdf phd.pdf

clean:
	rm -rf phd.dvi main.aux main.bbl main.dvi main.pdf main.blg main.toc main.out 
	rm -rf main.blg main.toc main.out main.idx main.ilg main.ind
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
