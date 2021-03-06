//  $Id$
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "construo.hxx"

SystemContext*  system_context  =0;
InputContext*   input_context   =0;
GraphicContext* graphic_context =0;

std::string to_xml (const CL_Vector& vec)
{
#if 0
  std::ostrstream out;
  out << "<cl-vector>"
      << "<x>" << vec.x << "</x>"
      << "<y>" << vec.y << "</y>"
      << "<z>" << vec.z << "</z>"
      << "</cl-vector>" << std::ends;
  std::string str (out.str ());
  out.freeze (false);
  return str;
#endif
  return "";
}

/* EOF */
