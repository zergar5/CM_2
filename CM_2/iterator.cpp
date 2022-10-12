#include "iterator.h"

#include "diag_matrix.h"

void Iterator::NextIteration(const vector<double>& current_x, vector<double>& next_x,
                             DiagMatrix& diag_matrix, const vector<double>& F, double& relaxation)
{
	auto n = diag_matrix.getSize();
	auto matrix = diag_matrix.getDiagMatrix();
	auto indexes = diag_matrix.getIndexes();
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < 7; j++)
		{
			if(indexes[j] >= 0 && indexes[j] < n)
			{
				sum += matrix[j][i] * current_x[indexes[j]];
			}
			indexes[j]++;
		}
		next_x[i] = current_x[i] + relaxation / matrix[3][i] * (F[i] - sum);
	}
}

void Iterator::NextIteration(vector<double>& current_x, DiagMatrix& diag_matrix, const vector<double>& F, double& relaxation)
{
	auto n = diag_matrix.getSize();
	auto matrix = diag_matrix.getDiagMatrix();
	auto indexes = diag_matrix.getIndexes();
	for (int i = 0; i < n; i++)
	{
		double sum = 0;
		for (int j = 0; j < 7; j++)
		{
			if (indexes[j] >= 0 && indexes[j] < n)
			{
				sum += matrix[j][i] * current_x[indexes[j]];
			}
			indexes[j]++;
		}

		current_x[i] += relaxation / matrix[3][i] * (F[i] - sum);
	}
}


