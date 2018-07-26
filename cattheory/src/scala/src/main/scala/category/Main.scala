package category
import java.io._

object Main {
  import Category._

  def main(args: Array[String]) {
    println(isStringLengthEven("abcd"));
    println(isStringLengthEven("abc"));
  }
}
