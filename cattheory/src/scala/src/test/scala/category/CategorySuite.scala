package cluster

import org.scalatest.FunSuite

import org.junit.runner.RunWith
import org.scalatest.junit.JUnitRunner

/**
  * This class implements a ScalaTest test suite for the methods in object
  * `Cluster` 
  * 
  * A test suite is created by defining a class which extends the type
  * `org.scalatest.FunSuite`. When running ScalaTest, it will automatically
  * find this class and execute all of its tests.
  *
  * Adding the `@RunWith` annotation enables the test suite to be executed
  * inside eclipse using the built-in JUnit test runner.
  *
  * You have two options for running this test suite:
  * 
  * - Start the sbt console and run the "test" command
  * - Right-click this file in eclipse and chose "Run As" - "JUnit Test"
 */
@RunWith(classOf[JUnitRunner])
class ClusterSuite extends FunSuite {
  
  test("FarthestFirstTraversal clustering heuristic") {
    val c = Cluster
    val res = c.farthestFirstTraversal("testfft.txt")
    val okres = List("0.0 0.0", "5.0 5.0", "0.0 5.0")
    assert(res == okres) 
  }

  test("squared error distortion") {
    val c = Cluster
    val res = c.squaredErrorDistortionProblem("testsed.txt")
    val okres = 18.246
    assert(math.abs(res - okres) < 0.001) 
  }

  test("lloyd") {
    val c = Cluster
    val res = c.lloydAlgorithm("testla.txt")
    val okres = List("1.800 2.867", "1.060 1.140")
    assert(res == okres) 
  }

  test("softkmean") {
    val c = Cluster
    val res = c.softKMeanAlgorithm("testskm.txt")
    val okres = List("1.662 2.623", "1.075 1.148")
    assert(res == okres) 
  }

  test("hierarchical") {
    val c = Cluster
    val res = c.hierarchicalClustering("testhc.txt")
    val okres = List(
      "4 6",
      "5 7",
      "3 4 6",
      "1 2",
      "3 4 5 6 7",
      "1 2 3 4 5 6 7" )
    assert(res == okres) 
  }
}
