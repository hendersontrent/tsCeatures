% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{crossing_points}
\alias{crossing_points}
\title{Calculate number of crossing points}
\usage{
crossing_points(x)
}
\arguments{
\item{x}{a numerical time-series input vector}
}
\value{
scalar value
}
\description{
Calculate number of crossing points
}
\examples{
x <- rnorm(100)
crossing_points(x)

}
\references{
Rob Hyndman, Yanfei Kang, Pablo Montero-Manso, Thiyanga Talagala, Earo Wang, Yangzhuoran Yang and Mitchell O'Hara-Wild (2020). tsfeatures: Time Series Feature Extraction. R package version 1.0.2. https://CRAN.R-project.org/package=tsfeatures
}
\author{
Trent Henderson
}
