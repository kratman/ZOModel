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

//Function definitions
void PrintFancyTitle()
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
  cout << "                     #";
  cout << "#                                      ";
  cout << "                                       #";
  cout << '\n';
  cout << "#######################################";
  cout << "########################################";
  cout << '\n' << '\n';
  cout.flush();
  return;
};

void ZOMInput(vector<MeatBag>& SurvHumans, ZOMSettings& Plague)
{
  //Function to collect settings
  cout << '\n';
  //Read settings
  cout << "Initial population: ";
  cout << '\n';
  cin >> Plague.Pop;
  cout << "Initial zombies: ";
  cout << '\n';
  cin >> Plague.Zombies;
  cout << "Prob. that a human will win a fight: ";
  cout << '\n';
  cin >> Plague.Wprob;
  cout << "Prob. that a zombie is super-hungry: ";
  cout << '\n';
  cin >> Plague.Eprob;
  cout << "Prob. that a human gets bitten: ";
  cout << '\n';
  cin >> Plague.Bprob;
  cout << "Mercy probability: ";
  cout << '\n';
  cin >> Plague.Mprob;
  //Return to the simulation
  cout << '\n';
  return;
};

void ZOMErrorChecker(ZOMSettings& Plague)
{
  //Function to check for nonsensical input
  bool DoQuit = 0;
  if (Plague.Pop == 0)
  {
    cout << "Zero humans? This will be quick...";
    cout << '\n';
    DoQuit = 1;
  }
  if (Plague.Zombies == 0)
  {
    cout << "Zero zombies? This will be quick...";
    cout << '\n';
    DoQuit = 1;
    DoQuit = 1;
  }
  if (Plague.Pop < 0)
  {
    cout << "Negative humans? Do you know how numbers work?";
    cout << '\n';
    DoQuit = 1;
  }
  if (Plague.Zombies < 0)
  {
    cout << "Negative zombies? Do you know how numbers work?";
    cout << '\n';
    DoQuit = 1;
  }
  if (Plague.Wprob <= 0.0)
  {
    cout << "Humans cannot win any fights?!?!";
    cout << '\n';
    cout << "Running that type of simulation is brutal and pointless...";
    cout << '\n';
    DoQuit = 1;
  }
  if ((Plague.Wprob > 1) or (Plague.Eprob > 1) or
     (Plague.Bprob > 1) or (Plague.Mprob > 1))
  {
    cout << "Probabilities cannot be greater than 1!";
    cout << '\n';
    cout << "You should take some math classes...";
    cout << '\n';
  }
  if (DoQuit)
  {
    cout << '\n';
    cout.flush();
    exit(0);
  }
  cout << "Nothing seems to be amiss...";
  cout << '\n';
  cout << " Well... besides the reanimated corpses...";
  cout << '\n';
  cout << '\n';
  cout << "Win probability: " << Plague.Wprob << '\n';
  cout << "Eaten probability: " << Plague.Wprob << '\n';
  cout << "Bitten probability: " << Plague.Wprob << '\n';
  cout << "Mercy probability: " << Plague.Wprob << '\n';
  cout << '\n';
  return;
};

void ZOMUpdate(vector<MeatBag>& SurvHumans, ZOMSettings& Plague)
{
  //Function for simulating the daily zombie attacks
  double randnum;
  vector<MeatBag> TempHumans;
  vector<MeatBag> Survivors;
  TempHumans = SurvHumans;
  int NewZombies = 0;
  //Ready... FIGHT!!!
  for (int z=0;z<Plague.Zombies;z++)
  {
    //Pick a random human
    int h = (rand()%SurvHumans.size());
    //Check if the human loses
    randnum = (((double)rand())/((double)RAND_MAX));
    if (randnum > Plague.Wprob)
    {
      //Remove human
      SurvHumans.erase(SurvHumans.begin()+h);
      TempHumans.erase(SurvHumans.begin()+h);
      //Check for reanimation
      randnum = (((double)rand())/((double)RAND_MAX));
      if (randnum > Plague.Eprob)
      {
        NewZombies += 1;
      }
    }
    else
    {
      NewZombies -= 1; //Remove a zombie
      //Check if the human was bitten
      randnum = (((double)rand())/((double)RAND_MAX));
      if (randnum < Plague.Bprob)
      {
        //Confirm bite
        TempHumans[h].Bitten = 1;
      }
    }
  }
  //Those about to die salute you
  for (int i=0;i<SurvHumans.size();i++)
  {
    if (SurvHumans[i].Bitten)
    {
      Plague.Pop -= 1;
      randnum = (((double)rand())/((double)RAND_MAX));
      if (randnum > Plague.Mprob)
      {
        Plague.Zombies += 1;
      }
    }
    else
    {
      //Save bite information
      MeatBag tmp;
      tmp = TempHumans[i];
      Survivors.push_back(tmp);
    }
  }
  //Copy data and end the day
  Plague.Zombies += NewZombies;
  SurvHumans = Survivors;
  return;
};

void ZOMPrint(int& DayCount, ZOMSettings& Plague)
{
  //Function to print the current progress of the outbreak
  cout << " Day: " << DayCount;
  cout << " Humans: " << Plague.Pop;
  cout << " Zombies: " << Plague.Zombies;
  cout << '\n';
  return;
};

#endif
