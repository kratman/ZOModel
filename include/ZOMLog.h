/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 Data types, headers, and declarations for ZOModel.

*/

#ifndef ZOM_LOG_HEADERS
#define ZOM_LOG_HEADERS

// Hard coded settings

#define ZOM_LOG_COMP_SCALE (10000400)
#define ZOM_LOG_APOC_CYC (1200000000)

// Custom header files

#include "ZOMApp.h"

// Data structures

class ZOMLogSettings
{
  private:
    double humPop_; // Human population
    double zomPop_; // Zombie population
    double months_; // Simulation time in months
    double popRate_; // Yearly population growth rate
    double winProb_; // Probability that a human beats a zombe
    double infRate_; // Yearly infection rate
    double merProb_; // Probability that the dead are prevented from turning
    double eroRate_; // Yearly rate of zombie destruction due to nature
  public:
    // Constructors
    ZOMLogSettings();
    ZOMLogSettings(double initHum, double initZom, double simYears,
                   double popRate, double winProb, double infRate,
                   double merProb, double eroRate);
    // Destructors
    ~ZOMLogSettings();
    // Functions
    double getHumPop();
    double getZomPop();
    void runCalc();
    // Debug routines
    void printResults();
};

#endif
