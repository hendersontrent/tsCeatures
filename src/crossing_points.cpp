#include <Rcpp.h>
using namespace Rcpp;

//' Calculate number of crossing points
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references  Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
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
  NumericVector x_sort = x;
  double median;

  if (n == 0)
  {
    return 0;
  }
  else
  {
    std::sort(x_sort.begin(), x_sort.end());
    if (n % 2 == 0)
    {
      median = (x_sort[n / 2 - 1] + x_sort[n / 2]) / 2;
    }
    else
    {
      median = x_sort[n / 2];
    }
  }

  // Get signature of whether each point is below or equal to median

  IntegerVector ab(n);

  for (int i = 0; i < n; i++){
    if (x[i] <= median) {
      ab[i] = 1;
    } else{
      ab[i] = 0;
    }
  }

  // Compute from 1 to n-1

  IntegerVector p1(n-1);

  for (int i = 0; i < n-1; i++){
    p1[i] = ab[i];
  }

  // Compute from 2 to n

  IntegerVector p2(n-1);

  for (int i = 1; i < n; i++){
    p2[i] = ab[i];
  }

  // Assess differences

  IntegerVector cross(n-1);

  for (int i = 0; i < n-1; i++){
    if (p1[i] != p2[i]) {
      cross[i] = 1;
    } else{
      cross[i] = 0;
    }
  }

  // Sum up crossing points

  int crossing_points = 0;

  for (int i = 0; i < n-1; i++) {
    crossing_points += cross[i];
  }

  return crossing_points;
}
