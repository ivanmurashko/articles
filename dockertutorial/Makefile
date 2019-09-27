all: dockertutorial.tex
	pdflatex -interaction=nonstopmode -shell-escape dockertutorial.tex
	bibtex dockertutorial
	pdflatex -interaction=nonstopmode -shell-escape dockertutorial.tex

clean:
	rm -rf dockertutorial.aux dockertutorial.bbl dockertutorial.dvi 
	rm -rf dockertutorial.blg dockertutorial.toc dockertutorial.out dockertutorial.idx dockertutorial.ilg dockertutorial.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf _minted-*
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
