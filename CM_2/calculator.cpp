#include "calculator.h"

#include "diag_matrix.h"

double Calculator::CalcResidual(DiagMatrix& diag_matrix, const vector<double>& x, const vector<double>& F)
{
   auto norm_F = CalcNorm(F);
   vector<double> Ax;
   Multiply(diag_matrix, x, Ax);
   vector<double> F_sub_Ax;
   Subtract(F, Ax, F_sub_Ax);
   auto norm_F_sub_Ax = CalcNorm(F_sub_Ax);
   return norm_F_sub_Ax / norm_F;
}

double Calculator::CalcCond(DiagMatrix& diag_matrix, const vector<double>& x, const vector<double>& F)
{
   vector<double> x_star;
   x_star.resize(x.size());
   for (int i = 0; i < x_star.size(); i++)
   {
      x_star[i] = static_cast<double>(i + 1);
   }
   auto x_star_norm = CalcNorm(x_star);
   vector<double> x_sub_x_star;
   Subtract(x, x_star, x_sub_x_star);
   auto x_sub_x_star_norm = CalcNorm(x_sub_x_star);
   auto error = x_sub_x_star_norm / x_star_norm;
   auto residual = CalcResidual(diag_matrix, x, F);
   return error / residual;
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

void Calculator::Multiply(DiagMatrix& diag_matrix, const vector<double>& x, vector<double>& result)
{
   result.resize(x.size());
   auto& n = diag_matrix.getSize();
   auto& indexes = diag_matrix.getIndexes();
   auto& matrix = diag_matrix.getDiagMatrix();
   for (int i = 0; i < n; i++)
   {
      double sum = 0;
      for (int j = 0; j < 7; j++)
      {
         if (indexes[j] + i >= 0 && indexes[j] + i < n)
         {
            sum += matrix[j][i] * x[indexes[j] + i];
         }
      }
      result[i] = sum;
   }
}

void Calculator::Subtract(const vector<double>& F, const vector<double>& Ax, vector<double>& result)
{
   result.resize(F.size());
   for (int i = 0; i < F.size(); i++)
   {
      result[i] = F[i] - Ax[i];
   }
}