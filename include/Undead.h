/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 Data types, headers, and declarations for ZOModel.

*/

#ifndef ZOM_HEADERS
#define ZOM_HEADERS

// Custom header files

#include "ZOMApp.h"
#include "ZOMSim.h"

// Namespaces

using namespace std;

// Function declarations

inline void PrintFancyTitle();

inline void ZOMInput(ZOMSimSettings&);

inline void ZOMPrint(ZOMSimSettings&);

inline void ZOMInitRand(int);

inline double ZOMRand();

inline int ZOMRandInt(int);

#endif

