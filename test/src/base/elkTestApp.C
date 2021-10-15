//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "elkTestApp.h"
#include "elkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
elkTestApp::validParams()
{
  InputParameters params = elkApp::validParams();
  return params;
}

elkTestApp::elkTestApp(InputParameters parameters) : MooseApp(parameters)
{
  elkTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

elkTestApp::~elkTestApp() {}

void
elkTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  elkApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"elkTestApp"});
    Registry::registerActionsTo(af, {"elkTestApp"});
  }
}

void
elkTestApp::registerApps()
{
  registerApp(elkApp);
  registerApp(elkTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
elkTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  elkTestApp::registerAll(f, af, s);
}
extern "C" void
elkTestApp__registerApps()
{
  elkTestApp::registerApps();
}
