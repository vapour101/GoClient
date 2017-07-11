ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = src/main
src_main_SOURCES = src/main.cxx

doc_DATA = COPYING INSTALL README.md
EXTRA_DIST = README.md googletest/googletest/LICENSE

#TESTS
TESTS = tests/unitTests

#Source files included by gtest-all.cc
GTEST_SRC = \
  googletest/googletest/src/gtest-death-test.cc \
  googletest/googletest/src/gtest-filepath.cc \
  googletest/googletest/src/gtest-internal-inl.h \
  googletest/googletest/src/gtest-port.cc \
  googletest/googletest/src/gtest-printers.cc \
  googletest/googletest/src/gtest-test-part.cc \
  googletest/googletest/src/gtest-typed-test.cc \
  googletest/googletest/src/gtest.cc
EXTRA_DIST += $(GTEST_SRC)

#Header files required to run unit tests, but not to be installed
GTEST_HEADER_FILES = \
  googletest/googletest/include/gtest/gtest-death-test.h \
  googletest/googletest/include/gtest/gtest-message.h \
  googletest/googletest/include/gtest/gtest-param-test.h \
  googletest/googletest/include/gtest/gtest-printers.h \
  googletest/googletest/include/gtest/gtest-spi.h \
  googletest/googletest/include/gtest/gtest-test-part.h \
  googletest/googletest/include/gtest/gtest-typed-test.h \
  googletest/googletest/include/gtest/gtest.h \
  googletest/googletest/include/gtest/gtest_pred_impl.h \
  googletest/googletest/include/gtest/gtest_prod.h \
  googletest/googletest/include/gtest/internal/gtest-death-test-internal.h \
  googletest/googletest/include/gtest/internal/gtest-filepath.h \
  googletest/googletest/include/gtest/internal/gtest-internal.h \
  googletest/googletest/include/gtest/internal/gtest-linked_ptr.h \
  googletest/googletest/include/gtest/internal/gtest-param-util-generated.h \
  googletest/googletest/include/gtest/internal/gtest-param-util.h \
  googletest/googletest/include/gtest/internal/gtest-port.h \
  googletest/googletest/include/gtest/internal/gtest-port-arch.h \
  googletest/googletest/include/gtest/internal/gtest-string.h \
  googletest/googletest/include/gtest/internal/gtest-tuple.h \
  googletest/googletest/include/gtest/internal/gtest-type-util.h \
  googletest/googletest/include/gtest/internal/custom/gtest.h \
  googletest/googletest/include/gtest/internal/custom/gtest-port.h \
  googletest/googletest/include/gtest/internal/custom/gtest-printers.h
EXTRA_DIST += $(GTEST_HEADER_FILES)

GTEST_INCLUDES = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

check_LTLIBRARIES = libgtest.la
check_PROGRAMS = tests/unitTests

libgtest_la_SOURCES = googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = $(GTEST_INCLUDES)
libgtest_la_LDFLAGS = -pthread

tests_unitTests_SOURCES = \
  tests/gtest_main.cxx \
  src/common/constants.hxx \
  tests/coords_test.cxx src/game-logic/coords.cxx src/game-logic/coords.hxx \
  tests/board_test.cxx src/game-logic/board.cxx src/game-logic/board.hxx
tests_unitTests_LDADD = libgtest.la
tests_unitTests_LDFLAGS = -pthread
tests_unitTests_CPPFLAGS = $(GTEST_INCLUDES) -I$(top_srcdir)/src
