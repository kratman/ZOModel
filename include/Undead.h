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

inline void PrintFancyTitle();

inline void ZOMInput(vector<MeatBag>&,ZOMSimSettings&);

void ZOMErrorChecker(vector<MeatBag>&,ZOMSimSettings&);

void ZOMUpdate(vector<MeatBag>&,ZOMSimSettings&);

inline void ZOMPrint(int&,ZOMSimSettings&);

#endif

