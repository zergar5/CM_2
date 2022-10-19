#pragma once
#include <string>
#include <vector>

using namespace std;

class DiagMatrix
{
   int _n;
   int _m;
   int _k;
   vector<vector<double>> diag_matrix_;
   vector<int> indexes_;
public:
   void MemoryAllocated(const string& file_name);
   void setSize(const int& n);
   int& getSize();
   void setM(const int& m);
   int& getM();
   void setK(const int& k);
   int& getK();
   void setIndexes(const vector<int>& indexes);
   vector<int>& getIndexes();
   void setDiagMatrix(const vector<vector<double>>& diag_matrix);
   vector<vector<double>>& getDiagMatrix();
};
