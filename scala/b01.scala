import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val ab = readLine().split(" ").map(_.toInt)
        println(ab(0) + ab(1))
    }
}