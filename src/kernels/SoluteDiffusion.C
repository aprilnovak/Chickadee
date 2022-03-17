#include "SoluteDiffusion.h"

registerMooseObject("ChickadeeApp", SoluteDiffusion);

InputParameters
SoluteDiffusion::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addParam<Real>("coefficient", "Diffusion coefficient");
  return params;
}

SoluteDiffusion::SoluteDiffusion(const InputParameters & parameters) : Kernel(parameters),
  _coefficient(getParam<Real>("coefficient"))
{
}

Real
SoluteDiffusion::computeQpResidual()
{
  return _coefficient * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
SoluteDiffusion::computeQpJacobian()
{
  return _coefficient * _grad_phi[_j][_qp] * _grad_test[_i][_qp];
}
