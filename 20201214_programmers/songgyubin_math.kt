package programmers

private fun main() {
    solution(4).forEach { print("$it ") }
}

fun solution(n: Int): IntArray {
    val answer = IntArray(n * (n + 1) / 2)
    val matrix = Array(n) { IntArray(n) }

    var x = -1
    var y = 0
    var num = 1

    for (i in 0 until n) {
        for (j in i until n) {
            when {
                i % 3 == 0 -> {
                    x++
                }
                i % 3 == 1 -> {
                    y++
                }
                i % 3 == 2 -> {
                    x--
                    y--
                }
            }
            matrix[x][y] = num++
        }
    }

    var k = 0
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (matrix[i][j] == 0) break
            answer[k++] = matrix[i][j]
        }
    }
    return answer
}