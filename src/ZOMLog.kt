
package src

import kotlin.math.pow

class ZOMLog(initHum: Double, initZom: Double,
             simYears: Int, popRate: Double,
             winProb: Double, infRate: Double,
             merProb: Double, erosion: Double) : Brains() {
    private var humPop: Double = initHum
    private var zomPop: Double = initZom
    private var months: Int = 12 * simYears
    private var growthRate: Double = (1.0 + (popRate / 100.0)).pow((1.0 / 12.0)) - 1.0
    private var winRate: Double = winProb / 100.0
    private var mercyRate: Double = merProb / 100.0
    private var infectRate: Double = infRate / (12.0 * 100.0)
    private var eroRate: Double = erosion / (12.0 * 100.0)

    private val minimumPopulation: Double = 0.001
    private val cooperationScale: Double = 10000400.0
    private val apocalypseCycle: Int = 1200000000
    private val undeadSurvivalRate: Double = 0.1

    private var secondApocalypse: Boolean = false
    private var lengthOfExistence: Int = 0
    private var maxHumans: Double = 0.0
    private var maxZombies: Double = 0.0

    override fun runCalc() {
        for (m in 0..months) {
            // Update statistics
            maxHumans = kotlin.math.max(humPop, maxHumans)
            maxZombies = kotlin.math.max(zomPop, maxZombies)
            if (humPop > 0.0) {
                lengthOfExistence = m
            }

            // Check if all humans and zombies have died
            if ((humPop < minimumPopulation) && (zomPop < minimumPopulation)) {
                break
            }

            // Save the current population sizes
            var newHumPop = humPop
            var newZomPop = zomPop

            // Update human population
            newHumPop += growthRate * humPop
            newHumPop -= (humPop * humPop * growthRate) / cooperationScale
            newHumPop -= (1.0 - winRate) * zomPop
            newHumPop -= infectRate * humPop

            // Update zombie population
            if (humPop > minimumPopulation) {
                newZomPop += zomPop * (1 - winRate) * (1 - mercyRate)
                newZomPop += humPop * infectRate * (1 - mercyRate)
                newZomPop -= winRate * zomPop
            }
            newZomPop -= eroRate * zomPop

            // Check for a second apocalypse
            if (apocalypseCycle == (0..apocalypseCycle).random()) {
                newHumPop = 0.0
                newZomPop *= undeadSurvivalRate
                secondApocalypse = true
            }

            // Save new populations
            if (newHumPop < minimumPopulation) {
                newHumPop = 0.0
            }
            if (newZomPop < minimumPopulation) {
                newZomPop = 0.0
            }
            humPop = newHumPop
            zomPop = newZomPop
        }
    }

    override fun printResults() {
        printHeader()
        println("ZOMLog Settings")
        println("--------")
        println("  *Simulation length: $months months")
        println("  *Monthly population growth rate: $growthRate")
        println("  *Probability that humans defeat zombies: $winRate")
        println("  *Probability that human show mercy to the infected: $mercyRate")
        println("  *Monthly natural zombie disease infection rate: $infectRate")
        println("  *Monthly natural erosion rate for zombies: $eroRate")
        println("")

        println("Results")
        println("-------")
        if (humPop < minimumPopulation) {
            println("  *Humans survived for $lengthOfExistence months")
            if (secondApocalypse) {
                println("  *Extinction due to asteroid impact.")
            } else {
                println("  *Extinction due to zombie apocalypse.")
            }
        }
        println("  *Largest number of humans (in thousands): $maxHumans")
        println("  *Largest number of zombies (in thousands): $maxZombies")
        println("  *Final number of humans (in thousands): $humPop")
        println("  *Final number of zombies (in thousands): $zomPop")
    }
}
