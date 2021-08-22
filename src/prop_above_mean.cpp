#include <Rcpp.h>
using namespace Rcpp;

//' Calculate proportion of points above the mean, as per binarize_mean from the MATLAB toolbox \code{hctsa}
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references B.D. Fulcher and N.S. Jones. hctsa: A computational framework for automated time-series phenotyping using massive feature extraction. Cell Systems 5, 527 (2017).
//' @references B.D. Fulcher, M.A. Little, N.S. Jones Highly comparative time-series analysis: the empirical structure of time series and their methods. J. Roy. Soc. Interface 10, 83 (2013).
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' prop_above_mean(x)
//'
// [[Rcpp::export]]
double prop_above_mean(NumericVector x){

  int n = x.size();
  double total = 0;
  double mean;

  // Compute mean

  for (int i = 0; i < n; ++i) {
    total += x[i];
  }

  mean = total / n;

  // Subtract mean from each point to see if above or below

  NumericVector xsub(n);

  for (int i = 0; i < n; ++i) {
    xsub[i] = x[i]-mean;
  }

  // Binarize vector into whether each value is above or below mean

  IntegerVector xbin(n);

  for (int i = 0; i < n; ++i) {
    if (xsub[i] > 0){
      xbin[i] = 1;
    } else {
      xbin[i] = 0;
    }
  }

  // Count the number of points above the mean

  int sum = 0;

  for (int i = 0; i < n; ++i) {
    sum += xbin[i];
  }

  // Convert to proportion and return

  double prop_above_mean = double(sum) / double(n);
  return prop_above_mean;
}
