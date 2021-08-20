#include <Rcpp.h>
using namespace Rcpp;

//' Function to calculate stability
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' stability(x)
//'
// [[Rcpp::export]]
double stability(NumericVector x){

  int n = x.size();
}
