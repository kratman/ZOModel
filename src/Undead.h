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
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <complex>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>
#include <sys/stat.h>
#include <algorithm>
using namespace std;

//Custom data types
struct ZOMSettings
{
  //General world statistics
  int Pop; //Human population
  int Zombies; //Zombie population
  int Bitten; //Number of bitten humans
  double Wprob; //Probability that the human kills the zombie
  double Eprob; //Probability that the zombie eats the human
  double Bprob; //Probability that the human was bitten
  double Mprob; //Probability for mercy
};

struct MeatBag
{
  //Useless structure for humans that are not yet food
  bool Bitten;
};

//Function declarations
void PrintFancyTitle();

void ZOMInput(vector<MeatBag>&,ZOMSettings&);

void ZOMErrorChecker(vector<MeatBag>&,ZOMSettings&);

void ZOMUpdate(vector<MeatBag>&,ZOMSettings&);

void ZOMPrint(int&,ZOMSettings&);

#endif
