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
    int runCalc();
};

#endif
