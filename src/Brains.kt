
package src

abstract class Brains {
    protected var printToScreen: Boolean = false // Toggle the command line interface

    protected fun printHeader() {
        println("")
        println("###############################################################################")
        println("#                                                                             #")
        println("#                      ZOModel: Zombie Outbreak Modeling                      #")
        println("#                                                                             #")
        println("###############################################################################")
        println("")
        println("")
    }

    fun togglePrinting() {
        printToScreen = !printToScreen
    }

    abstract fun runCalc()

    abstract fun printResults()

    abstract fun promptForInput()
}
