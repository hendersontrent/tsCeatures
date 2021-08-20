#' Automatically run every time-series feature calculation in the package
#'
#' @param data a numerical time-series input vector
#' @return object of class DataFrame that contains the summary statistics for each feature
#' @author Trent Henderson
#' @export
#' @examples
#' x <- rnorm(100)
#' outs <- compute_tsCeatures(x)
#'

compute_tsCeatures <- function(x){

  names <- c('mean',
             'median',
             'sd',
             'crossing_points',
             'quantile_1',
             'quantile_5',
             'quantile_10',
             'quantile_25',
             'quantile_75',
             'quantile_90',
             'quantile_95',
             'quantile_99',
             'ac_1',
             'ac_2',
             'lumpiness',
             'stability',
             'flat_spots')

  values = c()

  for (feature in names){
    fh = get(feature);
    values = append(values, fh(x))
  }

  outData = data.frame(names = names, values = values)

  return(outData)
}
