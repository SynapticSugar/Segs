/*
 * Super Entity Game Server
 * http://segs.sf.net/
 * Copyright (c) 2006 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 * $Id: MapServerInterface.h 253 2006-08-31 22:00:14Z malign $
 */

#pragma once
#include <string>
#include <ace/Configuration.h>
#include <ace/Configuration_Import_Export.h>
#include <ace/INET_Addr.h>
#include "types.h"
class StringsBasedCfg : public ACE_Configuration_Heap
{
public:
	int get_integer_value(const ACE_Configuration_Section_Key& key,const ACE_TCHAR* name,u32& value,u32 default_val)
	{
		ACE_TString res;
		if(-1==ACE_Configuration_Heap::get_string_value(key,name,res))
		{
			value=default_val;
			return -1;
		}
		value=strtoul(res.c_str(),NULL,0);
		return 0;
	}
	int get_integer_value(const ACE_Configuration_Section_Key& key,const ACE_TCHAR* name,u16& value,u16 default_val)
	{
		ACE_TString res;
		if(-1==ACE_Configuration_Heap::get_string_value(key,name,res))
		{
			value=default_val;
			return -1;
		}
		value = (u16)strtoul(res.c_str(),0,0);
		return 0;
	}
	int get_string_value(const ACE_Configuration_Section_Key& key, const ACE_TCHAR* name, std::string& value,const std::string &default_val)
	{
		ACE_TString res;
		if(-1==ACE_Configuration_Heap::get_string_value(key,name,res))
		{
			value=default_val;
			return -1;
		}
		value=res.c_str();
		return 0;
	}
	int get_addr(const ACE_Configuration_Section_Key& key, const ACE_TCHAR* name, ACE_INET_Addr& value,const ACE_INET_Addr &default_val)
	{
		ACE_TString res;
		if(-1==ACE_Configuration_Heap::get_string_value(key,name,res))
		{
			value.set(default_val);
			return -1;
		}
		ssize_t pos = res.rfind(':');
		if((pos<=0) || (pos>=res.length())) // invalid addr
		{
			value=default_val;
			return -1;
		}
		value.set((u16)strtoul(res.substr(pos+1,ACE_TString::npos).c_str(),0,0),res.substr(0,pos).c_str());
		return 0;
	}
};
