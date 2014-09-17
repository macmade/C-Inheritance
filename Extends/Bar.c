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

#include "Extends.h"
#include "__Bar.h"

static struct BarMethods __BarMethods;

struct BarMethods * Bar = & __BarMethods;

void Bar_Init( void )
{
    __BarMethods.parent = *( Foo );
    __BarMethods.New    = Bar_New;
    __BarMethods.GetZ   = Bar_GetZ;
}

BarRef Bar_New( int x, int y, int z )
{
    struct __Bar * o;
    
    o = calloc( sizeof( struct __Bar ), 1 );
    
    if( o != NULL )
    {
        o->_vtable = calloc( sizeof( struct BarMethods   ), 1 );
        o->_ivars  = calloc( sizeof( struct BarVariables ), 1 );
    }
    
    Bar_Construct( o, x, y, z );
    
    return o;
}

void Bar_Construct( BarRef o, int x, int y, int z )
{
    if( o == NULL || o->_vtable == NULL || o->_ivars == NULL )
    {
        return;
    }
    
    Foo_Construct( ( FooRef )o, x, y );
    
    memcpy( o->_vtable, Bar, sizeof( struct BarMethods ) );
    
    o->_vtable->parent.GetY = ( int ( * )( FooRef ) )Bar_GetY;
    o->_vtable->parent.SetX = ( void ( * )( FooRef, int ) )Bar_SetX;
    o->_ivars->z            = z;
}

int Bar_GetY( BarRef o )
{
    ( void )o;
    
    return -1;
}

int Bar_GetZ( BarRef o )
{
    if( o == NULL )
    {
        return 0;
    }
    
    return o->_ivars->z;
}

void Bar_SetX( BarRef o, int x )
{
    ( void )o;
    ( void )x;
}
