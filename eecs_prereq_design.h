// C Preprocessor Style macros

// Version 0.9 - Shawn Ostermann - May 24, 2022

// the look of required classes
#define REQUIRED_TEMPLATE(bgcolor,fcolor) shape=oval, sides=4, penwidth=4, style = "filled", fontcolor=fcolor, fillcolor=bgcolor
#define REQUIREDCS   REQUIRED_TEMPLATE(green2,		white)
#define REQUIREDEE   REQUIRED_TEMPLATE(goldenrod,	black)
#define MATH 	     REQUIRED_TEMPLATE(skyblue,		black)
#define SCIENCE      REQUIRED_TEMPLATE(red1,		black)

// the look of elective classes
#define ELECTIVE_TEMPLATE(bgcolor,fcolor) shape = rectangle, sides=10, penwidth=4, fillcolor = bgcolor, style = filled, fontcolor=fcolor
#define TECHELECTCS ELECTIVE_TEMPLATE(palegreen,		black) 
#define TECHELECTEE ELECTIVE_TEMPLATE(lightgoldenrod1,	black)

// the look of remedial (Intro) classes
#define REMEDIAL_TEMPLATE(color) shape = box, penwidth=2, style = filled, fontcolor=black, fillcolor=color
#define REMEDIALMATH REMEDIAL_TEMPLATE(lightpink)
#define REMEDIALCS   REMEDIAL_TEMPLATE(lightpink)
#define REMEDIALEE   REMEDIAL_TEMPLATE(lightpink)

// this controls what the prerequisite arrows look like
#define PREREQ(thisclass,prevclass) prevclass -> thisclass [penwidth=6]
#define COREQ(thisclass,prevclass)  prevclass -> thisclass [ dir=both, label = "Coreq", fontcolor=blue, color=blue, style=bold fontsize=60, penwidth=10, style=dashed] { rank=same thisclass prevclass }
#define PREREQ_LABEL(thisclass,prevclass,condition)   prevclass -> thisclass [ label = condition, fontsize=60, style=bold, fontcolor=red, penwidth=5, color=red]
#define PREREQ_PL(thisclass,prevclass,condition,mycolor)   prevclass -> thisclass [ label = condition, fontsize=30, fontcolor=mycolor, penwidth=5, color=mycolor, style=bold]
#define PREREQ_MPL(thisclass,prevclass,condition)   PREREQ_PL(thisclass,prevclass,condition,blue)
#define PREREQ_CSPL(thisclass,prevclass,condition)  PREREQ_PL(thisclass,prevclass,condition,green3) 
#define PREREQ_C(thisclass,prevclass)   PREREQ_LABEL(thisclass,prevclass, " ≥C")
#define PREREQ_INVIS(thisclass,prevclass)   prevclass -> thisclass [ style=invisible, dir=none]
#define COREQ_INVIS(thisclass,prevclass)   prevclass -> thisclass [ dir=none, style=invisible] { rank=same thisclass prevclass }

// this controls what the "semester" tags look like
#define SEMESTER_TEMPLATE(fontcolor,semester) <FONT COLOR=fontcolor><b> semester </b></FONT>
#define FALL       SEMESTER_TEMPLATE("goldenrod4", Fall )
#define SPRING     SEMESTER_TEMPLATE("red", Spring)
#define FALLSPRING SEMESTER_TEMPLATE("darkblue", F/S)
#define TBA        SEMESTER_TEMPLATE("white", TBA)

// the next line contains non-printing spaces to paste below to get around a mixed-font centering problem in graphviz...
//          

#define PLACEMENT_TEST(testname,testtitle,type)  \
node [type,width=0.25,margin="0,0",fontsize=28] ; testname [margin="0,0", label=\
	  < <FONT POINT-SIZE="72"> <b> testname </b> </FONT> <br/> \
	  	<FONT POINT-SIZE="55"> testtitle </FONT> \
        >];

#define NODE_OR(nodename)  node [shape=circle, style = "filled", penwidth=1, fontcolor=black, fillcolor=yellow] ; nodename [label=" or "]; 

// for things like "Senior Standing" as a prerequisite
#define STANDING(nodelabel,text)  node [shape=box, style = "filled", penwidth=1, fontcolor=black, fillcolor=pink] ; nodelabel [label=text fontsize="50"]; 
#define PREREQ_SENIOR(thisnode,newnode) STANDING(newnode,"senior \n standing") newnode -> thisnode  [color=red] { rank=same thisnode newnode}
#define PREREQ_JUNIOR(thisnode,newnode) STANDING(newnode,"junior \n standing") newnode -> thisnode  color=red] { rank=same thisnode newnode}

//  Note, the "when" line below has 2 non-printing space characters ("en space", copied from Word)
// otherwise, graphviz miscalculated "centering" whence fonts change and this moves the "semester" a little more to the left. Sigh...
#define CLASS(classnumber,type,when,shortname,longname)  \
node [type,width=0.25,margin="0,0",fontsize=28] ; classnumber [margin="0,0", label=\
	  < \
	  	<FONT POINT-SIZE="72"> <b> classnumber </b> </FONT> <br/> \
	  	<FONT POINT-SIZE="55"> shortname </FONT> <FONT POINT-SIZE="50"> <br /> </FONT>\
	  	<FONT POINT-SIZE="48" face="Impact"> when   </FONT> \
	   >, \
	   ];
// classes with a caveat (4 lines)
#define CLASS4(classnumber,type,when,shortname,longname,caveat)  \
node [type,width=0.25,margin="0,0",fontsize=28] ; classnumber [margin="0,0", label=\
	  < \
	  	<FONT POINT-SIZE="72"> <b> classnumber </b> </FONT> <br/> \
	  	<FONT POINT-SIZE="55"> shortname </FONT> <FONT POINT-SIZE="50"> <br /> </FONT>\
	  	<FONT POINT-SIZE="55"> caveat </FONT> <FONT POINT-SIZE="50"> <br /> </FONT>\
	  	<FONT POINT-SIZE="48" face="Impact"> when   </FONT> \
	   >, \
	   ];

// for timestamps
#define INSERT_VERSION_SUBGRAPH    subgraph version { \
		style = rounded; \
		space [label = "0", penwidth=0, fontcolor=black, fillcolor=white, style=invisible, width=10] ; \
		vstring [label = "version: " + __DATE__  , fontsize="60", penwidth=0, fontcolor=black, fillcolor=white] ;};

