package programmers

import java.lang.StringBuilder
import java.util.*

private fun main() {
    solution("110010101001")

}

private fun solution(s: String): IntArray {

    var tmpS = s
    var binaryCount = 0
    var zeroCount = 0

    while (tmpS != "1") {
        zeroCount += tmpS.count { it == '0' }
        tmpS = tmpS.replace("0", "")
        println(tmpS)
        tmpS = toBinary(tmpS.length)
        binaryCount += 1
    }
    return intArrayOf(binaryCount,zeroCount)
}

private fun toBinary(num: Int): String {
    val s = Stack<String>()
    var tmpNum = num
    val result = StringBuilder()
    while (true) {
        if (tmpNum < 2) {
            s.add(tmpNum.toString())
            break
        }
        s.add((tmpNum % 2).toString())
        tmpNum /= 2
    }
    for (i in s.indices) {
        result.append(s.pop())
    }
    return result.toString()
}