// -*- mode: C++; indent-tabs-mode: nil; c-basic-offset: 2; -*-
// Pen.hh for Blackbox - an X11 Window manager
// Copyright (c) 2001 - 2003 Sean 'Shaleh' Perry <shaleh@debian.org>
// Copyright (c) 1997 - 2000, 2002 - 2003
//         Bradley T Hughes <bhughes at trolltech.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef GCCACHE_HH
#define GCCACHE_HH

#include "Util.hh"

namespace bt {

  class Color;
  class Display;
  class Font;
  class GCCacheItem;

  class Pen : public NoCopy {
  public:
    static void clearCache(void);

    Pen(unsigned int screen, const Color &color,
        int function = GXcopy, int subwindow = ClipByChildren);
    ~Pen(void);

    void setFont(const Font &font);

    const Display &display(void) const;
    const GC &gc(void) const;

  private:
    unsigned int _screen;

    const Color &_color;
    unsigned long _fontid;
    int _function;
    int _subwindow;

    mutable GCCacheItem *_item;
  };

} // namespace bt

#endif // GCCACHE_HH
