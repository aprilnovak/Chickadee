#pragma once

#include "Kernel.h"

class SoluteDiffusion : public Kernel
{
public:
  static InputParameters validParams();

  SoluteDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  const Real & _coefficient;
};
