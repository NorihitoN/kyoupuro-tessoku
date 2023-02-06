import scala.io.StdIn._

object Main extends App {
  val Array(n, x) = readLine().split(" ").map(_.toInt)
  val a = 0 +: readLine().split(" ").map(_.toInt)

  def binarySearch(x: Int, n: Int): Int = {
    @annotation.tailrec
    def go(x: Int, l: Int, r: Int): Int = {
      val m = (l + r) / 2
      if (x == a(m)) m
      else if (x < a(m)) go(x, l, m - 1)
      else go(x, m + 1, r)
    }
    go(x, 1, n)
  }

  println(binarySearch(x,n))
}
