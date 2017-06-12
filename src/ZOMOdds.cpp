// Header files

#include "ZOMApp.h"

// Constructors

ZOMOddsSettings::ZOMOddsSettings()
{
  zomPer_ = 0.0;
  fightPer_ = 0.0;
  numZom_ = 0.0;
};

ZOMOddsSettings::ZOMOddsSettings(double zombie, double fight)
{
  zomPer_ = zombie;
  fightPer_ = fight;
  numZom_ = 0.0;
};

ZOMOddsSettings::~ZOMOddsSettings()
{
  return;
};

// Functions

inline int ZOMOddsSettings::runCalc()
{
  numZom_ = zomPer_;
  numZom_ /= (ZOM_MAX_PERCENT-zomPer_);
  numZom_ /= (fightPer_/ZOM_MAX_PERCENT);
  numZom_ = ceil(numZom_);
  return ((int)numZom_);
};

