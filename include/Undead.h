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

#include "ZOMApp.h"
#include "ZOMSim.h"

using namespace std;

// Function declarations
void PrintFancyTitle();

void ZOMInput(vector<MeatBag>&,ZOMSettings&);

void ZOMErrorChecker(vector<MeatBag>&,ZOMSettings&);

void ZOMUpdate(vector<MeatBag>&,ZOMSettings&);

void ZOMPrint(int&,ZOMSettings&);

#endif

