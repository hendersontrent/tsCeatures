#include <Rcpp.h>
using namespace Rcpp;

//' Calculate proportion of length that walker crosses time series, as per PH_Walker_prop_01_sw_propcross from the MATLAB toolbox \code{hctsa}
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references B.D. Fulcher and N.S. Jones. hctsa: A computational framework for automated time-series phenotyping using massive feature extraction. Cell Systems 5, 527 (2017).
//' @references B.D. Fulcher, M.A. Little, N.S. Jones Highly comparative time-series analysis: the empirical structure of time series and their methods. J. Roy. Soc. Interface 10, 83 (2013).
//' @references  Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' walker_propcross(x)
//'
// [[Rcpp::export]]
double walker_propcross(NumericVector x){

  int n = x.size();
  double p = 0.1; // For 10% parameter

  // Simulate walker

  NumericVector w(n);
  w[0] = 0;

  for (int i = 1; i < n; ++i) {
    w[i] = w[i-1] + p * (x[i-1] - w[i-1]);
  }

  // Do operation part 1

  NumericVector w1(n-1);

  for (int i = 0; i < n-1; ++i) {
    w1[i] = w[i]-x[i];
  }

  // Do operation part 2

  NumericVector w2(n-1);

  for (int i = 1; i < n; ++i) {
    w2[i-1] = w[i]-x[i];
  }

  // Multiply 2 parts

  NumericVector wmul(n-1);

  for (int i = 0; i < n-1; ++i) {
    wmul[i] = w1[i]*w2[i];
  }

  // Binarize if less than zero

  IntegerVector wbin(n-1);

  for (int i = 0; i < n-1; ++i) {
    if (wmul[i] < 0){
      wbin[i] = 1;
    } else {
      wbin[i] = 0;
    }
  }

  // Calculate proportion

  int total = 0;

  for (int i = 0; i < n-1; ++i) {
    total += wbin[i];
  }

  double prop_cross = double(total)/(double(n-1));
  return prop_cross;
}
