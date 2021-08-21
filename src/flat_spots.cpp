#include <Rcpp.h>
using namespace Rcpp;

//' Calculate number of flat spots
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' flat_spots(x)
//'
// [[Rcpp::export]]
double flat_spots(NumericVector x){

  int n = x.size();
}
