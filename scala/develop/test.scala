// import scala.io.StdIn._
import java.util.Scanner

object Main extends App {
  val sc = new Scanner(System.in)
  val n = sc.nextInt()
  val k = sc.nextInt()
  val a = 0 +: Vector.fill(n){sc.nextInt()}

  def search(k: Long): Long = {
    @annotation.tailrec
    def go(k: Long, l: Long, r: Long): Long = {
      val m = (l + r) / 2
      if (l == r) l
      else if (check(m)) go(k, l, m)
      else go(k, m+1, r)
    }
    go(k, 1, 1000000000)
  }

  def check(m: Long): Boolean = {
    val printer = (1 to n).map(i => m/a(i))
    val sum = printer.sum
    sum >= k
  }

  println(search(k))
}
