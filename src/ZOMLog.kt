
package src

import kotlin.math.pow

class ZOMLog(initHum: Double, initZom: Double,
             simYears: Int, popRate: Double,
             winProb: Double, infRate: Double,
             merProb: Double, erosion: Double) {
    private var humPop: Double = initHum
    private var zomPop: Double = initZom
    private var months: Int = 12 * simYears
    private var growthRate: Double = (1 + popRate).pow((1 / 12)) - 1
    private var winRate: Double = winProb
    private var mercyRate: Double = merProb
    private var infectRate: Double = infRate / 12.0
    private var eroRate: Double = erosion / 12.0

    private val ZOM_LOG_COMP_SCALE: Double = 10000400.0
    private val ZOM_LOG_APOC_CYC: Int = 1200000000
    private val ZOM_LOG_MIN_POP: Double = 0.001
    private val ZOM_LOG_SEC_APOC_SCALE: Double = 0.1

    fun runCalc() {
        // Statistics counters
        var maxHum = 0.0
        var maxZom = 0.0
        var extMonths = 0

        // Flags
        var secondApoc = false

        for (m in 0..months) {
            // Update statistics
            maxHum = kotlin.math.max(humPop, maxHum);
            maxZom = kotlin.math.max(zomPop, maxZom);
            if (humPop > 0.0) {
                extMonths = m
            }

            // Check if all humans and zombies have died
            if ((humPop < ZOM_LOG_MIN_POP) && (zomPop < ZOM_LOG_MIN_POP)) {
                break
            }

            // Save the current population sizes
            var newHumPop = humPop
            var newZomPop = zomPop

            // Update human population
            newHumPop += growthRate * humPop
            newHumPop -= (humPop * humPop * growthRate) / ZOM_LOG_COMP_SCALE
            newHumPop -= (1.0 - winRate) * zomPop
            newHumPop -= infectRate * humPop

            // Update zombie population
            if (humPop > ZOM_LOG_MIN_POP) {
                newZomPop += zomPop * (1 - winRate) * (1 - mercyRate)
                newZomPop += humPop * infectRate * (1 - mercyRate)
                newZomPop -= winRate * zomPop
            }
            newZomPop -= eroRate * zomPop

            // Check for a second apocalypse (random int is needed)
            if (secondApoc) {
                newHumPop = 0.0
                newZomPop *= ZOM_LOG_SEC_APOC_SCALE
            }

            // Save new populations
            humPop = kotlin.math.min(newHumPop, ZOM_LOG_MIN_POP)
            zomPop = kotlin.math.min(newZomPop, ZOM_LOG_MIN_POP)
        }
    }
}