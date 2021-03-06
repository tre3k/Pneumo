/*----- PROTECTED REGION ID(PneumoStateMachine.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        PneumoStateMachine.cpp
//
// description : State machine file for the Pneumo class
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <Pneumo.h>

/*----- PROTECTED REGION END -----*/	//	Pneumo::PneumoStateMachine.cpp

//================================================================
//  States  |  Description
//================================================================


namespace Pneumo_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Pneumo::is_valve_allowed()
 *	Description : Execution allowed for valve attribute
 */
//--------------------------------------------------------
bool Pneumo::is_valve_allowed(TANGO_UNUSED(Tango::AttReqType type))
{
	//	Not any excluded states for valve attribute in Write access.
	/*----- PROTECTED REGION ID(Pneumo::valveStateAllowed_WRITE) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pneumo::valveStateAllowed_WRITE

	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Pneumo::is_sensor_allowed()
 *	Description : Execution allowed for sensor attribute
 */
//--------------------------------------------------------
bool Pneumo::is_sensor_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for sensor attribute in read access.
	/*----- PROTECTED REGION ID(Pneumo::sensorStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Pneumo::sensorStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================


/*----- PROTECTED REGION ID(Pneumo::PneumoStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	Pneumo::PneumoStateAllowed.AdditionalMethods

}	//	End of namespace
