/*
 * Medical Image Registration ToolKit (MIRTK)
 *
 * Copyright 2013-2016 Imperial College London
 * Copyright 2013-2016 Andreas Schuh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mirtk/Config.h" // MIRTK_USE_FLOAT_BY_DEFAULT

#include "mirtk/Vtk.h"
#include "mirtk/Stream.h"

#include "vtkCharArray.h"
#include "vtkUnsignedCharArray.h"
#include "vtkShortArray.h"
#include "vtkUnsignedShortArray.h"
#include "vtkIntArray.h"
#include "vtkUnsignedIntArray.h"
#include "vtkFloatArray.h"
#include "vtkDoubleArray.h"
#include "vtkIdTypeArray.h"


namespace mirtk {


// -----------------------------------------------------------------------------
vtkSmartPointer<vtkDataArray> NewVTKDataArray(int vtkType)
{
  switch (vtkType) {
    case VTK_VOID: {
      #if MIRTK_USE_FLOAT_BY_DEFAULT
        return vtkSmartPointer<vtkFloatArray>::New();
      #else
        return vtkSmartPointer<vtkDoubleArray>::New();
      #endif
    } break;
    case VTK_CHAR:           return vtkSmartPointer<vtkCharArray>::New();
    case VTK_UNSIGNED_CHAR:  return vtkSmartPointer<vtkUnsignedCharArray>::New();
    case VTK_SHORT:          return vtkSmartPointer<vtkShortArray>::New();
    case VTK_UNSIGNED_SHORT: return vtkSmartPointer<vtkUnsignedShortArray>::New();
    case VTK_INT:            return vtkSmartPointer<vtkIntArray>::New();
    case VTK_UNSIGNED_INT:   return vtkSmartPointer<vtkUnsignedIntArray>::New();
    case VTK_FLOAT:          return vtkSmartPointer<vtkFloatArray>::New();
    case VTK_DOUBLE:         return vtkSmartPointer<vtkDoubleArray>::New();
    case VTK_ID_TYPE:        return vtkSmartPointer<vtkIdTypeArray>::New();
    default:
      cerr << "Invalid VTK data type: " << vtkType << endl;
      exit(1);
  }
}


} // namespace mirtk
