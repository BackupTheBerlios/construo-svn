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

#ifndef HEADER_CONSTRUO_WORLDVIEW_SELECT_TOOL_HXX
#define HEADER_CONSTRUO_WORLDVIEW_SELECT_TOOL_HXX

#include "worldview_tool.hxx"

class Particle;

/** */
class WorldViewSelectTool : public WorldViewTool
{
private:
  typedef std::vector<Particle*> Selection;
  Selection selection;
  /** Pointer to the world for which the selection is valid, if world
      changes (on undo) the selection becomes invalid and has do be
      cleared */
  World* selected_world;

  typedef enum { GETTING_SELECTION_MODE, 
                 MOVING_SELECTION_MODE, 
                 IDLE_MODE } Mode;
  Mode mode;
  Vector2d selection_start;
public:
  WorldViewSelectTool (WorldViewComponent*);
  ~WorldViewSelectTool ();

  void activate ();
  void deactivate ();

  void draw_background (GraphicContext* gc);
  void draw_foreground (GraphicContext* gc);

  void on_primary_button_press (int x, int y);
  void on_primary_button_release (int x, int y);

  void on_secondary_button_press (int x, int y);
  void on_secondary_button_release (int x, int y);

  void on_mouse_move (int x, int y, int of_x, int of_y);

  void on_delete_press (int x, int y);
  void on_fix_press (int x, int y);
};

#endif

/* EOF */
