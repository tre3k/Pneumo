/*----- PROTECTED REGION ID(PneumoClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        PneumoClass.h
//
// description : Include for the Pneumo root class.
//               This class is the singleton class for
//                the Pneumo device class.
//               It contains all properties and methods which the 
//               Pneumo requires only once e.g. the commands.
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
// Pshenichnyi Kirill PNPI (c) 2019
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef PneumoClass_H
#define PneumoClass_H

#include <tango.h>
#include <Pneumo.h>


/*----- PROTECTED REGION END -----*/	//	PneumoClass.h


namespace Pneumo_ns
{
/*----- PROTECTED REGION ID(PneumoClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	PneumoClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute valve class definition
class valveAttrib: public Tango::Attr
{
public:
	valveAttrib():Attr("valve",
			Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~valveAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Pneumo *>(dev))->read_valve(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
		{(static_cast<Pneumo *>(dev))->write_valve(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Pneumo *>(dev))->is_valve_allowed(ty);}
};


/**
 *	The PneumoClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  PneumoClass : public Tango::DeviceClass
#else
class PneumoClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(PneumoClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	PneumoClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static PneumoClass *init(const char *);
		static PneumoClass *instance();
		~PneumoClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		PneumoClass(string &);
		static PneumoClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	Pneumo_H
