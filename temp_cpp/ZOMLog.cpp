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
  humPop_ = ZOM_DOUBLE_ZERO;
  zomPop_ = ZOM_DOUBLE_ZERO;
  months_ = ZOM_DOUBLE_ZERO;
  popRate_ = ZOM_DOUBLE_ZERO;
  winProb_ = ZOM_DOUBLE_ZERO;
  infRate_ = ZOM_DOUBLE_ZERO;
  merProb_ = ZOM_DOUBLE_ZERO;
  eroRate_ = ZOM_DOUBLE_ZERO;
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
  popRate_ = ZOM_DOUBLE_ONE + popRate;
  popRate_ = pow(popRate_, (ZOM_DOUBLE_ONE / ZOM_MONTHS_PER_YEAR));
  popRate_ -= ZOM_DOUBLE_ONE;

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
  // Statistics counters
  double maxHum = ZOM_DOUBLE_ZERO;
  double maxZom = ZOM_DOUBLE_ZERO;
  double extMonths = ZOM_DOUBLE_ZERO;

  // Flags
  bool endApoc = false;
  bool secondApoc = false;

  for (unsigned int m = ZOM_INT_ZERO; ((m < months_) && (endApoc == false));
       m++)
  {
    // Update statistics
    maxHum = max(humPop_, maxHum);
    maxZom = max(zomPop_, maxZom);
    if (humPop_ > ZOM_DOUBLE_ZERO)
    {
      extMonths = (double)m;
    }

    // Check if all humans and zombies have died
    if ((humPop_ < ZOM_LOG_MIN_POP) && (zomPop_ < ZOM_LOG_MIN_POP))
    {
      endApoc = true;
    }

    // Save the current population sizes
    double newHumPop = humPop_;
    double newZomPop = zomPop_;

    // Update human population
    newHumPop += popRate_ * humPop_;
    newHumPop -= (humPop_ * humPop_ * popRate_) / ZOM_LOG_COMP_SCALE;
    newHumPop -= (ZOM_DOUBLE_ONE - winProb_) * zomPop_;
    newHumPop -= (infRate_ * humPop_);

    // Update zombie population
    if (humPop_ > ZOM_LOG_MIN_POP)
    {
      newZomPop += zomPop_ * (ZOM_DOUBLE_ONE - winProb_)
                   * (ZOM_DOUBLE_ONE - merProb_);
      newZomPop += humPop_ * infRate_ * (ZOM_DOUBLE_ONE - merProb_);
      newZomPop -= winProb_ * zomPop_;
    }
    newZomPop -= eroRate_ * zomPop_;

    // Check for a second apocalypse
    if (secondApoc)
    {
      newHumPop = ZOM_DOUBLE_ZERO;
      newZomPop *= ZOM_LOG_SEC_APOC_SCALE;
    }

    // Prevent impossible populations
    if (newHumPop < ZOM_LOG_MIN_POP)
    {
      newHumPop = ZOM_DOUBLE_ZERO;
    }
    if (newZomPop < ZOM_LOG_MIN_POP)
    {
      newZomPop = ZOM_DOUBLE_ZERO;
    }

    // Save new populations
    humPop_ = newHumPop;
    zomPop_ = newZomPop;
  }

  // Return to the app
  return;
};

