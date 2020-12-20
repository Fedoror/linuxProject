#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([linuxProject], [0.01], [vvdsfd@gmail.ru])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_SRCDIR([Unity/examples/unity_config.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([limits.h stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strstr])

AC_CONFIG_FILES([Unity/examples/example_1/makefile
                 Unity/examples/example_2/makefile
                 Unity/extras/fixture/test/Makefile
                 Unity/extras/memory/test/Makefile
                 Unity/test/Makefile
                 src/Makefile])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
