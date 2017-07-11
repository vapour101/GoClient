TESTS = unitTests

GTEST_INCLUDES = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

check_LTLIBRARIES = libgtest.la
check_PROGRAMS = unitTests

#libgtest_la_SOURCES cannot contain any make variables in the path, automake doesn't like it.
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = $(GTEST_INCLUDES)
libgtest_la_LDFLAGS = -pthread

unitTests_SOURCES = gtest_main.cxx coords_test.cxx ../src/game-logic/coords.cxx
unitTests_LDADD = libgtest.la
unitTests_LDFLAGS = -pthread
unitTests_CPPFLAGS = $(GTEST_INCLUDES)
