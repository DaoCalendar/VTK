/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImagePaint.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
  Thanks:    Thanks to C. Charles Law who developed this class.

Copyright (c) 1993-1995 Ken Martin, Will Schroeder, Bill Lorensen.

This software is copyrighted by Ken Martin, Will Schroeder and Bill Lorensen.
The following terms apply to all files associated with the software unless
explicitly disclaimed in individual files. This copyright specifically does
not apply to the related textbook "The Visualization Toolkit" ISBN
013199837-4 published by Prentice Hall which is covered by its own copyright.

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
// .NAME vtkImagePaint - A region that can be drawn into with colors.
// .SECTION Description
// vtkImagePaint is a region object with methods to draw boxs, lines ...
// over the data.  DrawColor is a vector that is placed into the components
// of the region.  It can be color (RGB) Greyscale scalar, or any 
// arbitrary vector.  This object is limited to drawing into 2d regions 
// for now.


#ifndef __vtkImagePaint_h
#define __vtkImagePaint_h

#include <math.h>
#include "vtkImageRegion.h"

//
// Special classes for manipulating data
//
//BTX - begin tcl exclude
//
// For the fill functionality
class vtkImagePaintPixel { //;prevent man page generation
public:
  int X;
  int Y;
  void *Pointer;
  vtkImagePaintPixel *Next;
};
//ETX - end tcl exclude
//


class VTK_EXPORT vtkImagePaint : public vtkImageRegion
{
public:
  vtkImagePaint();
  ~vtkImagePaint();
  static vtkImagePaint *New() {return new vtkImagePaint;};
  char *GetClassName() {return "vtkImagePaint";};
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // To drawing into a different image, set it with this method.
  vtkSetObjectMacro(ImageRegion, vtkImageRegion);
  vtkGetObjectMacro(ImageRegion, vtkImageRegion);
  
  // Description:
  // Set/Get DrawValue.  This is the value that is used when filling regions
  // or drawing lines.
  void SetDrawColor(int dim, float *color);
  void GetDrawColor(int dim, float *color);
  float *GetDrawColor() {return this->DrawColor;}
  vtkImageSetMacro(DrawColor, float);
  vtkImageGetMacro(DrawColor, float);
  
  void FillBox(int min0, int max0, int min1, int max1);
  void FillTube(int x0, int y0, int x1, int y1, float radius);
  void FillTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
  void DrawCircle(int c0, int c1, float radius);
  void DrawPoint(int p0, int p1);
  void DrawSegment(int x0, int y0, int x1, int y1);
  void DrawSegment3D(float *p0, float *p1);

  void FillPixel(int x, int y);
  
protected:
  vtkImageRegion *ImageRegion;
  float DrawColor[VTK_IMAGE_DIMENSIONS];
  
  int ClipSegment(int &a0, int &a1, int &b0, int &b1);
};



#endif


