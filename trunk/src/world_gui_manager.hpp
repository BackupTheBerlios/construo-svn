//  Construo - A wire-frame construction gamee
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

#ifndef HEADER_WORLD_GUI_MANAGER_HPP
#define HEADER_WORLD_GUI_MANAGER_HPP

#include "gui_manager.hpp"

/** */
class WorldGUIManager : public GUIManager
{
private:
  static WorldGUIManager* instance_;
public:
  static WorldGUIManager* instance() { return instance_; }

  WorldGUIManager ();
  virtual ~WorldGUIManager ();

  void update();
  void draw_overlay (); 
};

#endif

/* EOF */
