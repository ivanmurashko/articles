package category

// https://hseeberger.wordpress.com/2010/11/25/introduction-to-category-theory-in-scala/
object Category {
  def id[A]: A => A = a => a
  def compose[A, B, C](g: B => C, f: A => B): A => C =
    g compose f 

  val isEven = (i: Int) => i % 2  == 0
  val stringLength = (s: String) => s.length
  val isStringLengthEven = (s: String) => compose(isEven, stringLength)(s)
}
