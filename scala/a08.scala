import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val Vector(h, w) = readLine().split(" ").map(_.toInt).toVector
    val x =
      Vector.fill(h)(0).map(_ => readLine().split(" ").map(_.toInt).toVector)
    val q = readInt()
    val abcd =
      Vector.fill(q)(0).map(_ => readLine().split(" ").map(_.toInt).toVector)
    val z = Array.fill(h + 1)(Array.fill(w + 1) { 0 })

    for (i <- 1 to h) {
      for (j <- 1 to w) {
        z(i)(j) = z(i)(j - 1) + x(i - 1)(j - 1)
      }
    }
    for (j <- 1 to w) {
      for (i <- 1 to h) {
        z(i)(j) = z(i - 1)(j) + z(i)(j)
      }
    }
    for (Vector(a, b, c, d) <- abcd) {
      println(z(c)(d) - z(a - 1)(d) - z(c)(b - 1) + z(a - 1)(b - 1))
    }
  }
}
