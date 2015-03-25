/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

*/

//Header
#include "Undead.h"
#include "Brains.h"

int main()
{
  //Set random seed
  srand((unsigned)time(0)); //Serial only random numbers
  //End of section

  //Initialize variables
  ZOMSettings Plague; //Statistics for the zombie infestation
  vector<MeatBag> SurvHumans; //List of surviving humans
  int DayCount = 0; //Counter for the days
  //End of section

  //Read input and check for errors
  PrintFancyTitle();
  ZOMInput(SurvHumans,Plague);
  ZOMErrorChecker(SurvHumans,Plague);
  //End of section

  //Run simulation
  ZOMPrint(DayCount,Plague);
  while (((Plague.Pop > 0) and (Plague.Zombies > 0)) or (DayCount == 0))
  {
    DayCount += 1;
    ZOMUpdate(SurvHumans,Plague);
    ZOMPrint(DayCount,Plague);
  }
  //End of section

  //Epilogue
  cout << '\n';
  cout << "The end?";
  cout << '\n';
  cout << '\n';
  if (Plague.Pop == 0)
  {
    cout << "Yes. Everyone is dead...";
    cout << '\n';
    cout << '\n';
  }
  //End of section

  //Flush and exit
  cout.flush();
  return 0;
};
