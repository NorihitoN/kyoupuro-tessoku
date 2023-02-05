import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt()
    val a = readLine().split(" ").map(_.toInt).toVector
    val d = readInt()
    val lr = Vector.fill(d){0}.map(_ => readLine().split(" ").map(_.toInt).toVector)

    val x = Array.fill(n){0}
    val y = Array.fill(n){0}

    x(0) = a(0)
    for (i <- 1 to (n-1)){
      x(i) = Array(x(i-1), a(i)).max
    }

    y(n-1) = a(n-1)

    for (i <- (n-2) to 0 by -1) {
      y(i)= Array(y(i+1), a(i)).max
    }

    for (i <- 0 until d )
      println(Array(x(lr(i)(0)-2), y(lr(i)(1))).max)
    
  }
}
