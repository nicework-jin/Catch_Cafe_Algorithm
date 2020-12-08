package programmers

import kotlin.math.min

private var answer = Int.MAX_VALUE
private fun main() {
    println(solution("ababcdcdababcdcd"))
}

private fun solution(s: String): Int {
    if (s.length==1) return 1
    for (i in 1..s.length / 2) {
        getLength(s, i)
    }
    return answer
}

private fun getLength(s: String, len: Int) {
    val sb = StringBuffer()
    var tmpS = ""
    var count = 1

    for (i in 0..s.length + len step len) {
        var nextS = ""
        nextS = when {
            i >= s.length -> ""
            i + len > s.length -> {
                s.substring(i)
            }
            else -> {
                s.substring(i, len + i)
            }
        }
        if (i != 0) {
            if (tmpS == nextS) {
                count++
            } else if (count >= 2) {
                sb.append("$count$tmpS")
                count = 1
            }else{
                sb.append(tmpS)
            }
        }
        tmpS = nextS
    }
    answer = min(answer, sb.length)
}