// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// fullmodel
Rcpp::List fullmodel(const Eigen::VectorXd& y, const Eigen::MatrixXd& d, const double& epsilon, const unsigned int& h);
RcppExport SEXP _LocallyStationaryModels_fullmodel(SEXP ySEXP, SEXP dSEXP, SEXP epsilonSEXP, SEXP hSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type h(hSEXP);
    rcpp_result_gen = Rcpp::wrap(fullmodel(y, d, epsilon, h));
    return rcpp_result_gen;
END_RCPP
}
// rcppeigen_add22
Rcpp::List rcppeigen_add22(const Eigen::MatrixXd& x, const Eigen::MatrixXd& y);
RcppExport SEXP _LocallyStationaryModels_rcppeigen_add22(SEXP xSEXP, SEXP ySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type y(ySEXP);
    rcpp_result_gen = Rcpp::wrap(rcppeigen_add22(x, y));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_LocallyStationaryModels_fullmodel", (DL_FUNC) &_LocallyStationaryModels_fullmodel, 4},
    {"_LocallyStationaryModels_rcppeigen_add22", (DL_FUNC) &_LocallyStationaryModels_rcppeigen_add22, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_LocallyStationaryModels(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
