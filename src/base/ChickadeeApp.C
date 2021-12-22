#include "ChickadeeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ChickadeeApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

ChickadeeApp::ChickadeeApp(InputParameters parameters) : MooseApp(parameters)
{
  ChickadeeApp::registerAll(_factory, _action_factory, _syntax);
}

ChickadeeApp::~ChickadeeApp() {}

void
ChickadeeApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"ChickadeeApp"});
  Registry::registerActionsTo(af, {"ChickadeeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ChickadeeApp::registerApps()
{
  registerApp(ChickadeeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ChickadeeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ChickadeeApp::registerAll(f, af, s);
}
extern "C" void
ChickadeeApp__registerApps()
{
  ChickadeeApp::registerApps();
}
