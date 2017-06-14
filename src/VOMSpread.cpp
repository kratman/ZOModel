// Header files

#include "ZOMApp.h"
#include "VOMSpread.h"

// Constructors

VOMSpreadSettings::VOMSpreadSettings()
{
  feedDays_ = 0.0;
  deathPer_ = 0.0;
  numDays_ = 0.0;
  numVamp_ = 0.0;
};

VOMSpreadSettings::VOMSpreadSettings(double feed, double death)
{
  feedDays_ = feed;
  deathPer_ = death/ZOM_MAX_PERCENT;
  numDays_ = 0.0;
  numVamp_ = 0.0;
};

VOMSpreadSettings::~VOMSpreadSettings()
{
  return;
};

// Functions

inline int VOMSpreadSettings::runCalc()
{
  while (numVamp_ < VOM_HUMAN_POP)
  {
    numVamp_ += ceil(numVamp_*(VOM_FLOAT_ONE-deathPer_));
    numDays_ += feedDays_;
  }
  return numDays_;
};

