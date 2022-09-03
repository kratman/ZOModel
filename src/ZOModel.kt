
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
        quitSimulation = false
        var debugOutput = "Checking for errors..."
        if (humans < 0) {
            debugOutput = "$debugOutput\n  * Negative humans? Do you know how numbers work?"
            quitSimulation = true
        }
        if (zombies < 0) {
            debugOutput = "$debugOutput\n  * Negative zombies? Do you know how numbers work?"
            quitSimulation = true
        }
        if (winProb <= 0.0) {
            debugOutput = "$debugOutput\n  * Humans cannot win any fights?!?!"
            debugOutput = "$debugOutput\n    Running that type of simulation is brutal and pointless..."
            quitSimulation = true
        }
        if ((winProb > 1.0) || (eatProb > 1.0) || (biteProb > 1.0) || (mercyProb > 1.0) || (infectProb > 1.0)) {
            debugOutput = "$debugOutput\n  * Probabilities cannot be greater than 1."
            debugOutput = "$debugOutput\n    You should take some math classes..."
            winProb = kotlin.math.min(winProb, 1.0)
            eatProb = kotlin.math.min(eatProb, 1.0)
            biteProb = kotlin.math.min(biteProb, 1.0)
            mercyProb = kotlin.math.min(mercyProb, 1.0)
            infectProb = kotlin.math.min(infectProb, 1.0)
        }
        if ((winProb < 0.0) || (eatProb < 0.0) || (biteProb < 0.0) || (mercyProb < 0.0) || (infectProb < 0.0)) {
            debugOutput = "$debugOutput\n  * Probabilities cannot be less than 0."
            debugOutput = "$debugOutput\n    You should take some math classes..."
            winProb = kotlin.math.max(winProb, 0.0)
            eatProb = kotlin.math.max(eatProb, 0.0)
            biteProb = kotlin.math.max(biteProb, 0.0)
            mercyProb = kotlin.math.max(mercyProb, 0.0)
            infectProb = kotlin.math.max(infectProb, 0.0)
        }
        if (printToScreen) {
            println(debugOutput)
            println("")
            if (!quitSimulation) {
                println("Nothing seems to be amiss...")
                println(" Well... besides the reanimated corpses...")
                println("")
                println("Settings")
                println("--------")
                println("  * Win probability: $winProb")
                println("  * Eaten probability: $eatProb")
                println("  * Bitten probability: $biteProb")
                println("  * Mercy probability: $mercyProb")
                println("  * Infected probability: $infectProb")
                println("")
            }
        }
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
        if (printToScreen) {
            println("Simulation")
            println("--------")
        }
        if (!quitSimulation) {
            simulation()
        }
    }

    override fun printResults() {
        println("")
        println("The end?")
        println("")
        if (humans <= 0) {
            println("Yes. Everyone is dead...")
            println("")
        }
        println("")
    }
}
