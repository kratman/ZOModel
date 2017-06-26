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

VOMSpreadSettings::VOMSpreadSettings()
{
  feedDays_ = ZOM_DOUBLE_ZERO;
  deathPer_ = ZOM_DOUBLE_ZERO;
  numDays_ = ZOM_DOUBLE_ZERO;
  numVamp_ = ZOM_DOUBLE_ZERO;
  return;
};

VOMSpreadSettings::VOMSpreadSettings(double feed, double death)
{
  feedDays_ = feed;
  deathPer_ = death/ZOM_MAX_PERCENT;
  numDays_ = ZOM_DOUBLE_ZERO;
  numVamp_ = ZOM_DOUBLE_ONE;
  return;
};

VOMSpreadSettings::~VOMSpreadSettings()
{
  return;
};

// Functions

void VOMSpreadSettings::runCalc()
{
  numDays_ = ZOM_DOUBLE_ZERO;
  numVamp_ = ZOM_DOUBLE_ONE;
  while (numVamp_ < VOM_HUMAN_POP)
  {
    numVamp_ += ceil(numVamp_ * (ZOM_DOUBLE_ONE - deathPer_));
    numDays_ += feedDays_;
  }
  return;
};

int VOMSpreadSettings::getDays()
{
  return ((int)numDays_);
};

void VOMSpreadSettings::printResults()
{
  // Print header
  cout << '\n';
  cout << "--- VOMSpread test ---" << '\n';

  // Print settings
  cout << '\n';
  cout << "Settings" << '\n';
  cout << "--------" << '\n';
  cout << "  *Time between vampire feedings: " << feedDays_;
  cout << " days" << '\n';
  cout << "  *Percent of victims killed: " << (ZOM_MAX_PERCENT*deathPer_);
  cout << "%" << '\n';
  cout << '\n';

  // Print results
  cout << "Results" << '\n';
  cout << "-------" << '\n';
  cout << "  *All humans have become vampires in ";
  cout << numDays_ << " days." << '\n' << '\n';

  return;
};
