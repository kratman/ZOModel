
package src

import kotlin.random.Random

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

    fun promptForInput() {
        println("Initial human population:")
        humans = readln().toInt()
        println("Initial zombie population:")
        zombies = readln().toInt()
        println("Probability that a human will win a fight against a zombie:")
        winProb = readln().toDouble()
        println("Probability that a zombie is super-hungry:")
        eatProb = readln().toDouble()
        println("Probability that a human gets bitten by a zombie:")
        biteProb = readln().toDouble()
        println("Probability that the infected are shown mercy:")
        mercyProb = readln().toDouble()
        println("Fraction infected at the beginning:")
        infectProb = readln().toDouble()
        println("")
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
        val biteList = MutableList(humans) {false}
        var risen = 0
        // Mark humans as infected
        if (days == 0) {
            val infected = kotlin.math.min(((infectProb * humans.toDouble()).toInt()), humans)
            for (i in 0 until infected) {
                biteList[i] = true
            }
        }
        // Ready... FIGHT!!!
        for (z in 0 until zombies) {
            if (humans <= 0) {
                break
            }
            val human = (0 until humans).random()
            if (Random.nextDouble() > winProb) {
                humans--
                biteList.removeAt(human)
                if (Random.nextDouble() > eatProb) {
                    risen++
                }
            } else {
                risen--
                if (Random.nextDouble() < biteProb) {
                    biteList[human] = true
                }
            }
        }
        // Those about to die salute you
        for (victim in biteList) {
            if (victim) {
                humans--
                if (Random.nextDouble() > mercyProb) {
                    risen++
                }
            }
        }
        zombies = kotlin.math.max(zombies + risen, 0)
        days++
    }

    private fun simulation() {
        while (((humans > 0) && (zombies > 0)) || (days == 0)) {
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
