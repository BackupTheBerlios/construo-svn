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

#include "string_utils.hxx"

namespace StringUtils
{
  bool has_prefix (const std::string& str, const std::string& prefix)
  {
    if (prefix.length() > str.length())
      {
        return false;
      }
    else
      {
        for (std::string::size_type i = 0; i < prefix.length(); ++i)
          {
            if (prefix[i] != str[i])
              return false;
          }
        return true;
      }
  }

  bool has_suffix (const std::string& str, const std::string& suffix)
  {
    if (suffix.length() > str.length())
      {
        return false;
      }
    else
      {
        for (std::string::size_type i = 0; i < suffix.length(); ++i)
          {
            if (suffix[i] != str[str.length() -  suffix.length() + i])
              return false;
          }
        return true;
      }
  }
}

/* EOF */
