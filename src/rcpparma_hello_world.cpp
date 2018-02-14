// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-

// we only include RcppArmadillo.h which pulls Rcpp.h in for us
#include "config.h"
#include "RcppArmadillo.h"

// via the depends attribute we tell Rcpp to create hooks for
// RcppArmadillo so that the build process will know what to do
//
// [[Rcpp::depends(RcppArmadillo)]]

// simple example of creating two matrices and
// returning the result of an operatioon on them
//
// via the exports attribute we tell Rcpp to make this function
// available from R
//
// [[Rcpp::export]]
arma::cx_mat solve_dummy() {
    arma::cx_mat m1 = arma::eye<arma::cx_mat>(10, 10);
    arma::cx_mat m2 = arma::eye<arma::cx_mat>(10, 10);
	                    
    return solve(m1,m2);
}
