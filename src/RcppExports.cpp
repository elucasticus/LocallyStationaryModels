// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// find_anchorpoints
Rcpp::List find_anchorpoints(const Eigen::MatrixXd& d, const unsigned int& n_cubotti);
RcppExport SEXP _LocallyStationaryModels_find_anchorpoints(SEXP dSEXP, SEXP n_cubottiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type n_cubotti(n_cubottiSEXP);
    rcpp_result_gen = Rcpp::wrap(find_anchorpoints(d, n_cubotti));
    return rcpp_result_gen;
END_RCPP
}
// variogramlsm
Rcpp::List variogramlsm(const Eigen::VectorXd& y, const Eigen::MatrixXd& d, const Eigen::MatrixXd& anchorpoints, const double& epsilon, const unsigned int& n_angles, const unsigned int& n_intervals, const std::string& kernel_id);
RcppExport SEXP _LocallyStationaryModels_variogramlsm(SEXP ySEXP, SEXP dSEXP, SEXP anchorpointsSEXP, SEXP epsilonSEXP, SEXP n_anglesSEXP, SEXP n_intervalsSEXP, SEXP kernel_idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type anchorpoints(anchorpointsSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type n_angles(n_anglesSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type n_intervals(n_intervalsSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type kernel_id(kernel_idSEXP);
    rcpp_result_gen = Rcpp::wrap(variogramlsm(y, d, anchorpoints, epsilon, n_angles, n_intervals, kernel_id));
    return rcpp_result_gen;
END_RCPP
}
// findsolutionslsm
Rcpp::List findsolutionslsm(const Eigen::MatrixXd& anchorpoints, const Eigen::MatrixXd& empiricvariogram, const Eigen::MatrixXd& squaredweights, const Eigen::VectorXd& x, const Eigen::VectorXd& y, std::string& variogram_id, const std::string& kernel_id, const Eigen::VectorXd& parameters, const double& epsilon);
RcppExport SEXP _LocallyStationaryModels_findsolutionslsm(SEXP anchorpointsSEXP, SEXP empiricvariogramSEXP, SEXP squaredweightsSEXP, SEXP xSEXP, SEXP ySEXP, SEXP variogram_idSEXP, SEXP kernel_idSEXP, SEXP parametersSEXP, SEXP epsilonSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type anchorpoints(anchorpointsSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type empiricvariogram(empiricvariogramSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type squaredweights(squaredweightsSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type y(ySEXP);
    Rcpp::traits::input_parameter< std::string& >::type variogram_id(variogram_idSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type kernel_id(kernel_idSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type parameters(parametersSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsilon(epsilonSEXP);
    rcpp_result_gen = Rcpp::wrap(findsolutionslsm(anchorpoints, empiricvariogram, squaredweights, x, y, variogram_id, kernel_id, parameters, epsilon));
    return rcpp_result_gen;
END_RCPP
}
// predikt
Rcpp::List predikt(const Eigen::VectorXd& y, const Eigen::MatrixXd& d, const Eigen::MatrixXd& anchorpoints, const double& epsilon, const double& delta, const Eigen::MatrixXd& solutions, const Eigen::MatrixXd& positions, const std::string& variogram_id, const std::string& kernel_id);
RcppExport SEXP _LocallyStationaryModels_predikt(SEXP ySEXP, SEXP dSEXP, SEXP anchorpointsSEXP, SEXP epsilonSEXP, SEXP deltaSEXP, SEXP solutionsSEXP, SEXP positionsSEXP, SEXP variogram_idSEXP, SEXP kernel_idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type anchorpoints(anchorpointsSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsilon(epsilonSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type solutions(solutionsSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type positions(positionsSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type variogram_id(variogram_idSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type kernel_id(kernel_idSEXP);
    rcpp_result_gen = Rcpp::wrap(predikt(y, d, anchorpoints, epsilon, delta, solutions, positions, variogram_id, kernel_id));
    return rcpp_result_gen;
END_RCPP
}
// smoothing
Rcpp::List smoothing(const Eigen::MatrixXd solutions, const Eigen::MatrixXd& anchorpoints, const double& delta, const Eigen::MatrixXd& positions, const std::string& kernel_id);
RcppExport SEXP _LocallyStationaryModels_smoothing(SEXP solutionsSEXP, SEXP anchorpointsSEXP, SEXP deltaSEXP, SEXP positionsSEXP, SEXP kernel_idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd >::type solutions(solutionsSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type anchorpoints(anchorpointsSEXP);
    Rcpp::traits::input_parameter< const double& >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type positions(positionsSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type kernel_id(kernel_idSEXP);
    rcpp_result_gen = Rcpp::wrap(smoothing(solutions, anchorpoints, delta, positions, kernel_id));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_LocallyStationaryModels_find_anchorpoints", (DL_FUNC) &_LocallyStationaryModels_find_anchorpoints, 2},
    {"_LocallyStationaryModels_variogramlsm", (DL_FUNC) &_LocallyStationaryModels_variogramlsm, 7},
    {"_LocallyStationaryModels_findsolutionslsm", (DL_FUNC) &_LocallyStationaryModels_findsolutionslsm, 9},
    {"_LocallyStationaryModels_predikt", (DL_FUNC) &_LocallyStationaryModels_predikt, 9},
    {"_LocallyStationaryModels_smoothing", (DL_FUNC) &_LocallyStationaryModels_smoothing, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_LocallyStationaryModels(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
