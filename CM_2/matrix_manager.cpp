#include "matrix_manager.h"

#include <fstream>

using namespace std;

void MatrixManager::Read(DiagMatrix& diag_matrix, const string& file_name)
{
   try
   {
      auto matrix_in = ifstream(file_name);
      int n = 0;
      int m = 0;
      int k = 0;
      matrix_in >> n;
      diag_matrix.setSize(n);
      matrix_in >> m;
      diag_matrix.setM(m);
      matrix_in >> k;
      diag_matrix.setK(k);

      vector<int> indexes(7);
      for (int i = 0; i < 7; i++)
      {
         matrix_in >> indexes[i];
      }
      diag_matrix.setIndexes(indexes);

      vector<vector<double>> matrix(7, vector<double>(n));
      for (int i = 0; i < 7; i++)
      {
         for (int j = 0; j < n; j++)
         {
            matrix_in >> matrix[i][j];
         }
      }
      diag_matrix.setDiagMatrix(matrix);
   }
   catch (...)
   {
      throw "Error with Matrix file";
   }
}

