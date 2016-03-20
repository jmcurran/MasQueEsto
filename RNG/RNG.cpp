#include <random>
#include <Rcpp.h>

using namespace std;
using namespace Rcpp;

mt19937 mtEngine;
uniform_real_distribution<double> rngU;
normal_distribution<double> rngZ;

//[[Rcpp::export]]
void setSeed(unsigned int seed){
    mtEngine = mt19937(seed);
    rngU = uniform_real_distribution<>(0.0, 1.0);
    rngZ = normal_distribution<double>(0.0, 1.0);
  }

  
double rnorm(double mu = 0, double sigma = 1){
  return rngZ(mtEngine) * sigma + mu;
}
  
double runif(void){
  return rngU(mtEngine);
}
  
//[[Rcpp::export]]
NumericVector testNorm(int n, double m, double s){
  NumericVector r(n);
  for(int i = 0; i < n; i++)
    r[i] = rnorm(m, s);
  
  return r;
}

//[[Rcpp::export]]
NumericVector testUnif(int n){
  NumericVector r(n);
  for(int i = 0; i < n; i++)
    r[i] = runif();
  
  return r;
}


  