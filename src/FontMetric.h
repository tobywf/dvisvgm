/*************************************************************************
** FontMetrics.h                                                        **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2013 Martin Gieseking <martin.gieseking@uos.de>   **
**                                                                      **
** This program is free software; you can redistribute it and/or        **
** modify it under the terms of the GNU General Public License as       **
** published by the Free Software Foundation; either version 3 of       **
** the License, or (at your option) any later version.                  **
**                                                                      **
** This program is distributed in the hope that it will be useful, but  **
** WITHOUT ANY WARRANTY; without even the implied warranty of           **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         **
** GNU General Public License for more details.                         **
**                                                                      **
** You should have received a copy of the GNU General Public License    **
** along with this program; if not, see <http://www.gnu.org/licenses/>. **
*************************************************************************/

#ifndef FONTMETRICS_H
#define FONTMETRICS_H

#include <istream>
#include "types.h"

struct FontMetric
{
	virtual ~FontMetric () {}
	virtual double getDesignSize () const =0;
	virtual double getCharWidth (int c) const =0;
	virtual double getCharHeight (int c) const =0;
	virtual double getCharDepth (int c) const =0;
	virtual double getItalicCorr (int c) const =0;
	virtual UInt32 getChecksum () const =0;
	virtual UInt16 firstChar () const =0;
	virtual UInt16 lastChar () const =0;
	static FontMetric* read (const char *fontname);
};


struct NullFontMetric : public FontMetric
{
	double getDesignSize () const      {return 1;}
	double getCharWidth (int c) const  {return 0;}
	double getCharHeight (int c) const {return 0;}
	double getCharDepth (int c) const  {return 0;}
	double getItalicCorr (int c) const {return 0;}
	UInt32 getChecksum () const        {return 0;}
	UInt16 firstChar () const          {return 0;}
	UInt16 lastChar () const           {return 0;}
};

#endif