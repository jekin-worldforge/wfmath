// -*-C++-*-
// error.h (Class structures for errors thrown by the WFMath library)
//
//  The WorldForge Project
//  Copyright (C) 2001  The WorldForge Project
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//  For information about WorldForge and its authors, please contact
//  the Worldforge Web Site at http://www.worldforge.org.

// Author: Ron Steinke
// Created: 2001-12-7

#ifndef WFMATH_ERROR_H
#define WFMATH_ERROR_H

#include <wfmath/vector.h>
#include <wfmath/vector_funcs.h>

namespace WF { namespace Math {

struct BadRotationAxisNum {
  BadRotationAxisNum(const int i_in, const int j_in) : i(i_in), j(j_in) {}

  int i, j;
};

template<const int len>
struct BadRotationPlane {
  BadRotationPlane(const Vector<len>& v1_in, const Vector<len>& v2_in)
    : v1(v1_in), v2(v2_in) {}

  Vector<len> v1, v2;
};

struct BadRotationAxis : public Vector<3> {
  BadRotationAxis(const Vector<3>& v) : Vector<3>(v) {}
};

}} // namespace WF::Math

#endif // WFMATH_ERROR_H
