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

#include "lisp_reader.hxx"
#include "particle.hxx"

Particle::Particle (lisp_object_t* obj)
{
  fixed = false;
  mass = 10.0;

  obj = lisp_cdr(obj);
  //std::cout << "Loading particle: " << std::endl;
  //lisp_dump(obj, stdout);
  //std::cout << std::endl;

  LispReader reader(obj);
  reader.read_vector ("pos", &pos);
  reader.read_vector ("velocity", &velocity);
  reader.read_float ("mass", &mass);
  reader.read_bool ("fixed", &fixed);
  reader.read_int ("id", &id);
}

/* EOF */
