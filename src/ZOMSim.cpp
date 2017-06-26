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

// Constructors

ZOMSimSettings::ZOMSimSettings()
{
  pop_ = ZOM_INT_ZERO;
  zombies_ = ZOM_INT_ZERO;
  bitten_ = ZOM_INT_ZERO;
  days_ = ZOM_INT_ZERO;
  winProb_ = ZOM_DOUBLE_ZERO;
  eatProb_ = ZOM_DOUBLE_ZERO;
  biteProb_ = ZOM_DOUBLE_ZERO;
  mercyProb_ = ZOM_DOUBLE_ZERO;
  infectProb_ = ZOM_DOUBLE_ZERO;
  return;
};

ZOMSimSettings::ZOMSimSettings(int hum, int zom, double win, double eat,
                               double bite, double mercy, double infect)
{
  // Initialize variables
  pop_ = hum;
  zombies_ = zom;
  bitten_ = ZOM_INT_ZERO;
  days_ = ZOM_INT_ZERO;
  winProb_ = win;
  eatProb_ = eat;
  biteProb_ = bite;
  mercyProb_ = mercy;
  infectProb_ = infect;

  // Initialize the human population
  double randnum;
  for (int i = ZOM_INT_ZERO; i < pop_; i++)
  {
    MeatBag tmp;
    // Determine if the human is infected
    randnum = ZOMRand();
    if (randnum < infectProb_)
    {
      tmp.bitten = true;
    }
    else
    {
      tmp.bitten = false;
    }
    // Add human to the population
    survHumans_.push_back(tmp);
  }
  return;
};

ZOMSimSettings::~ZOMSimSettings()
{
  return;
};

// Functions

int ZOMSimSettings::getPop()
{
  return pop_;
};

int ZOMSimSettings::getZom()
{
  return zombies_;
};

int ZOMSimSettings::getDays()
{
  return days_;
};

void ZOMSimSettings::errorChecker()
{
  // Function to check for nonsensical input
  bool doQuit = false;
  if (pop_ < ZOM_INT_ZERO)
  {
    cout << "Negative humans? Do you know how numbers work?";
    cout << '\n';
    doQuit = 1;
  }
  if (zombies_ < ZOM_INT_ZERO)
  {
    cout << "Negative zombies? Do you know how numbers work?";
    cout << '\n';
    doQuit = 1;
  }
  if (winProb_ <= ZOM_DOUBLE_ZERO)
  {
    cout << "Humans cannot win any fights?!?!";
    cout << '\n';
    cout << "Running that type of simulation is brutal and pointless...";
    cout << '\n';
    doQuit = true;
  }
  if ((winProb_ > ZOM_DOUBLE_ONE) or (eatProb_ > ZOM_DOUBLE_ONE) or
     (biteProb_ > ZOM_DOUBLE_ONE) or (mercyProb_ > ZOM_DOUBLE_ONE))
  {
    cout << "Probabilities cannot be greater than 1.";
    cout << '\n';
    cout << "You should take some math classes...";
    cout << '\n';
  }
  if ((winProb_ < ZOM_DOUBLE_ZERO) or (eatProb_ < ZOM_DOUBLE_ZERO) or
     (biteProb_ < ZOM_DOUBLE_ZERO) or (mercyProb_ < ZOM_DOUBLE_ZERO))
  {
    cout << "Probabilities cannot be less than 0.";
    cout << '\n';
    cout << "You should take some math classes...";
    cout << '\n';
  }
  if (doQuit)
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
  cout << "Win probability: " << winProb_ << '\n';
  cout << "Eaten probability: " << eatProb_ << '\n';
  cout << "Bitten probability: " << biteProb_ << '\n';
  cout << "Mercy probability: " << mercyProb_ << '\n';
  cout << "Infected probability: " << infectProb_ << '\n';
  cout << '\n';
  return;
};

void ZOMSimSettings::dailyUpdate()
{
  // Function for simulating the daily zombie attacks
  double randNum;
  vector<MeatBag> tempHumans;
  vector<MeatBag> survivors;
  tempHumans = survHumans_;
  int newZombies = ZOM_INT_ZERO;
  // Ready... FIGHT!!!
  for (int z = ZOM_INT_ZERO; z < zombies_ ; z++)
  {
    // Pick a random human
    if (survHumans_.size() == ZOM_INT_ZERO)
    {
      break;
    }
    int h = ZOMRandInt(survHumans_.size());
    // Check if the human loses
    randNum = ZOMRand();
    if (randNum > winProb_)
    {
      // Remove human
      pop_ -= 1;
      survHumans_.erase(survHumans_.begin()+h);
      tempHumans.erase(tempHumans.begin()+h);
      // Check for reanimation
      randNum = ZOMRand();
      if (randNum > eatProb_)
      {
        newZombies += ZOM_INT_ONE;
      }
    }
    else
    {
      newZombies -= 1; //Remove a zombie
      // Check if the human was bitten
      randNum = ZOMRand();
      if (randNum < biteProb_)
      {
        // Confirm bite
        tempHumans[h].bitten = true;
      }
    }
  }
  // Those about to die salute you
  for (unsigned int i = ZOM_INT_ZERO; i < survHumans_.size(); i++)
  {
    if (survHumans_[i].bitten)
    {
      pop_ -= ZOM_INT_ONE;
      randNum = ZOMRand();
      if (randNum > mercyProb_)
      {
        newZombies += ZOM_INT_ONE;
      }
    }
    else
    {
      // Save bite information
      MeatBag tmp;
      tmp = tempHumans[i];
      survivors.push_back(tmp);
    }
  }
  // Copy data and end the day
  zombies_ += newZombies;
  survHumans_ = survivors;
  days_++;
  return;
};

