CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type -Werror=uninitialized # --coverage
# Do not allow compiling if a non-void function is missing a return statement
# Do not allow compiling if a variable is used without being initialized

OBJECTS = main.o processStrings.o
# TESTS = test-1-hashtable test-2-hashtable test-3-passserver
# CATCH = test/catch/catch.o

main: $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.dSYM test/*.dSYM
	rm -f ds?.txt 
	rm -f ds??.txt
	rm -f ds???.txt
	rm -f *.o *.gc* test/*.o test/*.gc* *.dSYM *.pdb *.obj $(addprefix test/,$(TESTS)) main $(CATCH)

#$(TESTS): $(CATCH)
#	$(CXX) $(CXXFLAGS) -o test/$@ $^
#	test/$@ --success "$(SUB_TEST)"
