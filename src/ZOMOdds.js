
//Initialize variables
var ZomPer = +process.argv[2]
var FightPer = +process.argv[3]
var NumZom = 0.0
var WinPer = 0.0
var WarnCheck = 0

//Print header
console.log("")

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
console.log("  *Humans that can fight: "+FightPer+"%")

//Estimate odds
NumZom = (100/(100.0-ZomPer))/(FightPer/100.0)
WinPer = 100*NumZom/(NumZom+1.0)
WinPer = +WinPer.toFixed(2)

//Print results
console.log("")
console.log("Results")
console.log("-------")
console.log("  *Number of each human needs to eliminate: "+NumZom)
console.log("  *Humans need to win "+WinPer+"% of one-on-one fights.")
console.log("")
