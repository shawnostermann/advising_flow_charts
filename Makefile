#
# Main Makefile for graphvis
#
# version 0.0.1 - Mar 23, 2022
#

.PRECIOUS: %.gv

DOTCCSOURCES=${wildcard *.dotcc}
DOTSOURCES=${DOTCCSOURCES:.dotcc=.gv}
DOTBWSOURCES=${DOTSOURCES:.gv=_bw.gv}
PNGFILES=${DOTSOURCES:.gv=.png}
PDFFILES=${DOTSOURCES:.gv=.pdf}
HEADERS=${wildcard *.h}

default: pdf png bw

pdf: ${PDFFILES}
png: ${PNGFILES}


#
# default rules
#
%.gv: %.dotcc ${HEADERS}
	cpp $*.dotcc > $*.gv 
%.png: %.gv
	dot -Tpng  -o $*.png $*.gv
%.pdf: %.gv
	dot -Tpdf  -o $*.pdf $*.gv
%.eps: %.gv
	dot -Teps  -o $*.eps $*.gv
%.ps: %.gv
	dot -Tps  -o $*.ps $*.gv
%.gv: %.dotcc ${HEADERS}
	cpp $*.dotcc > $*.gv 
%_bw.gv: %.gv ${HEADERS}
	cp $*.gv $*_bw.gv 
#
# make bw (black and white) copies for printing
#
bw: ${DOTBWSOURCES}
	

commit: pdf png
	git add ${HEADERS} ${DOTCCSOURCES} ${DOTSOURCES} ${PDFFILES} Makefile
	git commit -m latest
	git push

clean:
	rm -f ${PNGFILES} ${PDFFILES} ${DOTSOURCES} ${DOTBWSOURCES}
	