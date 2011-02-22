sync: doc
	make clean
	@echo `pwd`
	@rsync -r -t -u -v --delete \
	--include "makefile"        \
	--include "*.c++"           \
	--include "*.html"          \
	--exclude "*"               \
	. downing@$(OOPL):public_html/ni/quizzes/

%.app: %.c++
	g++ -ansi -pedantic -Wall $< -o $@

%.c++.html: %.c++
	code2html -l c++ $< $@

%.c++x: %.app %.c++.html
	$(patsubst %.c++x,%.app,$@)

clean:
	rm -f *.app

doc: $(patsubst %.c++,%.c++.html,$(wildcard *.c++))

scrub: clean
	rm -f *.html
