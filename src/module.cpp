/*
SoftTH, Software multihead solution for Direct3D
Copyright (C) 2005-2012 Keijo Ruotsalainen, www.kegetys.fi
              2014-     C. Justin Ratcliff, www.softth.net

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "module.h"

// Constructor
Module::Module()
{
  Module::hMod = NULL;
}

// Copy constuctor
Module::Module(Module &hMod)
{

}

// Destructor
Module::~Module()
{

}

bool Module::SetHandle(char* path)
{
  Module::hMod = LoadLibrary(path);
  if(Module::hMod) return true; else return false;
}

HMODULE Module::GetHandle()
{
  if(Module::hMod) return Module::hMod; else return NULL;
}

void Module::Release()
{
  FreeLibrary(Module::hMod);
  Module::hMod = NULL;
}


