
import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    
    repeat(t) {
        val x = scanner.nextInt()
        val y = scanner.nextInt()
        println("${minOf(x, y)} ${maxOf(x, y)}")
    }
}
