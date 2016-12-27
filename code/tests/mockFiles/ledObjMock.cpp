#include <CppUTestExt/MockSupport.h>
#include "ledObj.h"
#include "ledObjMock.h"


//--- Compile mock version
CLedObj::CLedObj()
{
}

//--- Compile abstract mock version with output control
CLedObjMock::CLedObjMock() : CLedObj()
{
}

