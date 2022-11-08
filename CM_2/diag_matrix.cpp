#include "diag_matrix.h"
#include "matrix_manager.h"

void DiagMatrix::MemoryAllocated(const string& file_name)
{
   MatrixManager::Read(*this, file_name);
}

void DiagMatrix::setSize(const int& n)
{
   this->n_ = n;
}

int& DiagMatrix::getSize()
{
   return this->n_;
}

void DiagMatrix::setM(const int& m)
{
   this->m_ = m;
}

int& DiagMatrix::getM()
{
   return this->m_;
}

void DiagMatrix::setK(const int& k)
{
   this->k_ = k;
}

int& DiagMatrix::getK()
{
   return this->k_;
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