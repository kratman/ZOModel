/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

*/

// ZOModel custom headers

#include "Undead.h"

// ZOModel library call for Java or Go interfaces

void ZOMRunSim(ZOMOddsSettings* zomOdds, VOMSpreadSettings* vampSpread,
               ZOMSimSettings* zomSim, ZOMLogSettings* zomLog)
{
  // Run ZOMOdds simulation
  if (zomOdds != NULL)
  {
    zomOdds->runCalc();
  }

  // Run VOMSpread simulation
  if (vampSpread != NULL)
  {
    vampSpread->runCalc();
  }

  // Run ZOModel simulation
  if (zomSim != NULL)
  {
    
  }

  // Run ZOMLog simulation
  if (zomLog != NULL)
  {
    
  }

  // Return to the app
  return;
};

// Test command line interface routine
int main()
{
  // Create test calculations
  ZOMOddsSettings zomOdds(90.0,12.0);
  VOMSpreadSettings vampSpread(7.0,90.0);

  // Run simulations
  ZOMRunSim(&zomOdds, &vampSpread, NULL, NULL);

  // Print results
  zomOdds.printResults();
  vampSpread.printResults();

  //Exit
  return 0;
};
