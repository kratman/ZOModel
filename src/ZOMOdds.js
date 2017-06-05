// The line below should say JAVASCRIPT and is used to place the interpreter
//JAVASCRIPT

/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

 ZOModel is licensed under GPLv3, for more information see GPL_LICENSE

*/

//Initialize variables
var zomPer = process.argv[2]
var fightPer = +process.argv[3]
var numZom = 0.0
var warnCheck = 0
var titleLine = ""
var helpText = ""

//Print header
console.log("")
titleLine = ""
titleLine += "######################################"
titleLine += "########################################"
titleLine += '\n'
titleLine += "#                                     "
titleLine += "                                       #"
titleLine += '\n'
titleLine += "#                      "
titleLine += "ZOModel: Zombie Outbreak Modeling"
titleLine += "                     #"
titleLine += '\n'
titleLine += "#                             "
titleLine += "By: Eric G. Kratz"
titleLine += "                              #"
titleLine += '\n'
titleLine += "#                              "
titleLine += "                                              #"
titleLine += '\n'
titleLine += "###############################################"
titleLine += "###############################"
titleLine += '\n'
console.log(titleLine)

//Start calculations
if ((zomPer == "--help") || (zomPer == "-h") ||
   (isNaN(zomPer)) || (isNaN(fightPer)))
{
  //Print help and exit
  helpText = "Usage:"
  helpText += '\n'
  helpText += "  user:$ ZOMOdds ZombiePercent FighterPercent"
  helpText += '\n'
  console.log(helpText)
}
else
{
  //Continue calculations
  zomPer = +zomPer

  //Check for errors
  if (zomPer > 100)
  {
    console.log("Warning: Input cannot be larger than 100%")
    warnCheck = 1
    zomPer = 100
  }
  if (zomPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    warnCheck = 1
    zomPer = 0
  }
  if (fightPer > 100)
  {
    console.log("Warning: Input cannot be larger than 100%")
    warnCheck = 1
    fightPer = 100
  }
  if (fightPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    warnCheck = 1
    fightPer = 0
  }
  if (warnCheck == 1)
  {
    console.log("")
  }

  //Print settings to the log
  console.log("Settings")
  console.log("--------")
  console.log("  *Zombified humans: "+zomPer+"%")
  console.log("  *Survivors in the fight: "+fightPer+"%")

  //Estimate odds
  numZom = (zomPer/(100.0-zomPer))/(fightPer/100.0)
  numZom = Math.ceil(numZom)

  //Print results
  console.log("")
  console.log("Results")
  console.log("-------")
  console.log("  *Number of zombies each survivor needs to eliminate: "+numZom)
  console.log("")
}

