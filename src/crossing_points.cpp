#include <Rcpp.h>
using namespace Rcpp;

//' Function to calculate number of crossing points
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' crossing_points(x)
//'
// [[Rcpp::export]]
int crossing_points(NumericVector x){

  // Compute median

  int n = x.size();
  double median;

  if (n == 0)
  {
    return 0;
  }
  else
  {
    std::sort(x.begin(), x.end());
    if (n % 2 == 0)
    {
      median = (x[n / 2 - 1] + x[n / 2]) / 2;
    }
    else
    {
      median = x[n / 2];
    }
  }

  // Get signature of whether each point is below or equal to median

  NumericVector ab(n);

  for (int i = 0; i < n; i++){
    if (x[i] <= median) {
      ab[i] = 1;
    } else{
      ab[i] = 0;
    }
  }

  // Compute from 1 to n-1

  NumericVector p1(n-1);

  for (int i = 0; i < n-1; i++){
    p1[i] = ab[i];
  }

  // Compute from 2 to n

  NumericVector p2(n-1);

  for (int i = 1; i < n; i++){
    p2[i] = ab[i];
  }

  // Assess differences

  NumericVector cross(n-1);

  for (int i = 1; i < n-1; i++){
    if (p1[i] != p2[i]) {
      cross[i] = 1;
    } else{
      cross[i] = 0;
    }
  }

  // Sum up crossing points

  int crossing_points;
  crossing_points = 0;

  for (int i=0; i < n; i++) {
    crossing_points += i;
  }

  return crossing_points;
}
