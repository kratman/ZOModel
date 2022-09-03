/*

##############################################################################
#                                                                            #
#                      ZOModel: Zombie Outbreak Modeling                     #
#                             By: Eric G. Kratz                              #
#                                                                            #
##############################################################################

*/

//Initialize variables
var feedDays = process.argv[2]
var minDays = 0.1
var deathPer = +process.argv[3]
var maxDeathPer = 99.9
var numVamp = 0.0
var numDays = 0.0
var humanPop = 7000000000
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
if ((feedDays == "--help") || (feedDays == "-h") ||
   (isNaN(feedDays)) || (isNaN(deathPer)))
{
  //Print help and exit
  helpText = "Usage:"
  helpText += '\n'
  helpText += "  user:$ VOMSpread DaysBetweenFeeds PercentKilledVictims"
  helpText += '\n'
  console.log(helpText)
}
else
{
  //Continue calculations
  feedDays = +feedDays
  deathPer = +deathPer
  numVamp = 1

  //Check for errors
  if (deathPer > maxDeathPer)
  {
    console.log("Warning: Input cannot be larger than "+maxDeathPer+"%")
    warnCheck = 1
    deathPer = maxDeathPer
  }
  if (deathPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    warnCheck = 1
    deathPer = 0
  }
  if (feedDays < 0)
  {
    console.log("Warning: Input cannot be less than "+minDays+" days")
    warnCheck = 1
    feedDays = 0
  }
  if (warnCheck == 1)
  {
    console.log("")
  }

  //Print settings to the log
  console.log("Settings")
  console.log("--------")
  console.log("  *Time between vampire feedings: "+feedDays+" days")
  console.log("  *Percent of victims killed: "+deathPer+"%")

  //Calculate the number of days before vampires kill all humans
  deathPer /= 100.0
  while (numVamp < humanPop)
  {
    numVamp += Math.ceil(numVamp*(1.0-deathPer))
    numDays += feedDays
  }

  //Print results
  console.log("")
  console.log("Results")
  console.log("-------")
  console.log("  *All humans have become vampires in "+numDays+" days.")
  console.log("")
}

