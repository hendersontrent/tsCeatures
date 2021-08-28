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

  int by = 10;
  int nRatio = (double(n) - 1) / double(by);
  NumericVector lo(nRatio + 1);

  int z = 0;
  for (double i = 1; i <= n; i = i + by) {
    lo[z] = i;
    z += 1;
  }

  int nRatio2 = ((double(n) + by) - double(by)) / double(by);
  NumericVector up(nRatio2 + 1);

  int z2 = 0;
  for (double i = by; i <= n + by; i = i + by) {
    up[z2] = i;
    z2 += 1;
  }

  // Segs

  int nsegs = n / by;
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

  if (n < 2*by) {
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
