#include <Rcpp.h>
using namespace Rcpp;

//' Calculate Quantile 5
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_5(x)
//'
// [[Rcpp::export]]
double quantile_5(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.05);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}

//' Calculate Quantile 10
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_10(x)
//'
// [[Rcpp::export]]
double quantile_10(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.1);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}

//' Calculate Quantile 25
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_25(x)
//'
// [[Rcpp::export]]
double quantile_25(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.25);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}

//' Calculate Quantile 75
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_75(x)
//'
// [[Rcpp::export]]
double quantile_75(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.75);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}

//' Calculate Quantile 90
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_90(x)
//'
// [[Rcpp::export]]
double quantile_90(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.90);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}

//' Calculate Quantile 95
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' quantile_95(x)
//'
// [[Rcpp::export]]
double quantile_95(NumericVector x){

  int n = x.size();
  double rank;
  int pos_ind;
  double quantile;

  // Compute rank of quantile value

  rank = n*(0.95);
  pos_ind = std::round(rank);

  // Index original vector to get the value

  quantile = x[pos_ind];
  return(quantile);
}
