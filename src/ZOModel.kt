package src

class ZOModel : Brains() {
    private var humans: Int = 0 // Human population
    private var zombies: Int = 0 // Zombie population
    private var days: Int = 0 // Number of days since the outbreak
    private var winProb: Double = 0.0 // Probability that the human kills the zombie
    private var eatProb: Double = 0.0 // Probability that the zombie eats the human
    private var biteProb: Double = 0.0 // Probability that the human was bitten
    private var mercyProb: Double = 0.0 // Probability for mercy
    private var infectProb: Double = 0.0 // Initial infection fraction
    private var quitSimulation: Boolean = false // Avoids simulating erroneous input

    private var printToScreen: Boolean = false

    fun initializeSimulation(hum: Int, zom: Int, win: Double, eat: Double,
                             bite: Double, mercy: Double, infect: Double) {
        humans = hum
        zombies = zom
        winProb = win
        eatProb = eat
        biteProb = bite
        mercyProb = mercy
        infectProb = infect
    }

    fun togglePrinting() {
        printToScreen = !printToScreen
    }

    private fun errorChecker() {

    }

    private fun printProgress() {
        if (printToScreen) {
            println(" | Day: $days | Humans: $humans | Zombies: $zombies")
        }
    }

    private fun dailyUpdate() {
        days += 1
        humans = 0
    }

    private fun simulation() {
        while (((humans > 0) && (zombies > 0)) && (days == 0)) {
            printProgress()
            dailyUpdate()
        }
        printProgress()
    }

    override fun runCalc() {
        if (printToScreen) {
            printHeader()
        }
        errorChecker()
        if (!quitSimulation) {
            simulation()
        }
    }

    override fun printResults() {
        println("")
        println("The end?")
        println("")
        if (humans == 0)
        {
            println("Yes. Everyone is dead...")
            println("")
        }
        println("")
    }
}
