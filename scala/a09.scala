import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val Vector(h, w, n) = readLine().split(" ").map(_.toInt).toVector
    val x = Array.fill(h+1)(Array.fill(w+1){0})
    val z = Array.fill(h+1)(Array.fill(w+1){0})
    val abcd = Vector.fill(n)(0).map(_ => readLine().split(" ").map(_.toInt).toVector)
    for (Vector(a, b, c, d) <- abcd) {
      x(a-1)(b-1) += 1
      x(a-1)(d) -= 1
      x(c)(b-1) -= 1
      x(c)(d) += 1
    }

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

    for (i <- 1 to h) {
      println(z(i).tail.mkString(" "))
    }
  }
}
