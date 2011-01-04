/*************************************************************************
** macros.h                                                             **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2011 Martin Gieseking <martin.gieseking@uos.de>   **
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

#ifndef MACROS_H
#define MACROS_H

#define FORALL(container, itertype, itervar) \
	for (itertype itervar=(container).begin(); itervar != (container).end(); ++itervar)

#define IMPLEMENT_ARITHMETIC_OPERATOR(class, op)        \
	inline class operator op (class a, const class &b) { \
		return a op##= b;                                 \
	}

#define IMPLEMENT_ARITHMETIC_OPERATOR2(class, scalar, op) \
	inline class operator op (class a, scalar b) { \
		return a op##= b;                           \
	}

#define IMPLEMENT_OUTPUT_OPERATOR(class)                            \
	inline std::ostream& operator << (std::ostream &os, class obj) { \
		return obj.write(os);                                         \
	}

#include <iostream>
#define SHOW(x) std::cerr << __FILE__ ", " << __LINE__ << ": " << #x << "=" << (x) << std::endl

#endif
