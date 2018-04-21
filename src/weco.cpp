#include <R.h>
#include <Rmath.h>
#include <Rcpp.h>
#include <vector>
using namespace Rcpp;

//get running length
// [[Rcpp::export]]
void getrl(NumericVector violations, int n, NumericVector rst) {
  int i;
  int nv, carl;

  nv   = 0;
  carl = 0;
  for (i = 0; i < n; i++) {
    if (0 == violations[i]) {
      carl++;
    } else {
      rst[nv] = carl;
      nv++;
      carl = 0;
    }
  }
}

//rule1
// [[Rcpp::export]]
NumericVector rule1(NumericVector data, int k, double m, double sd, int n, NumericVector rst) {
  int i;
  double b;

  b = (k) * (sd);

  for (i = 0; i < n; i++) {
    if (fabs(data[i] - m) > b ) {
      rst[i] = 1;
    } else {
      rst[i] = 0;
    }
  }
  return rst;
}
