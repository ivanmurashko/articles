all: pdf

pdf: nn.tex
	pdflatex  -interaction=nonstopmode -shell-escape nn.tex
	bibtex nn
	makeindex nn.nlo -s nomencl.ist -o nn.nls
	pdflatex  -interaction=nonstopmode -shell-escape nn.tex


clean:
	rm -rf *.aux nn.bbl *.dvi *.blg *.toc *.out *.idx *.nlo *.ist *.nls
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" -o -name "*.ind" -o -name "*.ilg" \) -exec rm -rf {} \;
