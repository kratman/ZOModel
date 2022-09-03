
package src

class VOMSpread(feed: Int, death: Double) : Brains() {
    private var feedDays: Int = feed
    private var deathRate: Double = death / 100.0
    private var days: Int = 0
    private var vampires: Double = 0.0

    private var worldPopulation: Double = 7000000000.0

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
