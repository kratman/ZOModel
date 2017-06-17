// Header files

#include "ZOMApp.h"
#include "ZOMOdds.h"

// Constructors

ZOMOddsSettings::ZOMOddsSettings()
{
  zomPer_ = 0.0;
  fightPer_ = 0.0;
  numZom_ = 0.0;
  return;
};

ZOMOddsSettings::ZOMOddsSettings(double zombie, double fight)
{
  zomPer_ = zombie;
  fightPer_ = fight;
  numZom_ = 0.0;
  return;
};

ZOMOddsSettings::~ZOMOddsSettings()
{
  return;
};

// Functions

void ZOMOddsSettings::runCalc()
{
  numZom_ = zomPer_;
  numZom_ /= (ZOM_MAX_PERCENT-zomPer_);
  numZom_ /= (fightPer_/ZOM_MAX_PERCENT);
  numZom_ = ceil(numZom_);
  return;
};

int ZOMOddsSettings::getNumZom()
{
  return ((int)numZom_);
};

void ZOMOddsSettings::printResults()
{
  // Print header
  cout << '\n';
  cout << "--- ZOMOdds test ---" << '\n';

  // Print settings
  cout << '\n';
  cout << "Settings" << '\n';
  cout << "--------" << '\n';
  cout << "  *Zombified humans: " << zomPer_;
  cout << "%" << '\n';
  cout << "  *Survivors in the fight : " << fightPer_;
  cout << "%" << '\n';
  cout << '\n';

  // Print results
  cout << "Results" << '\n';
  cout << "-------" << '\n';
  cout << "  *Number of zombies each survivor needs to eliminate: ";
  cout << ((int)numZom_) << '\n' << '\n';

  return;
};

