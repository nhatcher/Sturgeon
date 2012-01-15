#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void loadFileAsVector (vector <double> &fl, const char* str) {
  ifstream readFile(str);
  while (!readFile.eof()) {
    double w;
    readFile >> w;
    fl.push_back(w);
  }
  fl.pop_back();
  readFile.close();
}
void multiply (vector <double> &result, vector <double> &left, vector <double> &right) {
  result.clear();
  for (int i=0; i<left.size(); i++) {
    result.push_back(left[i]*right[i]);
  }
}
void multiply (vector <double> &result, vector <double> &left, double dl) {
  result.clear();
  for (int i=0; i<left.size(); i++) {
    result.push_back(left[i]*dl);
  }
}
double sum (vector <double> &v) {
  double result = 0;
  for (int i=0; i<v.size(); i++) {
    result += v[i];
  }
  return result;
}
double sum15 (vector <double> &v) {
  double result = 0;
  for (int i=14; i<v.size(); i++) {
    result += v[i];
  }
  return result;
}
int main() {
  vector <double> surv;
  vector <double> fecund;
  vector <double> abundb;
  vector <double> abunda;
  vector <double> spawn;
  vector <double> spawnb;
  double spawntot;
  loadFileAsVector(surv,"surv.csv");
  loadFileAsVector(fecund,"fecund.csv");
  loadFileAsVector(abundb,"initabundance.csv");
  for (int iii=0; iii<100; iii++) {
    multiply(spawn, abundb, fecund);
    multiply(spawnb, spawn, 0.0001);
    spawntot = sum(spawnb);
    multiply(abunda, abundb, surv);
    abundb.clear();
    abundb.push_back(spawntot);
    for (int j=0; j<abunda.size()-1; j++) {
      abundb.push_back(abunda[j]);
    }
    cout << setprecision(10) << sum15(abundb) << endl;
  };
  return 0;
}