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

#include <math.h>
#include "rect_collider.hxx"

RectCollider::RectCollider (int x1_, int y1_, int x2_, int y2_)
  : x1 (x1_), y1 (y1_), x2 (x2_), y2 (y2_)
{
}

bool
RectCollider::is_at (const Vector2d& pos)
{
  return false;
}

void
RectCollider::bounce (Particle& particle)
{
  float damp = 0.2;

  if (particle.pos.x > x1)
    {
      particle.velocity.x =  fabs(particle.velocity.x);
      particle.velocity *= damp;
    }
  else if (particle.pos.x < x2)
    {
      particle.velocity.x =  -fabs(particle.velocity.x);
      particle.velocity *= damp;
    }

  if (particle.pos.y > y1)
    {
      particle.velocity.y =  fabs(particle.velocity.y);
      particle.velocity *= damp;
    }
  else if (particle.pos.y < y2)
    {
      particle.velocity.y =  -fabs(particle.velocity.y);
      particle.velocity *= damp;
    }
}

void
RectCollider::draw (GraphicContext* gc)
{
  gc->draw_rect (x1, y1, x2, y2, Color (0x0000FF));
}

/* EOF */
