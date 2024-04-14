
new:
	flex -o scanner.cpp scanner.l
	bison -d -o parser.cpp parser.y
	g++ -g main.cpp parser.cpp scanner.cpp tree.hpp -o parse
	./parse <test.py>test.gv
	dot -Tpng -otree.png test.gv

run:
	./parse < ../tests/test1.py >test1.gv
	dot -Tpng -otree1.png test1.gv
	./parse < ../tests/test2.py >test2.gv
	dot -Tpng -otree2.png test2.gv
	./parse < ../tests/test3.py >test3.gv
	dot -Tpng -otree3.png test3.gv
	./parse < ../tests/test4.py >test4.gv
	dot -Tpng -otree4.png test4.gv
	./parse < ../tests/test5.py >test5.gv
	dot -Tpng -otree5.png test5.gv
