
import java.util.*

fun isBeautifulBinaryMatrix(M: List<List<Int>>): Boolean {
    val n = M.size

    for (i in 0 until n) {
        for (j in 0 until n) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                if (M[i][j] != 1) {
                    return false
                }
            } else if (M[i][j] != 0) {
                return false
            }
        }
    }
    return true
}

fun convert(s: String, r: Int): List<List<Int>> {
    val M = mutableListOf<List<Int>>()
    val n = s.length
    var cont = 0

    for (i in 0 until r) {
        val row = mutableListOf<Int>()
        for (j in 0 until (n / r)) {
            row.add(s[cont] - '0')
            cont++
        }
        M.add(row)
    }

    return M
}

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    scanner.nextLine()

    repeat(t) {
        val n = scanner.nextInt()
        scanner.nextLine()  // Consume newline
        val s = scanner.nextLine()

        var found = false
        for (i in 2..n) {
            if (n % i == 0) {
                val M = convert(s, i)
                if (isBeautifulBinaryMatrix(M)) {
                    println("Yes")
                    found = true
                    break
                }
            }
        }

        if (!found) {
            println("No")
        }
    }
}
