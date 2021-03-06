/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 Data types, headers, and declarations for ZOModel.

*/

#ifndef ZOM_ODDS_HEADERS
#define ZOM_ODDS_HEADERS

// Custom header files

#include "ZOMApp.h"

// Data structures

struct ZOMOddsSettings
{
  private:
    // General world statistics
    double zomPer_;
    double fightPer_;
    double numZom_;
  public:
    // Constructors
    ZOMOddsSettings();
    ZOMOddsSettings(double zombie, double fight);
    // Destructor
    ~ZOMOddsSettings();
    // Functions
    void runCalc();
    int getNumZom();
    // Debug routines
    void printResults();
};

#endif
