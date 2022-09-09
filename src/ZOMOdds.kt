
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

    }

    override fun runCalc() {
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
        printHeader()
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
