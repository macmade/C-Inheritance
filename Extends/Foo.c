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
#include "__Foo.h"

struct FooMethods Foo;

void Foo_Init( void )
{
    Foo.New  = Foo_New;
    Foo.GetX = Foo_GetX;
    Foo.GetY = Foo_GetY;
    Foo.SetX = Foo_SetX;
    Foo.SetY = Foo_SetY;
}

FooRef Foo_New( int x, int y )
{
    struct __Foo * o;
    
    o = calloc( sizeof( struct __Foo ), 1 );
    
    if( o != NULL )
    {
        o->_vtable = calloc( sizeof( struct FooMethods   ), 1 );
        o->_ivars  = calloc( sizeof( struct FooVariables ), 1 );
    }
    
    Foo_Construct( o, x, y );
    
    return o;
}

void Foo_Construct( FooRef o, int x, int y )
{
    if( o == NULL || o->_vtable == NULL || o->_ivars == NULL )
    {
        return;
    }
    
    memcpy( o->_vtable, &Foo, sizeof( struct FooMethods ) );
    
    o->_ivars->x = x;
    o->_ivars->y = y;
}

int Foo_GetX( FooRef o )
{
    if( o == NULL )
    {
        return 0;
    }
    
    if( o->_vtable->GetX != Foo_GetX )
    {
        return o->_vtable->GetX( o );
    }
    
    return o->_ivars->x;
}

int Foo_GetY( FooRef o )
{
    if( o == NULL )
    {
        return 0;
    }
    
    if( o->_vtable->GetY != Foo_GetY )
    {
        return o->_vtable->GetY( o );
    }
    
    return o->_ivars->y;
}

void Foo_SetX( FooRef o, int x )
{
    if( o == NULL )
    {
        return;
    }
    
    if( o->_vtable->SetX != Foo_SetX )
    {
        o->_vtable->SetX( o, x );
        
        return;
    }
    
    o->_ivars->x = x;
}

void Foo_SetY( FooRef o, int y )
{
    if( o == NULL )
    {
        return;
    }
    
    if( o->_vtable->SetY != Foo_SetY )
    {
        o->_vtable->SetY( o, y );
        
        return;
    }
    
    o->_ivars->y = y;
}
