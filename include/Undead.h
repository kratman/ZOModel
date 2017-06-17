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

void PrintFancyTitle();

void ZOMInput(ZOMSimSettings&);

void ZOMPrint(ZOMSimSettings&);

void ZOMInitRand(int);

double ZOMRand();

int ZOMRandInt(int);

#endif

