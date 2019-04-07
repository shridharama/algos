import java.util.Scanner
object Solution {

  def main(args: Array[String]): Unit = {
    val scanner = new Scanner(System.in)
    val T:Int = scanner.nextInt()
    for(i <- 1 to T){  
      val N: String = scanner.nextLine()
      val A = new StringBuilder
      val B = new StringBuilder
      var buildB:Boolean = false
      N.map{ c => 
        if(c == '4'){
          A+= '3'
          B+= '1'
          buildB = true
        } else {
          A+= c
          if(buildB)
            B+= '0'
        }
      }
      println(s"Case #${i}: $A $B")
    }
  }
}
