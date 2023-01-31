import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val Array(n, q) = readLine().split(" ").map(_.toInt)
        val listA = readLine().split(" ").map(_.toInt)
        val listS = listA.scanLeft(0){_+_}
        for ( i <- 1 to q) {
            val Array(l,r) = readLine().split(" ").map(_.toInt)
            println(listS(r) - listS(l-1))
        }
    }
}