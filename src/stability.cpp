#include <Rcpp.h>
using namespace Rcpp;

//' Calculate stability which is the variance of tiled window means
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references  Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' stability(x)
//'
// [[Rcpp::export]]
double stability(NumericVector x){

  int n = x.size();
  NumericVector x1(n);
  double total = 0;
  double total_sd = 0;
  double mu;
  double sigma;

  // Compute mean

  for(int i = 0; i < n; ++i) {
    total += x[i];
  }

  mu = total / n;

  // Compute SD

  for(int i = 0; i < n; ++i) {
    total_sd += (x[i]-mu)*(x[i]-mu);
  }

  sigma = std::sqrt((total_sd/n));

  // Scale time series using z-score formula

  for(int i = 0; i < n; ++i) {
    x1[i] = ((x[i]-mu)/sigma);
  }

  // Width routine

  int width = 0;

  NumericVector lo(n);
  NumericVector up(n);

  // Segs

  int nsegs = n / width;

  // Variance of x

  NumericVector varx(nsegs);

  // Compute stability

  double stability;

  if (n < 2*width) {
    stability = 0;
  } else {
    double total_var = 0;

    for(int i = 0; i < n; ++i) {
      x1[i] = ((x[i]-mu)*(x[i]-mu));
    }

    stability = total_var/n-1;
  }

  return stability;
}
