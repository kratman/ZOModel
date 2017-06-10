#ifndef ZOM_SIM_HEADERS
#define ZOM_SIM_HEADERS

struct ZOMSettings
{
  // General world statistics
  int Pop; // Human population
  int Zombies; // Zombie population
  int Bitten; // Number of bitten humans
  double Wprob; // Probability that the human kills the zombie
  double Eprob; // Probability that the zombie eats the human
  double Bprob; // Probability that the human was bitten
  double Mprob; // Probability for mercy
  double Iprob; // Initial infection rate
};

struct MeatBag
{
  // Useless structure for humans that are not yet food
  bool Bitten;
};

#endif
