import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val Array(a, b) = readLine().split(" ").map(_.toInt)
        val isFound = (a to b).map(100 % _).filter(_ == 0).length
        val ans = if (isFound > 0) "Yes" else "No"
        println(ans)
    }
}
