#ifndef VOM_SPREAD_HEADERS
#define VOM_SPREAD_HEADERS

// Hard coded settings

#define VOM_HUMAN_POP (7000000000)
#define VOM_MIN_DAYS (0.1)
#define VOM_MAX_DEATH_PER (99.9)

// Data structures

struct VOMSpreadSettings
{
  double feedDays;
  double deathPer;
  double numDays;
  double numVamp;
};

#endif
