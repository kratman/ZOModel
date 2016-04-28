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
var ZomPer = process.argv[2]
var FightPer = +process.argv[3]
var NumZom = 0.0
var WinPer = 0.0
var WarnCheck = 0
var titleline = ""
var helptext = ""

//Print header
console.log("")
titleline = ""
titleline += "######################################"
titleline += "########################################"
titleline += '\n'
titleline += "#                                     "
titleline += "                                       #"
titleline += '\n'
titleline += "#                      "
titleline += "ZOModel: Zombie Outbreak Modeling"
titleline += "                     #"
titleline += '\n'
titleline += "#                             "
titleline += "By: Eric G. Kratz"
titleline += "                              #"
titleline += '\n'
titleline += "#                              "
titleline += "                                              #"
titleline += '\n'
titleline += "###############################################"
titleline += "###############################"
titleline += '\n'
console.log(titleline)

//Start calculations
if ((ZomPer == "--help") || (ZomPer == "-h"))
{
  //Print help and exit
  helptext = "Usage:"
  helptext += '\n'
  helptext += "  user:$ ZOMOdds ZombiePercent FighterPercent"
  helptext += '\n'
  console.log(helptext)
}
else
{
  //Continue calculations
  ZomPer = +ZomPer

  //Check for errors
  if (ZomPer > 100)
  {
    console.log("Warning: Input cannot be larger than 100%")
    WarnCheck = 1
    ZomPer = 100
  }
  if (ZomPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    WarnCheck = 1
    ZomPer = 0
  }
  if (FightPer > 100)
  {
    console.log("Warning: Input cannot be larger than 100%")
    WarnCheck = 1
    FightPer = 100
  }
  if (FightPer < 0)
  {
    console.log("Warning: Input cannot be less than 0%")
    WarnCheck = 1
    FightPer = 0
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
  NumZom = (100.0/(100.0-ZomPer))/(FightPer/100.0)
  NumZom = Math.ceil(NumZom)
  WinPer = 100.0*NumZom/(NumZom+1.0)
  WinPer = +WinPer.toFixed(2)

  //Print results
  console.log("")
  console.log("Results")
  console.log("-------")
  console.log("  *Number of zombies each survivor needs to eliminate: "+NumZom)
  console.log("  *Survivors need to win ~"+WinPer+"% of one-on-one fights.")
  console.log("")
}

