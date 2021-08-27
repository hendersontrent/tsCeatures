#include <Rcpp.h>
using namespace Rcpp;

//' Calculate adjusted Fisher-Pearson coefficient of skewness
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' skewness(x)
//'
// [[Rcpp::export]]
double skewness(NumericVector x){

  int n = x.size();
  double total = 0;
  double mean;

  // Calculate mean

  for (int i = 0; i < n; ++i) {
    total += x[i];
  }

  mean = total / n;

  // Calculate standard deviation

  double total_sd = 0;
  double sigma;

  for(int i = 0; i < n; ++i) {
    total_sd += (x[i]-mean)*(x[i]-mean);
  }

  sigma = std::sqrt((total_sd/n));

  // Calculate G

  double G = std::sqrt((n*(n-1)))/(n-2);

  // Calculate skewness

  double total_skew = 0;

  for (int i = 0; i < n; ++i) {
    total_skew += ((x[i]-mean)*(x[i]-mean)*(x[i]-mean))/n;
  }

  double skewness = total_skew/(sigma*sigma*sigma);

  // Adjust skewness

  double adj_skewness = G * skewness;
  return adj_skewness;
}
