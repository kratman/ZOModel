/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 Data types, headers, and declarations for ZOModel.

*/

#ifndef ZOM_APP_HEADERS
#define ZOM_APP_HEADERS

// Standard libraries

#ifdef _OPENMP
  #include <omp.h>
#endif
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>

// Namespaces

using namespace std;

// Hard coded settings

#define ZOM_MAX_PERCENT (100.0)
#define ZOM_MIN_PERCENT (0.0)
#define ZOM_MONTHS_PER_YEAR (12)
#define ZOM_DOUBLE_ZERO (0.0)
#define ZOM_DOUBLE_ONE (1.0)
#define ZOM_INT_ZERO (0)
#define ZOM_INT_ONE (1)

#endif
