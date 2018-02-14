## -*- mode: autoconf; autoconf-indentation: 4; -*-
##
##  RcppArmadillo configure.ac
##
##  'Rcpp' Integration for the 'Armadillo' Templated Linear Algebra Library
##
##  Copyright (C) 2016 - 2017  Dirk Eddelbuettel
##
##  Licensed under GPL-2 or later
##  modified (/adapted/broken) by baptiste for testing purposes

## require at least autoconf 2.61
AC_PREREQ(2.61)

## Process this file with autoconf to produce a configure script.
AC_INIT(RcppArmadillo, m4_esyscmd_s([awk -e '/^Version:/ {print $2}' DESCRIPTION]))

## Set R_HOME, respecting an environment variable if one is set
: ${R_HOME=$(R RHOME)}
if test -z "${R_HOME}"; then
    AC_MSG_ERROR([Could not determine R_HOME.])
fi
## Use R to set CXX and CXXFLAGS
CXX=$(${R_HOME}/bin/R CMD config CXX)
CXXFLAGS=$("${R_HOME}/bin/R" CMD config CXXFLAGS)

## Check for suitable LAPACK_LIBS
AC_MSG_CHECKING([LAPACK_LIBS])

## external LAPACK has the required function
lapack=$(${R_HOME}/bin/R CMD config LAPACK_LIBS)
hasRlapack=$(echo ${lapack} | grep lRlapack)


if test x"${hasRlapack}" == x""; then
    ## We are using a full Lapack and can use zgesdd -- so #undef remains
    AC_MSG_RESULT([system LAPACK found])
    arma_lapack="#undef ARMA_CRIPPLED_LAPACK"
else
        ## We are using an older R's subset of Lapack and CANNOT use zgesdd etc, so we mark it
        AC_MSG_RESULT([R-supplied partial LAPACK found])
        AC_MSG_WARN([Some LAPACK functions may not be available])
        arma_lapack="#define ARMA_CRIPPLED_LAPACK 1"
fi


## now use all these
AC_SUBST([ARMA_LAPACK],["${arma_lapack}"])
