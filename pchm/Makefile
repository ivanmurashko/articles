all: pch.tex
	pdflatex -interaction=nonstopmode -shell-escape pch.tex
	bibtex pch
	pdflatex -interaction=nonstopmode -shell-escape pch.tex

clean:
	rm -rf pch*.aux pch*.bbl pch*.dvi 
	rm -rf pch*.blg pch*.toc pch*.out pch*.idx pch*.ilg pch*.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \;
	cd src; make clean
