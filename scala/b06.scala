import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val n = readInt()
        val listA = readLine().split(" ").map(_.toInt)
        val q = readInt()
        val winSum = listA.scanLeft(0){_+_}
        val loseSum = listA.map(a => {
            if (a == 1) 0
            else 1
        }).scanLeft(0){_+_}

        for ( i <- 1 to q) {
            val Array(l,r) = readLine().split(" ").map(_.toInt)
            val wl = (winSum(r)-winSum(l-1)) - (loseSum(r)-loseSum(l-1))
            if (wl > 0) println("win")
            else if (wl < 0) println("lose")
            else println("draw")
        }
    }
}