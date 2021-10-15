#include "elkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
elkApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

elkApp::elkApp(InputParameters parameters) : MooseApp(parameters)
{
  elkApp::registerAll(_factory, _action_factory, _syntax);
}

elkApp::~elkApp() {}

void
elkApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"elkApp"});
  Registry::registerActionsTo(af, {"elkApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
elkApp::registerApps()
{
  registerApp(elkApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
elkApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  elkApp::registerAll(f, af, s);
}
extern "C" void
elkApp__registerApps()
{
  elkApp::registerApps();
}
