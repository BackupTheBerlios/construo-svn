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
#include "system_context.hxx"
#include "world_button.hxx"
#include "gui_directory_button.hxx"
#include "gui_directory.hxx"

GUIDirectory::GUIDirectory (const std::string& pathname)
  : GUIComponent (0, 0, 800, 600)
{
  std::vector<std::string> dir = system_context->read_directory(pathname);
  
  for (std::vector<std::string>::iterator i = dir.begin(); i != dir.end(); ++i)
    {
      std::string filename = pathname + *i;

      FileType type = system_context->get_file_type (filename);

      std::cout << "Creating object for: " << filename << std::endl;

      if (type == FT_DIRECTORY)
        {
          files.push_back (new GUIDirectoryButton (filename));
        }
      else if (type == FT_CONSTRUO_FILE)
        {
          files.push_back (new WorldButton (filename));
        }
      else // (type == FT_UNKNOWN_FILE)
        {
          // ignore unknown files
          std::cout << "GUIFileManager: ignoring '" << filename
                    << "' since it has unknown filetype" << std::endl;
        }
    }
}

GUIDirectory::~GUIDirectory ()
{
}

void
GUIDirectory::draw (GraphicContext* gc)
{
  for(std::vector<GUIFileButton*>::iterator i = files.begin();
      i != files.end();
      ++i)
    {
      (*i)->draw(gc);
    }  
}

/* EOF */
