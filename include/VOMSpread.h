/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 Data types, headers, and declarations for ZOModel.

*/

#ifndef VOM_SPREAD_HEADERS
#define VOM_SPREAD_HEADERS

// Hard coded settings

#define VOM_HUMAN_POP (7000000000)
#define VOM_MIN_DAYS (0.1)
#define VOM_MAX_DEATH_PER (99.9)

// Custom header files

#include "ZOMApp.h"

// Data structures

struct VOMSpreadSettings
{
  private:
    // General world statistics
    double feedDays_;
    double deathPer_;
    double numDays_;
    double numVamp_;
  public:
    // Constructors
    VOMSpreadSettings();
    VOMSpreadSettings(double feed, double death);
    // Destructor
    ~VOMSpreadSettings();
    // Functions
    void runCalc();
    int getDays();
    // Debug routines
    void printResults();
};

#endif
