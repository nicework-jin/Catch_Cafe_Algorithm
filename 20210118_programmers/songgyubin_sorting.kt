package programmers

import kotlin.math.max


private fun main() {
    println(solution(intArrayOf(3, 0, 6, 1, 5)))

}

private fun solution(citations: IntArray): Int {
    var answer = 0
    var h = 0
    while (true) {
        if (h > citations.max()!!) break
        val upCount = citations.count { it -> it >= h }
        val downCount = citations.count { it -> it <= h }
        if (upCount >= h && downCount <= h) answer = max(answer, h)
        h++
    }

    return answer
}