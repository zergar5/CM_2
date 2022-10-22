#include "iterator.h"

#include "diag_matrix.h"

double Iterator::NextIteration(const vector<double>& current_x, vector<double>& next_x,
   DiagMatrix& diag_matrix, const vector<double>& F, const double& relaxation)
{
	auto& n = diag_matrix.getSize();
	auto& matrix = diag_matrix.getDiagMatrix();
	auto& indexes = diag_matrix.getIndexes();
	double residual = 0.0;
	double sum_of_sq_vec_F = 0.0;
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < 7; j++)
		{
			if(indexes[j] + i >= 0 && indexes[j] + i < n)
			{
				sum += matrix[j][i] * current_x[indexes[j] + i];
			}
		}
		residual += (F[i] - sum) * (F[i] - sum);
		sum_of_sq_vec_F += F[i] * F[i];
		next_x[i] = current_x[i] + relaxation / matrix[3][i] * (F[i] - sum);
	}
	return sqrt(residual) / sqrt(sum_of_sq_vec_F);
}

double Iterator::NextIteration(vector<double>& current_x, DiagMatrix& diag_matrix, const vector<double>& F,
	const double& relaxation)
{
	auto& n = diag_matrix.getSize();
	auto& matrix = diag_matrix.getDiagMatrix();
	auto& indexes = diag_matrix.getIndexes();
	double residual = 0.0;
	double sum_of_sq_vec_F = 0.0;
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < 7; j++)
		{
			if (indexes[j] + i >= 0 && indexes[j] + i < n)
			{
				sum += matrix[j][i] * current_x[indexes[j] + i];
			}
		}
		residual += (F[i] - sum) * (F[i] - sum);
		sum_of_sq_vec_F += F[i] * F[i];
		current_x[i] += relaxation / matrix[3][i] * (F[i] - sum);
	}
	return sqrt(residual) / sqrt(sum_of_sq_vec_F);
}