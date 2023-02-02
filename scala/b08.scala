import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val t = readInt()
        val n = readInt()
        var a = Array.ofDim[Int](t+9)
        for ( i <- 0 until n) {
            val Array(l,r) = readLine().split(" ").map(_.toInt)
            a(l+1) += 1
            a(r+1) -= 1
        }
        val s = a.tail.scanLeft(0)(_+_)
        for ( i <- 1 to t) {
            println(s(i))
        }

    }
}