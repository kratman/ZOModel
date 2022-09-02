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
  ZOMLogSettings zomLog(1.0e8,1.0e5,5.0,0.02,0.95,0.005,0.10,0.01);

  // Run simulations
  ZOMRunSim(&zomOdds, &vampSpread, NULL, &zomLog);

  // Print results
  zomOdds.printResults();
  vampSpread.printResults();

  //Exit
  return 0;
};

