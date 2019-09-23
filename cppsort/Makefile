all: cppsort.tex
	pdflatex -interaction=nonstopmode -shell-escape cppsort.tex
	bibtex cppsort
	pdflatex -interaction=nonstopmode -shell-escape cppsort.tex
	cd src && $(MAKE)


clean:
	rm -rf cppsort.aux cppsort.bbl cppsort.dvi 
	rm -rf cppsort.blg cppsort.toc cppsort.out cppsort.idx cppsort.ilg cppsort.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd src && $(MAKE) clean
