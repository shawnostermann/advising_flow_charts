// C Preprocessor Style macros

// Version 0.9 - Shawn Ostermann - May 24, 2022

// the look of required classes
#define REQUIRED_TEMPLATE(color) shape=polygon, sides=10, penwidth=10, style = "filled", fontcolor=black, fillcolor=color
#define REQUIREDCS   REQUIRED_TEMPLATE(green3)
#define REQUIREDEE   REQUIRED_TEMPLATE(orange3)
#define MATH 	     REQUIRED_TEMPLATE(skyblue)
#define SCIENCE      REQUIRED_TEMPLATE(red1)

// the look of elective classes
#define ELECTIVE_TEMPLATE(color) shape = ellipse, penwidth=2, color = blueviolet, style = filled, fillcolor=color
#define TECHELECTCS ELECTIVE_TEMPLATE(greenyellow) 
#define TECHELECTEE ELECTIVE_TEMPLATE(orange1)

// the look of remedial (Intro) classes
#define REMEDIAL_TEMPLATE(color) shape = box, penwidth=2, style = filled, fontcolor=black, fillcolor=color
#define REMEDIALMATH REMEDIAL_TEMPLATE(lightgoldenrod2)
#define REMEDIALCS   REMEDIAL_TEMPLATE(lightgoldenrod2)

// this controls what the prerequisite arrows look like
#define PREREQ(thisclass,prevclass)  prevclass -> thisclass
#define COREQ(thisclass,prevclass)   prevclass -> thisclass [ label = "Coreq", fontsize=60, penwidth=8, style=dotted]
#define PREREQ_LABEL(thisclass,prevclass,condition)   prevclass -> thisclass [ label = condition, fontsize=60, fontcolor=red, penwidth=5, color=red, style=bold]
#define PREREQ_C(thisclass,prevclass)   PREREQ_LABEL(thisclass,prevclass, " ≥C")

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

// Note, the "when" line below has 2 non-printing space characters ("en space", copied from Word)
// otherwise, graphviz miscalculated "centering" whence fonts change and this moves the "semester" a little more to the left. Sigh...
#define CLASS(classnumber,type,when,shortname,longname)  \
node [type,width=0.25,margin="0,0",fontsize=28] ; classnumber [margin="0,0", label=\
	  < \
	  	<FONT POINT-SIZE="72"> <b> classnumber </b> </FONT> <br/> \
	  	<FONT POINT-SIZE="55"> shortname </FONT> <FONT POINT-SIZE="50"> <br /> </FONT>\
	  	<FONT POINT-SIZE="48" face="Impact"> when   </FONT> \
	   >];
