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
#include "ZOMSim.cpp"
#include "Brains.cpp"

// Command line interface main

int main()
{
  // Set random seed
  ZOMInitRand((unsigned)time(0)); // Serial only random numbers
  // End of section

  // Initialize variables
  ZOMSimSettings zomPlague; // Statistics for the zombie infestation
  // End of section

  // Read input and check for errors
  PrintFancyTitle();
  ZOMInput(zomPlague);
  zomPlague.errorChecker();
  // End of section

  // Run simulation
  ZOMPrint(zomPlague);
  while (((zomPlague.getPop() > 0) and (zomPlague.getZom() > 0))
         or (zomPlague.getDays() == 0))
  {
    zomPlague.dailyUpdate();
    ZOMPrint(zomPlague);
  }
  // End of section

  // Epilogue
  cout << '\n';
  cout << "The end?";
  cout << '\n';
  cout << '\n';
  if (zomPlague.getPop() == 0)
  {
    cout << "Yes. Everyone is dead...";
    cout << '\n';
    cout << '\n';
  }
  // End of section

  // Flush and exit
  cout.flush();
  return 0;
};

