libraryDependencies += "org.scalacheck" %% "scalacheck" % "latest.milestone" % "test"
//libraryDependencies += "org.scalatest" %% "scalatest" % "latest.milestone" % " "test"
//libraryDependencies += "org.specs2" %% "specs2-scalacheck" % "latest.milestone" % "test"

lazy val root = (project in file(".")).
  settings(
    name := "category"      
  )
