#include <Rcpp.h>
using namespace Rcpp;

//' Calculate lumpiness which is the variance of tiled window variances
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references  Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' lumpiness(x)
//'
// [[Rcpp::export]]
double lumpiness(NumericVector x){

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

  // Width routines

  int width = 10; // Fix to 10 as pkg assumes uniform sampling (10 matches {tsfeatures})

  IntegerVector lo(n);
  IntegerVector up(n);

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      lo[i] = 1;
    } else{
      lo[i] = lo[i-1]+10;
    }
  }

  for (int i = 0; i < n+width; ++i) {
    if (i == 0) {
      up[i] = 10;
    } else{
      up[i] = up[i-1]+10;
    }
  }

  // Segs

  int nsegs = n / width;

  // Variance of x

  NumericVector varx(nsegs);

  for(int i = 0; i < nsegs; ++i) {

    x1[i] = ((x[i]-mu)/sigma);

  }

  // Compute lumpiness

  double lumpiness;

  if (n < 2*width) {
    lumpiness = 0;
  } else {
    double total_var = 0;

    for(int i = 0; i < n; ++i) {
      x1[i] = ((x[i]-mu)*(x[i]-mu));
    }

    lumpiness = total_var/n-1;
  }

  return lumpiness;
}
