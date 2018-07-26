package cluster

object Cluster {
  type Points = List[List[Double]]

  def str2List[T](data: String, f: String => T) : List[T] = {
    val splited : Array[String] = data.split(" ")
    val res : List[T] = splited.toList map( f )
    res
  }

  def list2Str[T]( data: List[T] ) : String = {
    def helper( l: List[T], acc: String ) : String = l match {
      case Nil => acc
      case x::xs => helper( xs, acc + x.toString + " " )
    }
    helper( data, "" ) trim
  }

  def listFloat2Str[Float]( data: List[Float] ) : String = {
    def helper( l: List[Float], acc: String ) : String = l match {
      case Nil => acc
      case x::xs => helper( xs, acc + "%.3f".format(x) + " " )
    }
    helper( data, "" ) trim
  }


  /**
    Calculates a distance between 2 points
    */
  def distance(v: List[Double], w: List[Double]): Double = {
    def helper(l: List[(Double, Double)], acc: Double) : Double = l match {
      case Nil => acc
      case x::xs => helper(xs, acc + math.pow(x._1 - x._2, 2))
    }
    helper(v zip w, 0.0)
  }

  def distance2center(x: List[Double], centers: Points ) : Double = {
    centers map ( distance(x, _) ) min
  }

  def maxdistance2center(points: Points, centers: Points ) : Double = {
    points map ( distance2center(_, centers) ) max
  }


  def findCenters( points: Points, k: Int ) : Points = {
    def helper(left: Int, centers: Points ) : Points = {
      if (left == 0) centers
      else centers match {
        case Nil => helper(left - 1, List(points.head))
        case y::ys => {
          val nc = points.maxBy[Double](x => distance2center(x, centers))
          helper(left - 1, centers :+ nc) 
        }
      }
    }
    helper(k, Nil)
  }

  def splitList(data: List[String], del: String) : (List[String], List[String]) = {
    def findElemPos(p: List[String], pos: Int): Int = p match {
      case Nil => -1
      case x::xs => {
        if (x == del) pos
        else findElemPos(xs, pos + 1)
      }
    }
    val n = findElemPos(data, 0 )
    data splitAt(n)
  }

  def distortion(points: Points, centers: Points) : Double = {
    def helper( l: Points, acc: Double ) : Double = l match {
      case Nil => acc
      case x::xs => helper(xs, acc + distance2center(x, centers))
    }
    val n = points.length
    helper(points, 0.0)/n
  }


   def center_gravity(x: Points, m: Int): List[Double] = {
      val init: List[Double] = List.fill(m)(0.0)
      val tmp: List[Double] = x.foldLeft[List[Double]](init){
        def acc(y: List[Double], z: List[Double]) : List[Double] = {
          z zip y map (t => t._1 + t._2)
        }
        acc _
      }
      tmp map (y => y / (x length))
    }

  /**
    Defines new centers by previosly defined clusters
    */
  def clusters2centers(clusters: List[Points], m: Int) : Points = {    

    def helper(x: Points): List[Double] = center_gravity(x, m)
    clusters map helper
  }

  /**
    Defines clusters by previously defined centers 
    */
  def centers2cluster(points: Points, centers: Points) : List[Points] = {
    def helper(point: List[Double], center: List[Double]): Boolean = {
      val d1 = distance(point, center)
      val d2 = distance2center(point, centers)
      math.abs(d1 - d2) < 0.00001
    }

    def filterByCenter(center: List[Double]) : Points = {
      points filter(helper(_, center))
    }
    //println(centers)
    val res = centers map(filterByCenter(_))
    //println(res.head.length)
    //println(res.tail.head.length)
    res
  }

  def lloyd(points: Points, k: Int, m: Int): Points = {
    def helper(centers: Points, left: Int) : Points = {
      if (left == 0) centers
      else {
        val clusters = centers2cluster(points, centers)
        helper(clusters2centers(clusters, m), left - 1)
      }
    }
    helper(points slice(0, k), k*5)
  }

  def softdistance(x: List[Double], y: List[Double], b: Double) : Double = {
    math.exp(-b*math.sqrt(distance(x, y)))
  }

  /**
    Defines clusters by previously defined centers 
    */
  def centers2softcluster(points: Points, centers: Points, b: Double) : Points = {
    def cdistance(x: List[Double]): Double = {
      centers.foldLeft[Double](0.0){
        def acc(y: Double, z: List[Double]) : Double = {
          y + softdistance(x, z, b)
        }
        acc _
      }
    }
    val denom: List[Double] = points map(cdistance(_))
    // center => hiden vector
    def converter(center: List[Double]) : List[Double] = {
      def helper(x: (List[Double], Double)): Double = {
        softdistance(x._1, center, b)/x._2
      }
      points zip denom map (helper(_))
    }
    centers map (converter(_))
  }

  /**
    Defines new centers by previosly defined clusters
    */
  def softclusters2centers(points: Points, clusters: Points, m: Int) : Points = {
    def csum(x: List[Double]): Double = x.foldLeft[Double](0.0){_ + _}
    val denom: List[Double] = clusters map(csum(_))

    def converter(center: List[Double]) : List[Double] = {
      val init: List[Double] = List.fill(m)(0.0)
      val c2p = center zip points
      c2p.foldLeft[List[Double]](init){
        def acc(x: List[Double], t: (Double, List[Double])) : List[Double] = {
          def helper(x: (Double, Double)) : Double = {
            x._1 + t._1*x._2
          }
          x zip t._2 map(helper(_))
        }
        acc _
      }
    }

    def helper(x: (List[Double], Double)): List[Double] = {
      def h(z: Double) : Double = {
        z/x._2
      }
      converter(x._1) map (h(_))
    }
    clusters zip denom map helper
  }

