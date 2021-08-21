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
  double total = 0;
  double autocovariance = 0;
  double variance = 0;
  double mean, acf;

  // Compute mean

  for (int i = 0; i < n; ++i) {
    total += x[i];
  }

  mean = total / n;

  // Compute lag covariance

  for (int i = 0; i < n-1; i++) {
    autocovariance += (x[i]-mean)*(x[i+1]-mean);
  }

  // Compute variance

  for (int i = 0; i < n; i++) {
    variance += (x[i]-mean)*(x[i]-mean);
  }

  // Return autocorrelation function

  acf = autocovariance/variance;
  return acf;
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
  double total = 0;
  double autocovariance = 0;
  double variance = 0;
  double mean, acf;

  // Compute mean

  for (int i = 0; i < n; ++i) {
    total += x[i];
  }

  mean = total / n;

  // Compute lag covariance

  for (int i = 0; i < n-2; i++) {
    autocovariance += (x[i]-mean)*(x[i+2]-mean);
  }

  // Compute variance

  for (int i = 0; i < n; i++) {
    variance += (x[i]-mean)*(x[i]-mean);
  }

  // Return autocorrelation function

  acf = autocovariance/variance;
  return acf;
}
