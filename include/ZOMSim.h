#ifndef ZOM_SIM_HEADERS
#define ZOM_SIM_HEADERS

// Data structures

struct MeatBag
{
  // Useless structure for humans that are not yet food
  bool bitten;
};

class ZOMSimSettings
{
  private:
    // General world statistics
    int pop_; // Human population
    int zombies_; // Zombie population
    int bitten_; // Number of bitten humans
    int days_;
    double winProb_; // Probability that the human kills the zombie
    double eatProb_; // Probability that the zombie eats the human
    double biteProb_; // Probability that the human was bitten
    double mercyProb_; // Probability for mercy
    double infectProb_; // Initial infection rate
    vector<MeatBag> survHumans_; // List of surviving humans
  public:
    // Constructors
    ZOMSimSettings();
    ZOMSimSettings(int hum, int zom, double win, double eat,
                   double bite, double mercy, double infect);
    // Destructor
    ~ZOMSimSettings();
    // Get functions
    int getPop();
    int getZom();
    int getDays();
    // Update functions
    void errorChecker();
    void dailyUpdate();
};

#endif
