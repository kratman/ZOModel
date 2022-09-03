
package src

class ZOMOdds(zombie: Double, fight: Double) : Brains() {
    private var zomPer: Double = zombie
    private var fightPer: Double = fight
    private var numZom: Double = 0.0

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
