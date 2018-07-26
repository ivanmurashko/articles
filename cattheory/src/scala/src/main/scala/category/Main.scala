package cluster
import java.io._

object Main {

  def main(args: Array[String]) {
    def printList(res: List[String]) : Unit = res match {
      case Nil => println("")
      case x::xs => {
        println(x)
        printList(xs)
      }
    }

    def printList2File(res: List[String], writer: PrintWriter) : Unit = res match {
      case Nil => println("")
      case x::xs => {
        writer.write(x+"\n")
        printList2File(xs, writer)
      }
    }


    val cluster = Cluster

    // Task 1
    def task1(path: String, printF: List[String] => Unit) : Unit = {
      val taskRes = cluster.farthestFirstTraversal(path)
      printF(taskRes)
    }

    // val task1Data = "dataset_10926_14.txt"
    // if (args.size == 1) {
    //   val writer = new PrintWriter(new File(args(0)))
    //   task1(task1Data, x => printList2File(x, writer))
    //   writer.close
    // }
    // else {
    //   task1(task1Data, printList)
    // }

    // Task 2
    def task2(path: String) : Unit = {
      val taskRes = cluster.squaredErrorDistortionProblem(path)
      println("%.3f".format(taskRes))
    }

    // val task2Data = "dataset_10927_3.txt"
    // task2(task2Data)

    // Task 3

    def task3(path: String, printF: List[String] => Unit) : Unit = {
      val taskRes = cluster.lloydAlgorithm(path)
      printF(taskRes)
    }

    // val task3Data = "dataset_10928_3.txt"
    // if (args.size == 1) {
    //   val writer = new PrintWriter(new File(args(0)))
    //   task3(task3Data, x => printList2File(x, writer))
    //   writer.close
    // }
    // else {
    //   task3(task3Data, printList)
    // }

    // Task 4
    def task4(path: String, printF: List[String] => Unit) : Unit = {
      val taskRes = cluster.softKMeanAlgorithm(path)
      printF(taskRes)
    }

    // val task4Data = "dataset_10933_7.txt"
    // if (args.size == 1) {
    //   val writer = new PrintWriter(new File(args(0)))
    //   task4(task4Data, x => printList2File(x, writer))
    //   writer.close
    // }
    // else {
    //   task4(task4Data, printList)
    // }

    // Task 5
    def task5(path: String, printF: List[String] => Unit) : Unit = {
      val taskRes = cluster.hierarchicalClustering(path)
      printF(taskRes)
    }

    val task5Data = "dataset_10934_7.txt"
    if (args.size == 1) {
      val writer = new PrintWriter(new File(args(0)))
      task5(task5Data, x => printList2File(x, writer))
      writer.close
    }
    else {
      task5(task5Data, printList)
    }




  }
}
