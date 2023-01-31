import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val nList = readLine().split("").map(_.toInt).reverse
        val ans = nList.zipWithIndex.map(v => if (v._1 == 1) Math.pow(2, v._2).toInt else 0).sum
        println(ans)
    }
}