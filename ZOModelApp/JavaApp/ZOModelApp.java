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
import java.awt.*;
import javax.swing.*;

//Define initial class
public class ZOModelApp
{
  //Main
  public static void main(String[] args)
  {
    //Initialize general variables
    int framePosCt = 0; //Counter for the position in the frame

    //Initialize ZOMOdds variables
    double oddsZomPer = 90.0; //Zombie population for ZOMOdds
    double oddsFightPer = 50.0; //Fighting percentage for ZOMOdds
    double oddsNumZom = 0.0; //Output for ZOMOdds
    double oddsWinPer = 0.0; //Output for ZOMOdds

    //Initialize ZOMlog variables
    double logHPop = 7000000.0; //Human population for ZOMlog
    double logZPop = 100.0; //Zombie population for ZOMlog
    int logYears = 5; //Simulation time in years for ZOMlog
    int logMonths = 60; //Simulation time in months for ZOMlog
    double logPopRate = 0.02; //Population growth rate for ZOMlog
    double logWinRate = 0.60; //Human win rate for ZOMlog
    double logInfRate = 0.02; //Natural infection rate for ZOMlog
    double logMerRate = 0.10; //Mercy rate for ZOMlog
    double logEroRate = 0.05; //Zombie erosion rate for ZOMlog
    double logCompScl = 10000400.0; //Human-human cooperation for ZOMlog
    double logApocCyc = 1200000000.0; //Months between extinctions for ZOMlog
    int logExtMon = 0; //Extinction month output for ZOMlog
    double logMaxHum = 0; //Maximum number of humans output for ZOMlog
    double logMaxZom = 0; //Maximum number of zombies output for ZOMlog

    //Initialize ZOModel variables


    //Create interactive window
    JFrame intFrame = new JFrame("ZOModelApp");
    intFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    intFrame.setLayout(new BoxLayout(intFrame.getContentPane(),
                       BoxLayout.Y_AXIS));

    //*Read input from the interactive window *//

    //Prompt for ZOMOdds input
    JLabel oddsInputText = new JLabel("Settings for ZOMOdds:",
                                  SwingConstants.LEFT);
    oddsInputText.setFont(oddsInputText.getFont().deriveFont(18.0f));
    //Create slider for oddsZomPer
    JLabel oddsZomPerLabel = new JLabel("Zombified humans (%):");
    oddsZomPerLabel.setFont(oddsZomPerLabel.getFont().deriveFont(12.0f));
    JSlider oddsZomPerSlide = new JSlider(JSlider.HORIZONTAL,0,100,90);
    oddsZomPerSlide.setMajorTickSpacing(10);
    oddsZomPerSlide.setMinorTickSpacing(2);
    oddsZomPerSlide.setPaintTicks(true);
    oddsZomPerSlide.setPaintLabels(true);
    //Create slider for oddsFightPer
    JLabel oddsFightPerLabel = new JLabel("Survivors that can fight (%):");
    oddsFightPerLabel.setFont(oddsFightPerLabel.getFont().deriveFont(12.0f));
    JSlider oddsFightPerSlide = new JSlider(JSlider.HORIZONTAL,0,100,50);
    oddsFightPerSlide.setMajorTickSpacing(10);
    oddsFightPerSlide.setMinorTickSpacing(2);
    oddsFightPerSlide.setPaintTicks(true);
    oddsFightPerSlide.setPaintLabels(true);
    //Add items to the window
    intFrame.add(oddsInputText,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(oddsZomPerLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(oddsZomPerSlide,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(oddsFightPerLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(oddsFightPerSlide,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n\n\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;

    //Prompt for ZOMlog input
    JLabel logInputText = new JLabel("Settings for ZOMlog:",
                                  SwingConstants.LEFT);
    logInputText.setFont(logInputText.getFont().deriveFont(18.0f));
    //Create text box for logHPop
    JLabel logHPopLabel = new JLabel("Human population (thousands):");
    logHPopLabel.setFont(logHPopLabel.getFont().deriveFont(12.0f));
    JTextField logHPopBox = new JTextField("7000000",10);
    //Create text box for logZPop
    JLabel logZPopLabel = new JLabel("Zombie population (thousands):");
    logZPopLabel.setFont(logZPopLabel.getFont().deriveFont(12.0f));
    JTextField logZPopBox = new JTextField("100",10);
    //Create text box for logYears
    JLabel logYearsLabel = new JLabel("Length of simulation (years):");
    logYearsLabel.setFont(logYearsLabel.getFont().deriveFont(12.0f));
    JTextField logYearsBox = new JTextField("5",10);
    //Create slider for logPopRate
    JLabel logPopRateLabel = new JLabel("Fractional population growth rate:");
    logPopRateLabel.setFont(logPopRateLabel.getFont().deriveFont(12.0f));
    JTextField logPopRateBox = new JTextField("0.02",10);
    //Create slider for logWinRate
    JLabel logWinRateLabel = new JLabel("Probability of a human killing a "
                                        +"zombie:");
    logWinRateLabel.setFont(logWinRateLabel.getFont().deriveFont(12.0f));
    JTextField logWinRateBox = new JTextField("0.60",10);
    //Create slider for logInfRate
    JLabel logInfRateLabel = new JLabel("Yearly natural infection rate:");
    logInfRateLabel.setFont(logInfRateLabel.getFont().deriveFont(12.0f));
    JTextField logInfRateBox = new JTextField("0.02",10);
    //Create slider for logMerRate
    JLabel logMerRateLabel = new JLabel("Proability that the infected are "
                                        +"prevented from reanimating:");
    logMerRateLabel.setFont(logMerRateLabel.getFont().deriveFont(12.0f));
    JTextField logMerRateBox = new JTextField("0.10",10);
    //Create slider for logEroRate
    JLabel logEroRateLabel = new JLabel("Yearly natural zombie erosion rate:");
    logEroRateLabel.setFont(logEroRateLabel.getFont().deriveFont(12.0f));
    JTextField logEroRateBox = new JTextField("0.05",10);
    //Add items to the window
    intFrame.add(logInputText,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n\n\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logHPopLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logHPopBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logZPopLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logZPopBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logYearsLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logYearsBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logPopRateLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logPopRateBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logWinRateLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logWinRateBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logInfRateLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logInfRateBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logMerRateLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logMerRateBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logEroRateLabel,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(logEroRateBox,SwingConstants.LEFT,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n\n\n"),SwingConstants.LEFT,framePosCt);
    framePosCt += 1;

    //Prompt for ZOModel input
    JLabel modelInputText = new JLabel("Settings for ZOModel:",
                                  SwingConstants.LEFT);
    modelInputText.setFont(modelInputText.getFont().deriveFont(18.0f));
    //Add items to the window
    intFrame.add(modelInputText,SwingConstants.CENTER,framePosCt);
    framePosCt += 1;
    intFrame.add(new JLabel("\n\n\n"),SwingConstants.CENTER,framePosCt);
    framePosCt += 1;

    //Show window
    intFrame.pack();
    intFrame.setVisible(true);

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
    //Create output array
    double[] logHumans = new double[logMonths];
    double[] logZombies = new double[logMonths];
    String[] logMessages = new String[logMonths];
    for (int i=0;i<logMonths;i++)
    {
      //Initialize arrays to zero
      logHumans[i] = 0;
      logZombies[i] = 0;
      logMessages[i] = "";
    }
    //Perform simulation
    for (int i=0;i<logMonths;i++)
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
      if ((logHPop < 0.001) && (logZPop < 0.001))
      {
        //Set counter to the last month
        i = logMonths;
      }
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
      double randNum = Math.random()*logApocCyc+1;
      if (randNum > logApocCyc)
      {
        newHPop = 0;
        newZPop *= 0.1;
        randNum = Math.random();
        if (randNum > 0.5)
        {
          logMessages[i] = "A comet has struck the Earth!!!";
        }
        else
        {
          logMessages[i] = "An asteroid has struck the Earth!!!";
        }
      }
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
      logHumans[i] = logHPop;
      logZombies[i] = logZPop;
    }

    //* ZOModel calculations *//


    //* Show output in the interactive window *//

    //Clear window


    //Print ZOMOdds stats


    //Graph ZOMlog populations


    //Graph ZOModel populations


    //Exit
    return;
  }
}

