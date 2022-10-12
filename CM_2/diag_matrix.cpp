#include "diag_matrix.h"
#include "matrix_manager.h"

DiagMatrix::DiagMatrix(const string& file_name)
{
   MatrixManager::Read(*this, file_name);
}

void DiagMatrix::setSize(const int& n)
{
   this->_n = n;
}

int& DiagMatrix::getSize()
{
   return this->_n;
}

void DiagMatrix::setM(const int& m)
{
   this->_m = m;
}

int& DiagMatrix::getM()
{
   return this->_m;
}

void DiagMatrix::setK(const int& k)
{
   this->_k = k;
}

int& DiagMatrix::getK()
{
   return this->_k;
}

void DiagMatrix::setIndexes(const vector<int>& indexes)
{
   this->indexes_ = indexes;
}

vector<int>& DiagMatrix::getIndexes()
{
   return this->indexes_;
}

void DiagMatrix::setDiagMatrix(const vector<vector<double>>& diag_matrix)
{
   this->diag_matrix_ = diag_matrix;
}

vector<vector<double>>& DiagMatrix::getDiagMatrix()
{
   return this->diag_matrix_;
}
