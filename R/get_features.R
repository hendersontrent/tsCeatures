#' Automatically run every time-series feature calculation in the package
#'
#' @importFrom stats median sd
#' @param x a numerical time-series vector
#' @return object of class DataFrame that contains the summary statistics for each feature
#' @author Trent Henderson
#' @export
#' @examples
#' x <- rnorm(100)
#' outs <- get_features(x)
#'

get_features <- function(x){

  if(anyNA(x) || !is.numeric(x)){
    stop("Input time series vector x should not have any missing or non-numeric values.")
  } else{

    outData <- data.frame(mean = mean(x, na.rm = TRUE),
                          median = stats::median(x, na.rm = TRUE),
                          sd = stats::sd(x, na.rm = TRUE),
                          min = min(x, na.rm = TRUE),
                          max = max(x, na.rm = TRUE),
                          ac_1 = ac_1(x),
                          ac_2 = ac_2(x),
                          crossing_points = crossing_points(x),
                          trev_num = trev_num(x),
                          quantile_5 = quantile_5(x),
                          quantile_10 = quantile_10(x),
                          quantile_25 = quantile_25(x),
                          quantile_75 = quantile_75(x),
                          quantile_90 = quantile_90(x),
                          quantile_95 = quantile_95(x),
                          prop_above_mean = prop_above_mean(x),
                          walker_propcross = walker_propcross(x))

    return(outData)
  }
}
