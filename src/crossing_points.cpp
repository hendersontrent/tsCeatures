#include <Rcpp.h>
using namespace Rcpp;

//' Function to calculate number of crossing points
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100, 0, 1)
//' crossing_points(x)
//'
// [[Rcpp::export]]
NumericVector crossing_points(NumericVector x){

  float mean;
  int sum, i;
  int n = x.size();

  sum = 0;

  for(i = 0; i < n; i++) {
    sum+=x[i];
  }

  mean = sum/n
  return mean;
}
