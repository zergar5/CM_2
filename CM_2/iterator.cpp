#include "iterator.h"
#include "block_diag_matrix.h"
#include "diag_matrix.h"
#include "block_relaxation.h"

double Iterator::NextIteration(DiagMatrix& diag_matrix, const vector<double>& current_x, vector<double>& next_x,
    const vector<double>& F, const double& relaxation)
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

double Iterator::NextIteration(DiagMatrix& diag_matrix, vector<double>& current_x, const vector<double>& F,
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

double Iterator::NextIteration(BlockDiagMatrix& block_diag_matrix, vector<double>& current_x,  const vector<double>& F,
	const double& relaxation)
{
	auto& n = block_diag_matrix.getSize();
	auto& block_size = block_diag_matrix.getBlockSize();
	auto& matrix = block_diag_matrix.getDiagMatrix();
	auto& indexes = block_diag_matrix.getIndexes();
	
	double residual = 0.0;
	double sum_of_sq_vec_F = 0.0;
	auto n_blocks = n / block_size;
	for (int i = 0; i < n_blocks; i++)
	{
		auto r = vector<double>(block_size);
		auto k0 = i * block_size;
		auto k1 = (i + 1) * block_size;
		BlockRelaxation::CalcBlockPart(block_diag_matrix, current_x, r, k0, k1);
		auto bi = 0;
		for (int j = k0; j < k1; j++, bi++)
		{
			double sum = 0.0;
			for (int k = 0; k < 7; k++)
			{
				if (indexes[k] + j >= 0 && indexes[k] + j < n)
				{
					if(indexes[k] + j < k0 || indexes[k] + j >= k1)
					{
						sum += matrix[k][j] * current_x[indexes[k] + j];
					}
				}
			}
			r[bi] = F[j] - (r[bi] + sum);
			residual += (r[bi]) * (r[bi]);
			r[bi] *= relaxation;
			sum_of_sq_vec_F += F[j] * F[j];
		}
		BlockRelaxation::SolveSLAE(block_diag_matrix, r, relaxation, k0, k1);
		bi = 0;
		for (int j = k0; j < k1; j++, bi++)
		{
			current_x[j] += r[bi];
		}
	}
	return sqrt(residual) / sqrt(sum_of_sq_vec_F);
}