AUTOMAKE_OPTIONS = foreign

check_PROGRAMS = funcA_test
funcA_test_SOURCES = main.cpp $(top_builddir)/FuncA.cpp $(top_builddir)/FuncA.h

TESTS = funcA_test

check-local: funcA_test
	./funcA_test

