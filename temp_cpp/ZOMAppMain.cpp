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
    zomLog->runCalc();
  }

  // Return to the app
  return;
};

