all:
	chmod +x $(problem)/* # because I am lazy
	# only do them if they are there!!
	if [ -a $(problem)/*.cpp ] ; \
	then \
		g++ $(problem)/answer.cpp -o $(problem)/answer.cppx ;\
	fi;
	if [ -a $(problem)/*.java ] ; \
	then \
		javac $(problem)/answer.java ;\
	fi;
	if [ -a $(problem)/*.cppx ] ; \
	then \
		./$(problem)/answer.cppx ;\
	fi;
	if [ -a $(problem)/*.js ] ; \
	then \
		./$(problem)/answer.js ;\
	fi;
	if [ -a $(problem)/*.rb ] ; \
	then \
		./$(problem)/answer.rb ;\
	fi;
	if [ -a $(problem)/*.py ] ; \
	then \
		./$(problem)/answer.py ;\
	fi;
	if [ -a $(problem)/*.sh ] ; \
	then \
		./$(problem)/answer.sh ;\
	fi;
	if [ -a $(problem)/*.r ] ; \
	then \
		./$(problem)/answer.r ;\
	fi;
	if [ -a $(problem)/*.class ] ; \
	then \
		java -cp ./$(problem) answer ;\
	fi;
	if [ -a $(problem)/*x ] ; \
	then \
		rm $(problem)/*x ;\
	fi;
	if [ -a $(problem)/*.class ] ; \
	then \
		rm $(problem)/*class ;\
	fi;
cpp:
	g++ $(problem)/answer.cpp -o $(problem)/answer.cppx
java:
	javac $(problem)/answer.java
clean:
	if [ -a *~ ] ; \
	then \
		rm *~ ;\
	fi;
	if [ -a $(problem)/*~ ] ; \
	then \
		rm $(problem)/*~ ;\
	fi;
	if [ -a $(problem)/*x ] ; \
	then \
		rm $(problem)/*x ;\
	fi;
	if [ -a $(problem)/*# ] ; \
	then \
		rm $(problem)/*# ;\
	fi;
	if [ -a $(problem)/*class ] ; \
	then \
		rm $(problem)/*class ;\
	fi;
	clear
help:
	echo "USAGE: Make problem=###"
	echo "EXAMPLE: Make problem=001"
