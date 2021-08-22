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
    x[i] = ((x[i]-mu)/sigma);
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
  int nlength = up[1]-lo[1];

  // Variance of each sliding window

  NumericVector total_var(nsegs);
  NumericVector total_var_sum(nsegs);
  NumericVector mean(nsegs);
  NumericVector varx(nsegs);

  for (int i = 0; i < nsegs; i++) {

    total_var[i] = 0;
    mean[i] = 0;

    // Compute tiled window metrics

    for (int k = lo[i]; k < up[i]; ++k){
      total_var[i] += x[k];
    }

    mean[i] = total_var[i]/nlength;

    // Compute variance

    for (int k = lo[i]; k < up[i]; ++k){
      total_var_sum[i] += (x[k]-mean[i])*(x[k]-mean[i]);
    }

    varx[i] = total_var_sum[i]/(nlength-1);
  }

  // Compute lumpiness

  double lumpiness;

  if (n < 2*width) {
    lumpiness = 0;
  } else {
    double total_lump = 0;
    double mean_lump;
    double var_lump = 0;

    // Compute mean

    for(int i = 0; i < nsegs; ++i) {
      total_lump += varx[i];
    }

    mean_lump = total_lump/nsegs;

    for(int i = 0; i < nsegs; ++i) {
      var_lump += (varx[i]-mean_lump)*(varx[i]-mean_lump);
    }

    lumpiness = var_lump/n-1;
  }

  return lumpiness;
}