  def softkmean(points: Points, k: Int, m: Int, b: Double): Points = {
    def helper(centers: Points, left: Int) : Points = {
      if (left == 0) centers
      else {
        val clusters = centers2softcluster(points, centers, b)
        helper(softclusters2centers(points, clusters, m), left - 1)
      }
    }
    helper(points slice(0, k), 100)
  }


  /**
    CODE CHALLENGE: Implement the FarthestFirstTraversal clustering heuristic.
    Input: Integers k and m followed by a set of points 
    Data in m-dimensional space.
    Output: A set Centers consisting of k points (centers) 
    resulting from applying
    FarthestFirstTraversal(Data, k), where the first point from Data 
    is chosen as the
    first center to initialize the algorithm.
    */
  def farthestFirstTraversal(path: String) : List[String] = {
    val inputData : List[String] = Loader.loadData(path)

    val header = str2List[Int](inputData.head, x => x.toInt )
    val k = header(0)
    val m = header(1)
    val points = inputData.tail.map( s => str2List[Double](s, x => x.toDouble))
    findCenters(points, k) map( x => list2Str(x) )
  }

  /**
    Squared Error Distortion Problem:  
    Compute the squared error distortion of a set of data points 
    with respect to a set of centers.
    Input: A set of points Data and a set of centers Centers. 
    Output: The squared error distortion Distortion(Data, Centers). 

    CODE CHALLENGE: Solve the Squared Error Distortion Problem.
    Input: Integers k and m, followed by a set of centers Centers 
    and a set of points Data.
    Output: The squared error distortion Distortion(Data, Centers).
    */
  def squaredErrorDistortionProblem(path: String): Double = {
   val inputData : List[String] = Loader.loadData(path)

    val header = str2List[Int](inputData.head, x => x.toInt )
    val k = header(0)
    val m = header(1)

    val data = splitList(inputData.tail, "--------")
    val centers = data._1 map( s => str2List[Double](s, x => x.toDouble))
    val points = data._2.tail map( s => str2List[Double](s, x => x.toDouble))

    distortion(points, centers)
  }

  /**
    CODE CHALLENGE: Implement the Lloyd algorithm for k-means clustering.
    Input: Integers k and m followed by a set of points Data 
    in m-dimensional space.
    Output: A set Centers consisting of k points (centers) 
    resulting from applying the Lloyd algorithm to Data and Centers, 
    where the first k points from Data are selected
    as the first k centers.
    */
  def lloydAlgorithm(path: String) : List[String] = {
    val inputData : List[String] = Loader.loadData(path)

    val header = str2List[Int](inputData.head, x => x.toInt )
    val k = header(0)
    val m = header(1)
    val points = inputData.tail.map( s => str2List[Double](s, x => x.toDouble))
    lloyd(points, k, m) map( x => listFloat2Str(x) )
  }

  /**
    CODE CHALLENGE: Implement the expectation maximization algorithm 
    for soft k-means clustering.
    Input: Integers k and m, followed by a stiffness parameter B, 
    followed by a set of points
    Data in m-dimensional space.
    Output: A set Centers consisting of k points (centers) resulting 
    from applying the expectation maximization algorithm for soft 
    k-means clustering. Select the first k points from Data as the 
    first centers for the algorithm and run the algorithm for 100 E-steps
    and 100 M-steps. Results should be accurate up to three decimal places.
    */
  def softKMeanAlgorithm(path: String) : List[String] = {
    val inputData : List[String] = Loader.loadData(path)

    val header = str2List[Int](inputData.head, x => x.toInt )
    val k = header(0)
    val m = header(1)
    val b = inputData.tail.head.toDouble
    val points = inputData.tail.tail.map( s => str2List[Double](s, x => x.toDouble))
    softkmean(points, k, m, b) map( x => listFloat2Str(x) )
  }

  /**
    CODE CHALLENGE: Implement HierarchicalClustering.
    Input: An integer n, followed by an n x n distance matrix.
    Output: The result of applying HierarchicalClustering to 
    this distance matrix (using Davg),
    with each newly created cluster listed on each line.    
    */
  def hierarchicalClustering(path: String) : List[String] = {
    val inputData : List[String] = Loader.loadData(path)
    val n = inputData.head.toInt
    val points = inputData.tail.map( s => str2List[Double](s, x => x.toDouble))
    val distances = HCluster.getDistances(n, points)
    val init = HCluster.getInitialData(n)
    def helper(data: List[HCluster.ClusterData], res: List[String]) : List[String] = {
      data match {
        case Nil => res
        case x::Nil => res
        case x::xs => {
          val pair = HCluster.findmin(data, distances)
          val newData = HCluster.createNewCluster(data, pair)
          //println(newData.size)
          val newCluster = HCluster.merge(pair).toList
          val newResItem = list2Str(newCluster.sorted)
          helper(newData, res :+ newResItem)
        }
      }
    }
    helper(init, List())
  }
}
