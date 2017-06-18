/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

*/

// Header files

#include "Undead.h"

// Constructors

ZOMLogSettings::ZOMLogSettings()
{
  // Initialize all variables
  humPop_ = 0.0;
  zomPop_ = 0.0;
  months_ = 0.0;
  popRate_ = 0.0;
  winProb_ = 0.0;
  infRate_ = 0.0;
  merProb_ = 0.0;
  eroRate_ = 0.0;
  return;
};

ZOMLogSettings::ZOMLogSettings(double initHum, double initZom,
                               double simYears, double popRate,
                               double winProb, double infRate,
                               double merProb, double eroRate)
{
  // Save initial populations
  humPop_ = initHum;
  zomPop_ = initZom;

  // Calculate the number of months
  months_ = simYears * ZOM_MONTHS_PER_YEAR;

  // Calculate the monthly population growth rate
  popRate_ = 1.0 + popRate;
  popRate_ = pow(popRate_, (1.0 / ZOM_MONTHS_PER_YEAR));
  popRate_ -= 1.0;

  // Save the probabilities
  winProb_ = winProb;
  merProb_ = merProb;

  // Calculate the approximate monthly rates
  // Note: These rate are additive, so this approximation should be fine
  infRate_ = infRate / ZOM_MONTHS_PER_YEAR;
  eroRate_ = eroRate / ZOM_MONTHS_PER_YEAR;

  return;
};

ZOMLogSettings::~ZOMLogSettings()
{
  return;
};

// Functions

double ZOMLogSettings::getHumPop()
{
  return humPop_;
};

double ZOMLogSettings::getZomPop()
{
  return zomPop_;
};

void ZOMLogSettings::runCalc()
{
  
  return;
};

