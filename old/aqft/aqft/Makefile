all: submission

submissionfiles = aqft.dvi aqft.pdf aqft.tex \
llncs.cls document.PDF

submissiondir = aqft

submission: ps pdf
	rm -rf $(submissiondir)
	mkdir -p $(submissiondir)
	@for file in $(submissionfiles); do \
		cp $$file $(submissiondir); \
	done
	zip -r $(submissiondir).zip $(submissiondir)
	rm -rf $(submissiondir)

ps: aqft.tex slides.tex
	latex aqft.tex
	latex aqft.tex
	latex slides.tex

pdf: aqft.tex
	pdflatex aqft.tex
	pdflatex aqft.tex
	pdflatex slides.tex

clean:
	rm -rf aqft.aux aqft.bbl aqft.dvi aqft.pdf aqft.blg aqft.toc aqft.out
	rm -rf slides.aux slides.bbl slides.dvi slides.pdf slides.blg slides.toc slides.out slides.nav slides.snm
	rm -rf *.zip
	rm -rf subaqft
	rm -rf aqft
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
