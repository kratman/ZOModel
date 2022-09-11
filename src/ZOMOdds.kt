
package src

class ZOMOdds() : Brains() {
    private var zomPer: Double = 0.0
    private var fightPer: Double = 0.0
    private var numZom: Double = 0.0

    constructor(zombie: Double, fight: Double) : this() {
        zomPer = zombie
        fightPer = fight
        numZom = 0.0
    }

    override fun promptForInput() {
        if (printToScreen) {
            println("Percent of the population turned:")
            zomPer = readln().toDouble()
            println("Percent of the population capable of fighting:")
            fightPer = readln().toDouble()
        }
    }

    private fun errorChecker() {
        var debugOutput = "Checking for errors..."
        if (zomPer > 100)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Population cannot be more than 100% zombies."
            zomPer = 100.0
        }
        if (zomPer < 0)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Population cannot be less than 0% zombies."
            zomPer = 0.0
        }
        if (fightPer > 100)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: More than 100% of the humans fighting is impossible."
            fightPer = 100.0
        }
        if (fightPer < 0)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Less than 0% of the humans fighting is impossible."
            fightPer = 0.0
        }
        if (printToScreen) {
            println(debugOutput)
            println("")
        }
    }

    override fun runCalc() {
        if (printToScreen) {
            printHeader()
        }
        errorChecker()
        val maxPercent = 100.0
        numZom = zomPer
        numZom /= (maxPercent - zomPer)
        numZom /= (fightPer / maxPercent)
        numZom = kotlin.math.ceil(numZom)
    }

    private fun getNumZom(): Int {
        return numZom.toInt()
    }

    override fun printResults() {
        println("ZOMOdds Settings")
        println("--------")
        println("  * Zombified humans: $zomPer%")
        println("  * Survivors in the fight: $fightPer%")
        println("")

        println("Results")
        println("-------")
        println("  * Number of zombies each survivor needs to eliminate: " + getNumZom().toString())
    }
}
