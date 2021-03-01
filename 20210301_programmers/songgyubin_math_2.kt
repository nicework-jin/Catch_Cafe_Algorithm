@file:JvmName("Songgyubin_mathKt")

package programmers

private fun main() {
    println(solution(10,2).joinToString())
}

private fun solution(brown: Int, yellow: Int): IntArray {
    val sum = brown + yellow;
    var tmpH = 3
    while (true) {
        if (sum%tmpH==0) {
            val w = sum / tmpH;
            if (((tmpH - 2) * (w - 2)) == yellow) {
                return intArrayOf(w, tmpH)
            }
        }
        tmpH++
    }
}