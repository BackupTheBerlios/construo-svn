//  Construo - A wire-frame construction game
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_CONSTRUO_KEEP_ALIVE_MGR_HPP
#define HEADER_CONSTRUO_KEEP_ALIVE_MGR_HPP

#include <vector>

class KeepAlive;

class KeepAliveMgr
{
  static std::vector<KeepAlive*> lst;
public:
  static void register_obj (KeepAlive*);
  static void unregister_obj (KeepAlive*);
  
  static void keep_alive ();
};

#endif

/* EOF */
