import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val d = readInt()
        val n = readInt()
        var a = Array.ofDim[Int](d+9)
        for ( i <- 0 until n) {
            val Array(l,r) = readLine().split(" ").map(_.toInt)
            a(l) += 1
            a(r+1) -= 1
        }
        val s = a.scanLeft(0)(_+_).tail
        for ( i <- 1 to d) {
            println(s(i))
        }

    }
}