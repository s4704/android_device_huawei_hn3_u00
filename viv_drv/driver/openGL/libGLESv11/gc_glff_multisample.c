/****************************************************************************
*
*    Copyright (c) 2005 - 2012 by Vivante Corp.  All rights reserved.
*
*    The material in this file is confidential and contains trade secrets
*    of Vivante Corporation. This is proprietary information owned by
*    Vivante Corporation. No part of this work may be disclosed,
*    reproduced, copied, transmitted, or used in any way for any purpose,
*    without the express written permission of Vivante Corporation.
*
*****************************************************************************/




#include "gc_glff_precomp.h"

#define _GC_OBJ_ZONE glvZONE_TRACE

/******************************************************************************\
*********************** Support Functions and Definitions **********************
\******************************************************************************/

/*******************************************************************************
**
**  glfQueryMultisampleState
**
**  Queries multisample state values.
**
**  INPUT:
**
**      Context
**          Pointer to the current context.
**
**      Name
**          Specifies the symbolic name of the state to get.
**
**      Type
**          Data format.
**
**  OUTPUT:
**
**      Value
**          Points to the data.
*/

GLboolean glfQueryMultisampleState(
    glsCONTEXT_PTR Context,
    GLenum Name,
    GLvoid* Value,
    gleTYPE Type
    )
{
    GLboolean result = GL_TRUE;
    gcmHEADER_ARG("Context=0x%x Name=0x%04x Value=0x%x Type=0x%04x",
                    Context, Name, Value, Type);


    switch (Name)
    {
    case GL_SAMPLE_BUFFERS:
        glfGetFromInt(
            1,
            Value,
            Type
            );
        break;

    case GL_SAMPLE_COVERAGE_VALUE:
        glfGetFromMutant(
            &Context->multisampleStates.coverageValue,
            Value,
            Type
            );
        break;

    case GL_SAMPLE_COVERAGE_INVERT:
        glfGetFromInt(
            Context->multisampleStates.coverageInvert,
            Value,
            Type
            );
        break;

    case GL_SAMPLES:
        glfGetFromInt(
            1,
            Value,
            Type
            );
        break;

    default:
        result = GL_FALSE;
    }

    gcmFOOTER_ARG("return=%d", result);
    /* Return result. */
    return result;
}


/******************************************************************************\
*********************** Multisample State Management Code **********************
\******************************************************************************/

/*******************************************************************************
**
**  glSampleCoverage
**
**  glSampleCoverage defines a mask to modify the coverage of multisampled pixel
**  fragments. This capability is used for antialiased screen-door transparency
**  and smooth transitions between two renderings of an object (often for
**  level-of-detail management in simulation systems).
**
**  When multisampling is enabled (see glEnable with argument GL_MULTISAMPLE) a
**  ``fragment mask'' is computed for each fragment generated by a primitive.
**  This mask reflects the amount of the pixel covered by the fragment, and
**  determines the frame buffer samples that may be affected by the fragment.
**
**  If conversion of alpha values to masks is enabled (glEnable with argument
**  GL_SAMPLE_ALPHA_TO_MASK), the fragment alpha value is used to generate a
**  temporary modification mask which is then ANDed with the fragment mask.
**  One way to interpret this is as a form of dithering: a multivalued alpha
**  (coverage or opacity) for the whole fragment is converted to simple binary
**  values of coverage at many locations (the samples).
**
**  After conversion of alpha values to masks, if replacement of alpha values
**  is enabled (glEnable with argument GL_SAMPLE_ALPHA_TO_ONE), the fragment's
**  alpha is set to the maximum allowable value.
**
**  Finally, if fragment mask modification is enabled (glEnable with argument
**  GL_SAMPLE_MASK), glSampleCoverage defines an additional modification mask.
**  value is used to generate a modification mask in much the same way alpha
**  was used above. If invert is GL_TRUE, then the modification mask specified
**  by value will be inverted. The final modification mask will then be ANDed
**  with the fragment mask resulting from the previous steps. This can be
**  viewed as an ``override'' control that selectively fades the effects of
**  multisampled fragments.
**
**  Note that glSampleCoverage(value, GL_TRUE) is not necessarily equivalent
**  to glSampleCoverage(1.0 - value, GL_FALSE); due to round-off and other
**  issues, complementing the coverage will not necessarily yield an inverted
**  modification mask.
**
**  INPUT:
**
**      Value
**          Specifies the coverage of the modification mask. The value is
**          clamped to the range [0, 1], where 0 represents no coverage and
**          1 full coverage. The initial value is 1.
**
**      Invert
**          Specifies whether the modification mask implied by value is
**          inverted or not. The initial value is GL_FALSE.
**
**  OUTPUT:
**
**      Nothing.
*/
#ifdef _GC_OBJ_ZONE
#undef _GC_OBJ_ZONE
#endif
#define _GC_OBJ_ZONE    glvZONE_FRAGMENT

#ifndef COMMON_LITE
GL_API void GL_APIENTRY glSampleCoverage(
    GLclampf Value,
    GLboolean Invert
    )
{
    glmENTER2(glmARGFLOAT, Value, glmARGUINT, Invert)
    {
		gcmDUMP_API("${ES11 glSampleCoverage 0x%08X 0x%08X}", *(GLuint*)&Value, Invert);

		glmPROFILE(context, GLES1_SAMPLECOVERAGE, 0);
        glfSetFloatMutant(&context->multisampleStates.coverageValue, Value);
        context->multisampleStates.coverageInvert = Invert;
    }
    glmLEAVE();
}
#endif

GL_API void GL_APIENTRY glSampleCoveragex(
    GLclampx Value,
    GLboolean Invert
    )
{
    glmENTER2(glmARGFIXED, Value, glmARGUINT, Invert)
    {
		gcmDUMP_API("${ES11 glSampleCoveragex 0x%08X 0x%08X}", Value, Invert);

		glmPROFILE(context, GLES1_SAMPLECOVERAGEX, 0);
        glfSetFixedMutant(&context->multisampleStates.coverageValue, Value);
        context->multisampleStates.coverageInvert = Invert;
    }
    glmLEAVE();
}

GL_API void GL_APIENTRY glSampleCoveragexOES(
    GLclampx Value,
    GLboolean Invert
    )
{
    glmENTER2(glmARGFIXED, Value, glmARGUINT, Invert)
    {
		gcmDUMP_API("${ES11 glSampleCoveragexOES 0x%08X 0x%08X}", Value, Invert);

        glfSetFixedMutant(&context->multisampleStates.coverageValue, Value);
        context->multisampleStates.coverageInvert = Invert;
    }
    glmLEAVE();
}
