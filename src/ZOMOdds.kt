
package ZOMOdds

class ZOMOdds {
    var zomPer
    var fightPer
    var numZom

    init {
        zomPer = 0
        fightPer = 0
        numZom = 0
    }

    constructor(zombie: Double, fight: Double) {
        zomPer = zombie
        fightPer = fight
    }

    fun runCalc() {
        numZom = zomPer
        numZom /= (ZOM_MAX_PERCENT - zomPer)
        numZom /= (fightPer / 100.0)
        numZom = ceil(numZom)
    }

    fun getNumZom(): Int {
        return numZOm as Int
    }

    fun printResults() {
        print('\n')
        print("--- ZOMOdds test ---" + '\n')

        print('\n')
        print("Settings" + '\n')
        print("--------" + '\n')
        print("  *Zombified humans: " + zomPer)
        print("%" + '\n')
        print("  *Survivors in the fight: " + fightPer)
        print("%" + '\n')
        print('\n')

        print("Results" + '\n')
        print("-------" + '\n')
        print("  *Number of zombies each survivor needs to eliminate: ")
        print(getNumZom() + '\n' + '\n')
    }
}

fun main() {
    odds = ZomOdds(90.0, 50.0)
    odds.runCalc()
    odds.printResults()
}