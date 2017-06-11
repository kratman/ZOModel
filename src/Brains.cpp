/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 The algorithmic brains of ZOModel.

*/

#ifndef ZOM_BRAINS
#define ZOM_BRAINS

#include "Undead.h"

// Function definitions

inline void ZOMInitRand(int seed)
{
  srand(seed); // Serial only random numbers
  return;
};

inline double ZOMRand()
{
  return (((double)rand())/((double)RAND_MAX));
};

inline int ZOMRandInt(int range)
{
  return (rand()%range);
};

inline void PrintFancyTitle()
{
  cout << '\n';
  cout << "#######################################";
  cout << "########################################";
  cout << '\n';
  cout << "#                                      ";
  cout << "                                       #";
  cout << '\n';
  cout << "#                      ";
  cout << "ZOModel: Zombie Outbreak Modeling";
  cout << "                      #";
  cout << '\n';
  cout << "#                                      ";
  cout << "                                       #";
  cout << '\n';
  cout << "#######################################";
  cout << "########################################";
  cout << '\n' << '\n';
  cout.flush();
  return;
};

inline void ZOMInput(ZOMSimSettings& zomPlague)
{
  // Temporary variables
  int initPop;
  int initZom;
  double initWin;
  double initEat;
  double initBite;
  double initMercy;
  double initInfect;
  // Function to collect settings
  cout << '\n';
  // Read settings
  cout << "Initial population: ";
  cout << '\n';
  cin >> initPop;
  cout << "Initial zombies: ";
  cout << '\n';
  cin >> initZom;
  cout << "Prob. that a human will win a fight: ";
  cout << '\n';
  cin >> initWin;
  cout << "Prob. that a zombie is super-hungry: ";
  cout << '\n';
  cin >> initEat;
  cout << "Prob. that a human gets bitten: ";
  cout << '\n';
  cin >> initBite;
  cout << "Mercy probability: ";
  cout << '\n';
  cin >> initMercy;
  cout << "Percent infected: ";
  cout << '\n';
  cin >> initInfect;
  // Save settings
  zomPlague = ZOMSimSettings(initPop,initZom,initWin,initEat,
                             initBite,initMercy,initInfect);
  // Return to the simulation
  cout << '\n';
  return;
};

inline void ZOMPrint(ZOMSimSettings& zomPlague)
{
  // Function to print the current progress of the outbreak
  cout << " | Day: " << zomPlague.getDays();
  cout << " | Humans: " << zomPlague.getPop();
  cout << " | Zombies: " << zomPlague.getZom();
  cout << '\n';
  return;
};

#endif

