#include <Rcpp.h>
using namespace Rcpp;

//' Calculate number of flat spots
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references  Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' longest_flat_spot(x)
//'
// [[Rcpp::export]]
double longest_flat_spot(NumericVector x){

  int n = x.size();
}
