// Header files

#include "Undead.h"

// Constructors

ZOMSimSettings::ZOMSimSettings()
{
  pop_ = 0;
  zombies_ = 0;
  bitten_ = 0;
  days_ = 0;
  winProb_ = 0.0;
  eatProb_ = 0.0;
  biteProb_ = 0.0;
  mercyProb_ = 0.0;
  infectProb_ = 0.0;
};

ZOMSimSettings::ZOMSimSettings(int hum, int zom, double win, double eat,
                               double bite, double mercy, double infect)
{
  // Initialize variables
  pop_ = hum;
  zombies_ = zom;
  bitten_ = 0;
  days_ = 0;
  winProb_ = win;
  eatProb_ = eat;
  biteProb_ = bite;
  mercyProb_ = mercy;
  infectProb_ = infect;

  // Initialize the human population
  double randnum;
  for (int i = 0; i < pop_; i++)
  {
    MeatBag tmp;
    // Determine if the human is infected
    randnum = ZOMRand();
    if (randnum < infectProb_)
    {
      tmp.bitten = 1;
    }
    else
    {
      tmp.bitten = 0;
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
  bool doQuit = 0;
  if (pop_ < 0)
  {
    cout << "Negative humans? Do you know how numbers work?";
    cout << '\n';
    doQuit = 1;
  }
  if (zombies_ < 0)
  {
    cout << "Negative zombies? Do you know how numbers work?";
    cout << '\n';
    doQuit = 1;
  }
  if (winProb_ <= 0.0)
  {
    cout << "Humans cannot win any fights?!?!";
    cout << '\n';
    cout << "Running that type of simulation is brutal and pointless...";
    cout << '\n';
    doQuit = 1;
  }
  if ((winProb_ > 1) or (eatProb_ > 1) or
     (biteProb_ > 1) or (mercyProb_ > 1))
  {
    cout << "Probabilities cannot be greater than 1.";
    cout << '\n';
    cout << "You should take some math classes...";
    cout << '\n';
  }
  if ((winProb_ < 0) or (eatProb_ < 0) or
     (biteProb_ < 0) or (mercyProb_ < 0))
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
  int newZombies = 0;
  // Ready... FIGHT!!!
  for (int z = 0; z < zombies_ ; z++)
  {
    // Pick a random human
    if (survHumans_.size() == 0)
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
        newZombies += 1;
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
        tempHumans[h].bitten = 1;
      }
    }
  }
  // Those about to die salute you
  for (unsigned int i = 0; i < survHumans_.size(); i++)
  {
    if (survHumans_[i].bitten)
    {
      pop_ -= 1;
      randNum = ZOMRand();
      if (randNum > mercyProb_)
      {
        newZombies += 1;
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

