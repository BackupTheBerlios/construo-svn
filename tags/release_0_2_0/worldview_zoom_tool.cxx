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

#include "colors.hxx"
#include "construo.hxx"
#include "input_context.hxx"
#include "math.hxx"
#include "worldview_component.hxx"
#include "worldview_zoom_tool.hxx"

WorldViewZoomTool::WorldViewZoomTool ()
{
  creating_zoom_rectangle = false;
}

WorldViewZoomTool::~WorldViewZoomTool ()
{
}

void
WorldViewZoomTool::activate ()
{
  creating_zoom_rectangle = false;
}

void
WorldViewZoomTool::draw_foreground (ZoomGraphicContext* gc)
{
  if (creating_zoom_rectangle)
    {
      float x = WorldViewComponent::instance()->get_gc()->screen_to_world_x (input_context->get_mouse_x ());
      float y = WorldViewComponent::instance()->get_gc()->screen_to_world_y (input_context->get_mouse_y ());               
      
      gc->draw_rect (Math::min(x, click_pos.x),
                     Math::min(y, click_pos.y),
                     Math::max(x, click_pos.x),
                     Math::max(y, click_pos.y),
                     Colors::new_spring);
    }
}

void
WorldViewZoomTool::on_primary_button_press (int screen_x, int screen_y)
{
  creating_zoom_rectangle = true;
  click_pos.x = WorldViewComponent::instance()->get_gc()->screen_to_world_x (screen_x);
  click_pos.y = WorldViewComponent::instance()->get_gc()->screen_to_world_y (screen_y);
}  

void
WorldViewZoomTool::on_primary_button_release (int screen_x, int screen_y)
{
  creating_zoom_rectangle = false;

  float x = WorldViewComponent::instance()->get_gc()->screen_to_world_x (screen_x);
  float y = WorldViewComponent::instance()->get_gc()->screen_to_world_y (screen_y);
  
  WorldViewComponent::instance()->get_gc()->zoom_to((int)Math::min(x, click_pos.x),
                                                    (int)Math::min(y, click_pos.y),
                                                    (int)Math::max(x, click_pos.x),
                                                    (int)Math::max(y, click_pos.y));
}

/* EOF */
