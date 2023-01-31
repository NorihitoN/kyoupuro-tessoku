
import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val n = readInt()
        val listA = readLine().split(" ").map(_.toInt)
        val isFound = (for {
                        i <- listA
                        j <- listA if j > i
                        k <- listA if k > j
                    } yield i + j + k ).filter(_ == 1000).length
        val ans = if (isFound > 0) "Yes" else "No"
        println(ans)
    }
    
}