#
# Main Makefile for graphvis
#
# version 0.0.1 - Mar 23, 2022
#

.PRECIOUS: %.gv

DOTCCSOURCES=${wildcard *.dotcc}
DOTSOURCES=${DOTCCSOURCES:.dotcc=.gv}
PNGFILES=${DOTSOURCES:.gv=.png}
PDFFILES=${DOTSOURCES:.gv=.pdf}

default: pdf

pdf: ${PDFFILES}
png: ${PNGFILES}


#
# default rules
#
%.gv: %.dotcc
	cpp $*.dotcc > $*.gv 
%.png: %.gv
	dot -Tpng  -o $*.png $*.gv
%.pdf: %.gv
	dot -Tpdf  -o $*.pdf $*.gv
%.eps: %.gv
	dot -Teps  -o $*.eps $*.gv
%.ps: %.gv
	dot -Tps  -o $*.ps $*.gv

clean:
	rm -f ${PNGFILES} ${PDFFILES}