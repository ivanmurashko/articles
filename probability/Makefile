all: probability.tex
	pdflatex -interaction=nonstopmode -shell-escape probability.tex
	bibtex probability
	pdflatex -interaction=nonstopmode -shell-escape probability.tex

clean:
	rm -rf probability.aux probability.bbl probability.dvi 
	rm -rf probability.blg probability.toc probability.out probability.idx probability.ilg probability.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" -o -name "*.nlo" \) -exec rm -rf {} \; 
