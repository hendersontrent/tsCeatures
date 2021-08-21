#' Automatically run every time-series feature calculation in the package
#'
#' @importFrom stats median sd
#' @param x a numerical time-series input vector
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
                          ac_1 = ac_1(x),
                          ac_2 = ac_2(x),
                          crossing_points = crossing_points(x))

    return(outData)
  }
}
