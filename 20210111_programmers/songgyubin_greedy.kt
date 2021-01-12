package programmers

import kotlin.math.min

private fun main() {
    println(solution("JAZ"))
    println(solution("AABA"))
    println(solution("JEROEN"))
    println(solution("JAN"))
}

private fun solution(name: String): Int {
    var answer = 0

    var len = name.length
    var move = len - 1

    for (i in 0 until len) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1)

        var next = i + 1
        while (next < len && name[next] == 'A') next++
        move = min(move, i + len - (next - i))
    }
    answer += move

    return answer
}