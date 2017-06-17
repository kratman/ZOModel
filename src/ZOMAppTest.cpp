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

