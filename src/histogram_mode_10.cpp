#include <Rcpp.h>
using namespace Rcpp;

//' Calculate mode of 10-binned histogram of the data vector similar to DN_HistogramMode_10 from the MATLAB toolbox \code{hctsa}
//'
//' @param x a numerical time-series input vector
//' @return scalar value
//' @references B.D. Fulcher and N.S. Jones. hctsa: A computational framework for automated time-series phenotyping using massive feature extraction. Cell Systems 5, 527 (2017).
//' @references B.D. Fulcher, M.A. Little, N.S. Jones Highly comparative time-series analysis: the empirical structure of time series and their methods. J. Roy. Soc. Interface 10, 83 (2013).
//' @author Trent Henderson
//' @export
//' @examples
//' x <- rnorm(100)
//' histogram_mode_10(x)
//'
// [[Rcpp::export]]
double histogram_mode_10(NumericVector x){

  int n = x.size();
  int nBins = 10;
  double min1 = min(x);
  double max1 = max(x);
  NumericVector binEdges(nBins);
  double step = (max1 - min1) / (nBins - 1);
  size_t i = 0;

  // Get bin edges

  for (auto& e : binEdges) {
    e = min1 + step * i++;
  }

  // Calculate the sum of all values in each bin

  NumericVector binCounts(nBins);
  binCounts[0] = 0;
  binCounts[1] = 0;
  binCounts[2] = 0;
  binCounts[3] = 0;
  binCounts[4] = 0;
  binCounts[5] = 0;
  binCounts[6] = 0;
  binCounts[7] = 0;
  binCounts[8] = 0;
  binCounts[9] = 0;

  for (int i = 0; i < n; ++i) {
    if (x[i] <= binEdges[0]) {
      binCounts[0] += 1;
    } else if (x[i] > binEdges[0] && x[i] < binEdges[1]) {
      binCounts[1] += 1;
    } else if (x[i] > binEdges[1] && x[i] < binEdges[2]) {
      binCounts[2] += 1;
    } else if (x[i] > binEdges[2] && x[i] < binEdges[3]) {
      binCounts[3] += 1;
    } else if (x[i] > binEdges[3] && x[i] < binEdges[4]) {
      binCounts[4] += 1;
    } else if (x[i] > binEdges[4] && x[i] < binEdges[5]) {
      binCounts[5] += 1;
    } else if (x[i] > binEdges[5] && x[i] < binEdges[6]) {
      binCounts[6] += 1;
    } else if (x[i] > binEdges[6] && x[i] < binEdges[7]) {
      binCounts[7] += 1;
    } else if (x[i] > binEdges[7] && x[i] < binEdges[8]) {
      binCounts[8] += 1;
    } else {
      binCounts[9] += 1;
    }
  }

  // Compute bin centres from edges

  NumericVector binCentres(nBins-1);
  double binCentre_total = 0;

  for (int i = 0; i < nBins-1; ++i) {
    binCentre_total += binCentres[i];
  }

  //binCentres

  // Compute mean position of the maximums to account for multiples

  double binMax_total = 0;

  for (int i = 0; i < nBins-1; ++i) {
    binMax_total += binCentres[i];
  }

  double binMax = binMax_total / (n-1);
  return binMax;
}
