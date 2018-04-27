# Produce main.pdf in output directory specified in latexmkrc

GREP                =   grep
SED                 =   sed
DIA                 =   dia
LATEXMK             =   latexmk
MPOST               =   mpost
PDF2ODP             =   pdf2odp
OFFICE              =   libreoffice

LATEXMKRC           =   ./latexmkrc
PDF_MODE_PTN        =   ^\s*$$pdf_mode\s*=\s*
OUT_EXT             =   $(shell case \
                        `$(GREP) '$(PDF_MODE_PTN)' $(LATEXMKRC) 2>/dev/null | \
                        $(SED) 's/$(PDF_MODE_PTN)\([0-3]\).*/\1/'` \
                        in ([1-3]) echo pdf ;; (*) echo dvi ;; esac)
OUT_DIR_PTN         =   ^\s*$$out_dir\s*=\s*
OUT_DIR             =   $(shell \
                        $(GREP) '$(OUT_DIR_PTN)' $(LATEXMKRC) 2>/dev/null | \
                        $(SED) 's/$(OUT_DIR_PTN)["\x27]\(.*\)["\x27].*/\1/')

ifeq ($(strip $(OUT_DIR)),)
    OUT_DIR         =   .
endif

MAIN                =   cppabi
TARGET              =   $(OUT_DIR)/$(MAIN).$(OUT_EXT)
ODP                 =   $(OUT_DIR)/$(MAIN).odp
PPT                 =   $(OUT_DIR)/$(MAIN).ppt

TEX_SOURCES         =   $(wildcard *.tex)
DIA_SOURCES         =   $(wildcard *.dia)
EPS_IMAGES          =   $(wildcard *.eps)
DIA_MP_SOURCES      =   $(DIA_SOURCES:.dia=.mp)
DIA_MPS_IMAGES      =   $(DIA_SOURCES:.dia=.mps)

DIA_MP_LOGS         =   $(DIA_SOURCES:.dia=.log)
DIA_MPX_FILES       =   $(DIA_SOURCES:.dia=.mpx)
DIA_MP_TRANS_FILES  =   $(DIA_MP_LOGS) $(DIA_MPX_FILES)
DIA_INTERMEDIATES   =   $(DIA_MP_SOURCES) $(DIA_MP_TRANS_FILES)
DIA_ALL_PRODUCTS    =   $(DIA_INTERMEDIATES) $(DIA_MPS_IMAGES)

MAIN_BBL            =   $(OUT_DIR)/$(MAIN).bbl


.PHONY: all clean clean-all odp ppt

.SECONDARY: $(DIA_MP_SOURCES)

all: $(TARGET)

odp: $(ODP)

ppt: $(PPT)

%.mp: %.dia
	$(DIA) -e $@ $<

%.mps: %.mp
	$(MPOST) -s 'outputtemplate="%j.mps"' $<

$(TARGET): $(EPS_IMAGES) $(DIA_MPS_IMAGES) $(TEX_SOURCES)
	$(LATEXMK) $(MAIN)

$(ODP): $(MAIN).pdf
	$(PDF2ODP) -x pdftocairo -s 1600 $(MAIN).pdf

$(PPT): $(ODP)
	$(OFFICE) --headless --convert-to ppt --outdir $(OUT_DIR) $(ODP)

clean:
	$(LATEXMK) -c
	rm -f $(DIA_INTERMEDIATES)

clean-all:
	$(LATEXMK) -C
	rm -f *-eps-converted-to.pdf $(DIA_ALL_PRODUCTS) $(MAIN_BBL) $(ODP) $(PPT)
	rm -rf _minted-nginx-haskell-module-pres/

