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
var feedDays = process.argv[2]
var deathPer = +process.argv[3]
var numVamp = 0.0
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
if ((ZomPer == "--help") || (ZomPer == "-h"))
{
  //Print help and exit
  helptext = "Usage:"
  helptext += '\n'
  helptext += "  user:$ VOMSpread DaysBetweenFeeds PercentKilledVictims"
  helptext += '\n'
  console.log(helptext)
}
else
{
  //Continue calculations
  numVamp = 1

  //Check for errors
  if (deathPer > 100)
  {
    console.log("Warning: Input cannot be larger than 100%")
    WarnCheck = 1
    deathPer = 100
  }
  if (deathPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    WarnCheck = 1
    deathPer = 0
  }
  if (feedDays < 0)
  {
    console.log("Warning: Input cannot be less than 0 days")
    WarnCheck = 1
    feedDays = 0
  }
  if (WarnCheck == 1)
  {
    console.log("")
  }

  //Print settings to the log
  console.log("Settings")
  console.log("--------")
  console.log("  *Zombified humans: "+ZomPer+"%")
  console.log("  *Survivors in the fight: "+FightPer+"%")

  //Estimate odds
  NumZom = (ZomPer/(100.0-ZomPer))/(FightPer/100.0)
  NumZom = Math.ceil(NumZom)

  //Print results
  console.log("")
  console.log("Results")
  console.log("-------")
  console.log("  *Number of zombies each survivor needs to eliminate: "+NumZom)
  console.log("")
}

