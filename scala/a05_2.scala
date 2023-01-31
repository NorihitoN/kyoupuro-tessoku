import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val Array(n, k) = readLine().split(" ").map(_.toInt)
        var count = 0
        for {
            i <- 1 to n
            j <- 1 to n
            z = k - i - j
            if (z >= 1 && z <= n)
        } count+=1
        println(count)
    }
}