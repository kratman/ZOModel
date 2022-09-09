
package src

class VOMSpread() : Brains() {
    private var feedDays: Int = 0
    private var deathRate: Double = 0.0
    private var days: Int = 0
    private var vampires: Double = 0.0

    private var worldPopulation: Double = 7000000000.0

    constructor(feed: Int, death: Double) : this() {
        feedDays = feed
        deathRate = death / 100.0
    }

    override fun promptForInput() {

    }

    override fun runCalc() {
        days = 0
        vampires = 1.0
        while (vampires < worldPopulation)
        {
            vampires += kotlin.math.ceil(vampires * (1 - deathRate));
            days += feedDays
        }
    }

    private fun getDeathRate(): Double {
        return (100.0 * deathRate)
    }

    override fun printResults() {
        printHeader()
        println("VOMSpread Settings")
        println("--------")
        println("  * Time between vampire feedings: $feedDays")
        println("  * Percent of victims killed: " + getDeathRate() +"%")
        println("")

        println("Results")
        println("-------")
        println("  * All humans have become vampires in $days")
    }
}
