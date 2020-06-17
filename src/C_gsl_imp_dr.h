//     ------------------------------------------------------------------------
//
//     This file is part of SDRcausal.
//
//     SDRcausal is free software: you can redistribute it and/or modify it
//     under the terms of the GNU General Public License as published by the
//     Free Software Foundation, either version 3 of the License, or (at your
//     option) any later version.
//
//     SDRcausal is distributed in the hope that it will be useful, but WITHOUT
//     ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//     FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//     for more details.
//
//     You should have received a copy of the GNU General Public License along
//     with SDRcausal.  If not, see <https://www.gnu.org/licenses/>.
//
//     ------------------------------------------------------------------------
//
#ifndef C_GSL_IMP_DR_H
#define C_GSL_IMP_DR_H
#include <R.h>
#include <Rdefines.h>

typedef struct ImpParams
{
  int n;
  int p;
  int d;
  int n_threads;
  int kernel_spec;
  int *treated;

  double b0;
  double h0;
  double h11;
  double h12;
  double h13;
  double h14;
  double gauss_cutoff;

  double *x;
  double *y;
} ImpParams;

/**
 * @brief Wrapper function for imp_dim_red which is used to estimate beta.
 *
 * @param n_in         Number of observations
 * @param p_in         Number of covariates
 * @param d_in         Structural dimension
 * @param x            Covariate matrix
 * @param x_beta       CMS projection of x
 * @param y            Response vector
 * @param treated      Binary treatment vector
 * @param kernel_spec  Indicates which kernel function to be used
 * @param h0           Kernel bandwidth
 * @param h11          Kernel bandwidth
 * @param h12          Kernel bandwidth
 * @param h13          Kernel bandwidth
 * @param h14          Kernel bandwidth
 * @param gauss_cutoff Cutoff value for Gaussian kernel
 * @param n_threads_in Number of threads for parallel computing
 * @param fval         Pointer to store output value
 *
 * @return R_NilValue
 */
SEXP
C_imp_dim_red (SEXP       n_in,
               SEXP       p_in,
               SEXP       d_in,
               const SEXP x,
               const SEXP beta_guess,
               const SEXP y,
               const SEXP treated,
               SEXP       kernel_spec,
               SEXP       h0,
               SEXP       h11,
               SEXP       h12,
               SEXP       h13,
               SEXP       h14,
               SEXP       gauss_cutoff,
               SEXP       n_threads_in,
               SEXP       beta_final);

#endif
