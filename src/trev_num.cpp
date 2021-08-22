#include <Rcpp.h>
using namespace Rcpp;

//' Calculate numerator of the trev function from the MATLAB toolbox \code{hctsa}
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references B.D. Fulcher and N.S. Jones. hctsa: A computational framework for automated time-series phenotyping using massive feature extraction. Cell Systems 5, 527 (2017).
//' @references B.D. Fulcher, M.A. Little, N.S. Jones Highly comparative time-series analysis: the empirical structure of time series and their methods. J. Roy. Soc. Interface 10, 83 (2013).
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' trev_num(x)
//'
// [[Rcpp::export]]
double trev_num(NumericVector x){

  int n = x.size();
  NumericVector xn(n-1);
  NumericVector xn1(n-1);

  // Get n-1 vector

  for (int i = 0; i < n-1; ++i) {
    xn[i] = x[i];
  }

  // Get n+1:n vector

  for (int i = 1; i < n; ++i) {
    xn[i] = x[i];
  }

  // Calculate differences

  NumericVector diffs(n-1);

  for (int i = 0; i < n-1; ++i) {
    diffs[i] = x[i];
  }

  // Calculate cubed differences

  NumericVector cubedDiff(n-1);

  for (int i = 0; i < n-1; ++i) {
    cubedDiff[i] = diffs[i]*diffs[i]*diffs[i];
  }

  // Compute mean of the cubed difference for the final trev function numerator

  double trev_num;
  double total = 0;

  for (int i = 0; i < n-1; ++i) {
    total += cubedDiff[i];
  }

  trev_num = total / n-1;
  return trev_num;
}
