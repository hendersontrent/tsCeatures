#include <Rcpp.h>
using namespace Rcpp;

//' Calculate autocorrelation function at lag 1
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' ac_1(x)
//'
// [[Rcpp::export]]
double ac_1(NumericVector x){

  int n = x.size();
}

//' Calculate autocorrelation function at lag 2
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' ac_2(x)
//'
// [[Rcpp::export]]
double ac_2(NumericVector x){

  int n = x.size();
}
