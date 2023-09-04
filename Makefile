COMPILE = g++ -Wall -Werror -std=c++11

all:
	@echo "\t make <program>"

%: %.cpp
	$(COMPILE) $< -o $@+

clean: 
	-@rm -f */*/*+ */*+ *+ *.txt
