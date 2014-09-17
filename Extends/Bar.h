/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Jean-David Gadina - www-xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

#include "warnings.h"

typedef struct __Bar * BarRef;

struct BarVariables
{
    struct FooVariables parent;
    
    int  z;
    char _pad_0[ 4 ];
};

struct BarMethods
{
    struct FooMethods parent;
    
    BarRef ( * New )( int x, int y, int z );
    int    ( * GetZ )( BarRef o );
};

extern struct BarMethods * Bar;

void   Bar_Init( void );
BarRef Bar_New( int x, int y, int z );
void   Bar_Construct( BarRef o, int x, int y, int z );
int    Bar_GetY( BarRef o );
int    Bar_GetZ( BarRef o );
void   Bar_SetX( BarRef o, int x );
