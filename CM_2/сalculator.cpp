#include "ñalculator.h"

#include "diag_matrix.h"

double Calculator::CalcResidual(DiagMatrix& diag_matrix, const vector<double>& next_x, const vector<double>& F)
{
   auto norm_F = CalcNorm(F);
   auto Ax = Multiply(diag_matrix, next_x);
   auto F_sub_Ax = Subtract(F, Ax);
   auto norm_F_sub_Ax = CalcNorm(F_sub_Ax);
   return norm_F_sub_Ax / norm_F;
}

double Calculator::CalcNorm(const vector<double>& vec)
{
   double norm = 0;
   for (auto element : vec)
   {
      norm += element * element;
   }
   return sqrt(norm);
}

vector<double> Calculator::Multiply(DiagMatrix& diag_matrix, const vector<double>& next_x)
{
   vector<double> result;
   result.resize(next_x.size());
   auto n = diag_matrix.getSize();
   auto indexes = diag_matrix.getIndexes();
   auto matrix = diag_matrix.getDiagMatrix();
   for (int i = 0; i < n; i++)
   {
      double sum = 0;
      for (int j = 0; j < 7; j++)
      {
         if (indexes[j] >= 0 && indexes[j] < n)
         {
            sum += matrix[j][i] * next_x[indexes[j]];
         }
         indexes[j]++;
      }
      result[i] = sum;
   }
   return result;
}

vector<double> Calculator::Subtract(const vector<double>& F, const vector<double>& Ax)
{
   vector<double> result;
   result.resize(F.size());
   for (int i = 0; i < F.size(); i++)
   {
      result[i] = F[i] - Ax[i];
   }
   return result;
}
