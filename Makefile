.PHONY: all clean

all: ccat test

ccat: ccat.cpp
	g++ -o ccat ccat.cpp

test: ccat
	./ccat tests/test.txt tests/test2.txt > test_output.txt
	sed G tests/test.txt | ./ccat -n | head >> test_output.txt
	sed G tests/test.txt | ./ccat -b | head -n5 >> test_output.txt
	@diff test_output.txt tests/reference.txt > /dev/null 2>&1; \
	RESULT=$$?; \
	if [ $$RESULT -eq 0 ]; then \
	    echo "Tests passed"; \
	else \
	    echo "Tests failed:"; \
	    diff test_output.txt tests/reference.txt; \
	    exit $$RESULT; \
	fi

clean:
	rm -f ccat test_output.txt