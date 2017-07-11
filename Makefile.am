ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = src/main
src_main_SOURCES = src/main.cxx

doc_DATA = COPYING INSTALL README.md
EXTRA_DIST = README.md googletest/googletest/LICENSE

#TESTS
TESTS = tests/unitTests

GTEST_INCLUDES = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

check_LTLIBRARIES = libgtest.la
check_PROGRAMS = tests/unitTests

libgtest_la_SOURCES = googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = $(GTEST_INCLUDES)
libgtest_la_LDFLAGS = -pthread

tests_unitTests_SOURCES = tests/gtest_main.cxx \
                          tests/coords_test.cxx src/game-logic/coords.cxx \
                          tests/board_test.cxx src/game-logic/board.cxx
tests_unitTests_LDADD = libgtest.la
tests_unitTests_LDFLAGS = -pthread
tests_unitTests_CPPFLAGS = $(GTEST_INCLUDES) -I$(top_srcdir)/src
