/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

*/

//Load Java packages
import javax.swing.*;

//Define initial class
public class ZOModelApp
{
  //Main
  public static void main(String[] args)
  {
    //Initialize ZOMOdds variables
    double oddsZomPer = 0.0; //Zombie population for ZOMOdds
    double oddsFightPer = 0.0; //Fighting percentage for ZOMOdds
    double oddsNumZom = 0.0; //Output for ZOMOdds
    double oddsWinPer = 0.0; //Output for ZOMOdds

    //Initialize ZOMlog variables
    double logHPop = 0.0; //Human population for ZOMlog
    double logZPop = 0.0; //Zombie population for ZOMlog
    double logYears = 0.0; //Simulation time in years for ZOMlog
    double logMonths = 0.0; //Simulation time in months for ZOMlog
    double logPopRate = 0.0; //Population growth rate for ZOMlog
    double logWinRate = 0.0; //Human win rate for ZOMlog
    double logInfRate = 0.0; //Natural infection rate for ZOMlog
    double logMerRate = 0.0; //Mercy rate for ZOMlog
    double logEroRate = 0.0; //Zombie erosion rate for ZOMlog
    double logCompScl = 10000400.0; //Human-human cooperation for ZOMlog
    double logApocCyc = 1200000000.0; //Months between extinctions for ZOMlog
    boolean logZomApoc = true; //ZOMlog flag to check for zombies
    boolean logApoc = false; //ZOMlog flag to check for an extinction event
    int logExtMon = 0; //Extinction month output for ZOMlog
    double logMaxHum = 0; //Maximum number of humans output for ZOMlog
    double logMaxZom = 0; //Maximum number of zombies output for ZOMlog

    //Initialize ZOModel variables


    //Create interactive window
    JFrame intFrame = new JFrame("ZOModelApp");
    intFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    //Read input from the interactive window


    //* ZOMOdds calculations *//
    oddsNumZom = (100.0/(100.0-oddsZomPer))/(oddsFightPer/100.0);
    oddsNumZom = Math.ceil(oddsNumZom);
    oddsWinPer = 100.0*oddsNumZom/(oddsNumZom+1.0);

    //* ZOMlog calculations *//
    logMonths = 12*logYears; //Switch from years to months
    //Adjust growth rate for exponential growth
    logPopRate += 1;
    logPopRate = Math.pow(logPopRate,(1.0/12.0));
    logPopRate -= 1;
    //Adjust additive rates
    logInfRate /= 12.0;
    logEroRate /= 12.0;
    //Perform simulation
    for (int i=0;i<logYears;i++)
    {
      //Create temporary variables
      double newHPop = 0;
      double newZPop = 0;
      //Update stats
      if (logHPop > logMaxHum)
      {
        logMaxHum = logHPop;
      }
      if (logZPop > logMaxZom)
      {
        logMaxZom = logZPop;
      }
      if (logHPop > 0)
      {
        logExtMon = i;
      }
      //End simulation if both humans and zombies are gone
      
      //Update human population
      newHPop = logHPop; //Old population
      newHPop += logPopRate*logHPop; //Sex
      newHPop -= (logPopRate/logCompScl)*logHPop*logHPop; //Human-human
      newHPop -= (1.0-logWinRate)*logZPop; //Human-zombie
      newHPop -= logInfRate*logHPop; //Human-nature
      //Update zombie population
      newZPop = logZPop; //Old population
      if (logHPop > 0.001)
      {
        newZPop += (1.0-logMerRate)*(1.0-logWinRate)*logZPop; //Zombie-human
        newZPop += (1.0-logMerRate)*logInfRate*logHPop; //Human-nature
        newZPop -= logWinRate*logZPop; //Zombie-human
      }
      newZPop -= logEroRate*logZPop; //Zombie-nature
      //Check for a second apocalypse
      
      //Prevent impossible populations
      if (newHPop < 0.001)
      {
        newHPop = 0;
      }
      if (newZPop < 0.001)
      {
        newZPop = 0;
      }
      //Save populations
      logHPop = newHPop;
      logZPop = newZPop;
    }

    //* ZOModel calculations *//


    //Show output in the interactive window


    //Exit
    return;
  }
}

