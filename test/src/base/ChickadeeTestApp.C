//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ChickadeeTestApp.h"
#include "ChickadeeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
ChickadeeTestApp::validParams()
{
  InputParameters params = ChickadeeApp::validParams();
  return params;
}

ChickadeeTestApp::ChickadeeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ChickadeeTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ChickadeeTestApp::~ChickadeeTestApp() {}

void
ChickadeeTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ChickadeeApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ChickadeeTestApp"});
    Registry::registerActionsTo(af, {"ChickadeeTestApp"});
  }
}

void
ChickadeeTestApp::registerApps()
{
  registerApp(ChickadeeApp);
  registerApp(ChickadeeTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ChickadeeTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ChickadeeTestApp::registerAll(f, af, s);
}
extern "C" void
ChickadeeTestApp__registerApps()
{
  ChickadeeTestApp::registerApps();
}
