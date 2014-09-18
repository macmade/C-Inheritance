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

int main( void )
{
    FooRef foo;
    BarRef bar;
    
    Foo_Init();
    Bar_Init();
    
    foo = Foo.New( 42, 27 );
    bar = Bar.New( 42, 27, 256 );
    
    printf( "Foo X: %i\n", Foo.GetX( foo ) );
    printf( "Foo Y: %i\n", Foo.GetY( foo ) );
    printf( "Bar X: %i\n", Foo.GetX( ( FooRef )bar ) );
    printf( "Bar Y: %i\n", Foo.GetY( ( FooRef )bar ) );
    printf( "Bar Z: %i\n", Bar.GetZ( bar ) );
    
    Foo.SetX( foo, 0 );
    Foo.SetY( foo, 0 );
    Foo.SetX( ( FooRef )bar, 0 );
    Foo.SetY( ( FooRef )bar, 0 );
    
    printf( "Foo X: %i\n", Foo.GetX( foo ) );
    printf( "Foo Y: %i\n", Foo.GetY( foo ) );
    printf( "Bar X: %i\n", Foo.GetX( ( FooRef )bar ) );
    printf( "Bar Y: %i\n", Foo.GetY( ( FooRef )bar ) );
    printf( "Bar Z: %i\n", Bar.GetZ( bar ) );
    
    return 0;
}
