import  scala.io.StdIn._

object Main {
    def main(args: Array[String]): Unit= {
        val n = readInt().toBinaryString.toInt
        printf("%010d\n", n)
    }
}