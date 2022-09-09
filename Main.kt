
import src.VOMSpread
import src.ZOMLog
import src.ZOMOdds
import src.ZOModel

fun main() {
    println("Pick a model to run [ZOModel, ZOMLog, ZOMOdds, VOMSpread]:")
    val choice = readln().lowercase()
    if (choice == "zomodel") {
        val sim = ZOModel()
        sim.togglePrinting()
        sim.promptForInput()
        sim.runCalc()
        sim.printResults()
    } else if (choice == "zomlog") {
        val sim = ZOMLog()
        sim.togglePrinting()
        sim.promptForInput()
        sim.runCalc()
        sim.printResults()
    } else if (choice == "zomodds") {
        val sim = ZOMOdds()
        sim.togglePrinting()
        sim.promptForInput()
        sim.runCalc()
        sim.printResults()
    } else if (choice == "vomspread") {
        val sim = VOMSpread()
        sim.togglePrinting()
        sim.promptForInput()
        sim.runCalc()
        sim.printResults()
    } else {
        println("That is not an option.")
    }
}
