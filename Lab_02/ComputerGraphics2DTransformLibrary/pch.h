// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_CG_2D_TRANSFORM_LIBRARY_H
#define PCH_CG_2D_TRANSFORM_LIBRARY_H

// add headers that you want to pre-compile here
#include "framework.h"

#ifdef COMPUTERGRAPHICS2DTRANSFORMLIBRARY_EXPORTS
#define CG_2D_TRANSFORM_LIBRARY_API __declspec(dllexport)
#else
#define CG_2D_TRANSFORM_LIBRARY_API __declspec(dllimport)
#endif

#endif //PCH_CG_2D_TRANSFORM_LIBRARY_H
