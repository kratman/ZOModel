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

// Input and output routines for the command line interface

void PrintFancyTitle();

void ZOMInput(ZOMSimSettings&);

void ZOMPrint(ZOMSimSettings&);

// Wrappers for random number generators

void ZOMInitRand(int);

double ZOMRand();

int ZOMRandInt(int);

// Java and Go interface functions

void ZOMRunSim();

#endif

