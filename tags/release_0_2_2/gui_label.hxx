//  $Id$
// 
//  Construo - A wire-frame construction gamee
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

#ifndef HEADER_CONSTRUO_GUI_LABEL_HXX
#define HEADER_CONSTRUO_GUI_LABEL_HXX

#include <string>
#include "gui_component.hxx"

/** */
class GUILabel : public GUIComponent
{
private:
  std::string title;
public:
  GUILabel (const std::string& title_, int x, int y, int width, int height);
  
  void draw (GraphicContext*);
  bool is_at (int, int) { return false; }
};

#endif

/* EOF */
