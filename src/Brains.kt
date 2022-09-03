
package src

abstract class Brains {
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

    abstract fun runCalc()

    abstract fun printResults()
}
