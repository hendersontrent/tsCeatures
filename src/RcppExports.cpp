// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// ac_1
double ac_1(NumericVector x);
RcppExport SEXP _tsCeatures_ac_1(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(ac_1(x));
    return rcpp_result_gen;
END_RCPP
}
// ac_2
double ac_2(NumericVector x);
RcppExport SEXP _tsCeatures_ac_2(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(ac_2(x));
    return rcpp_result_gen;
END_RCPP
}
// crossing_points
int crossing_points(NumericVector x);
RcppExport SEXP _tsCeatures_crossing_points(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(crossing_points(x));
    return rcpp_result_gen;
END_RCPP
}
// flat_spots
double flat_spots(NumericVector x);
RcppExport SEXP _tsCeatures_flat_spots(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(flat_spots(x));
    return rcpp_result_gen;
END_RCPP
}
// lumpiness
double lumpiness(NumericVector x);
RcppExport SEXP _tsCeatures_lumpiness(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(lumpiness(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_5
double quantile_5(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_5(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_5(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_10
double quantile_10(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_10(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_10(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_25
double quantile_25(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_25(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_25(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_75
double quantile_75(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_75(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_75(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_90
double quantile_90(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_90(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_90(x));
    return rcpp_result_gen;
END_RCPP
}
// quantile_95
double quantile_95(NumericVector x);
RcppExport SEXP _tsCeatures_quantile_95(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_95(x));
    return rcpp_result_gen;
END_RCPP
}
// stability
double stability(NumericVector x);
RcppExport SEXP _tsCeatures_stability(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(stability(x));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_tsCeatures_ac_1", (DL_FUNC) &_tsCeatures_ac_1, 1},
    {"_tsCeatures_ac_2", (DL_FUNC) &_tsCeatures_ac_2, 1},
    {"_tsCeatures_crossing_points", (DL_FUNC) &_tsCeatures_crossing_points, 1},
    {"_tsCeatures_flat_spots", (DL_FUNC) &_tsCeatures_flat_spots, 1},
    {"_tsCeatures_lumpiness", (DL_FUNC) &_tsCeatures_lumpiness, 1},
    {"_tsCeatures_quantile_5", (DL_FUNC) &_tsCeatures_quantile_5, 1},
    {"_tsCeatures_quantile_10", (DL_FUNC) &_tsCeatures_quantile_10, 1},
    {"_tsCeatures_quantile_25", (DL_FUNC) &_tsCeatures_quantile_25, 1},
    {"_tsCeatures_quantile_75", (DL_FUNC) &_tsCeatures_quantile_75, 1},
    {"_tsCeatures_quantile_90", (DL_FUNC) &_tsCeatures_quantile_90, 1},
    {"_tsCeatures_quantile_95", (DL_FUNC) &_tsCeatures_quantile_95, 1},
    {"_tsCeatures_stability", (DL_FUNC) &_tsCeatures_stability, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_tsCeatures(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
