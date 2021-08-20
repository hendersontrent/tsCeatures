#include <Rcpp.h>
using namespace Rcpp;

//' Function to calculate lumpiness
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' lumpiness(x)
//'
// [[Rcpp::export]]
double lumpiness(NumericVector x){

  int n = x.size();
}
