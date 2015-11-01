all:
	g++ $(problem)/answer.cpp -o $(problem)/answer.cppx
	javac $(problem)/answer.java
	./$(problem)/answer.cppx
	./$(problem)/answer.js
	./$(problem)/answer.rb
	./$(problem)/answer.py
	./$(problem)/answer.sh
	./$(problem)/answer.r
	java -cp ./$(problem) answer
	rm $(problem)/*x
	rm $(problem)/*class
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
