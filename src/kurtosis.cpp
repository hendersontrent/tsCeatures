#include <Rcpp.h>
using namespace Rcpp;

//' Calculate tailedness of the value distribution
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' kurtosis(x)
//'
// [[Rcpp::export]]
double kurtosis(NumericVector x){

  int n = x.size();
  double total = 0;
  double mean;

  // Calculate mean

  for (int i = 0; i < n; ++i) {
    total += x[i];
  }

  mean = total / n;

  // Calculate fourth moment

  double moment4 = 0;

  for (int i = 0; i < n; ++i) {
    moment4 += (x[i]-mean)*(x[i]-mean)*(x[i]-mean)*(x[i]-mean);
  }

  // Calculate second moment

  double moment2 = 0;

  for (int i = 0; i < n; ++i) {
    moment2 += (x[i]-mean)*(x[i]-mean);
  }

  // Calculate kurtosis

  double r = n * moment4 / (moment2*moment2);
  double kurtosis = r * ((1 - 1 / n) * (1 - 1 / n)) - 3;
  return kurtosis;
}
