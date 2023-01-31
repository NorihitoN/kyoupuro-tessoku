import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val Array(_,x) = readLine().split(" ").map(_.toInt)
        val listA = readLine().split(" ").map(_.toInt)
        val ans = if (listA.contains(x)) "Yes" else "No"
        println(ans)
    }
}