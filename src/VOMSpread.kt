
package src

class VOMSpread() : Brains() {
    private var feedDays: Int = 0
    private var deathRate: Double = 0.0
    private var days: Int = 0
    private var vampires: Double = 0.0

    private var worldPopulation: Double = 7000000000.0

    constructor(feed: Int, death: Double) : this() {
        feedDays = feed
        deathRate = death
    }

    override fun promptForInput() {
        if (printToScreen) {
            println("Number of days a vampire goes between feedings:")
            feedDays = readln().toInt()
            println("Percent of victims which die before turning into vampires:")
            deathRate = readln().toDouble()
        }
    }

    private fun errorChecker() {
        var debugOutput = "Checking for errors..."
        if (feedDays < 0)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Days between feeding cannot be negative."
            feedDays = 0
        }
        if (deathRate > 100.0)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Vampires killing more than 100% of their victims is impossible."
            deathRate = 100.0
        }
        if (deathRate < 0.0)
        {
            debugOutput = "$debugOutput\n  "
            debugOutput += "Warning: Vampires killing less than 0% of their victims is impossible."
            deathRate = 0.0
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
        days = 0
        vampires = 1.0
        var currentPopulation = worldPopulation
        while (currentPopulation > 0)
        {
            vampires += kotlin.math.ceil(vampires * (1.0 - (deathRate / 100.0)))
            currentPopulation -= kotlin.math.ceil(vampires)
            days += kotlin.math.max(feedDays, 1)
        }
    }

    override fun printResults() {
        println("VOMSpread Settings")
        println("--------")
        println("  * Time between vampire feedings: $feedDays")
        println("  * Percent of victims killed: $deathRate%")
        println("")

        println("Results")
        println("-------")
        println("  * All humans have become vampires in $days days.")
    }
}
