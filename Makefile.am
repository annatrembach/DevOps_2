AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = funcA
funcA_SOURCES = main.cpp FuncA.cpp FuncA.h
dist_man_MANS = funcA.1

SUBDIRS = tests

.PHONY: deb
deb:
	make DESTDIR=$(CURDIR)/deb install

