package programmers

import java.util.*

private lateinit var pq: PriorityQueue<MyString>

private fun main() {

    println(solution(intArrayOf(6, 10, 2)))

}

private fun solution(numbers: IntArray): String {
    var answer = StringBuffer()
    pq = PriorityQueue<MyString>()

    numbers.forEach {
        pq.add(MyString(it.toString()))
    }
    if (pq.peek().s=="0") return "0"
    while (pq.isNotEmpty()){
        answer.append(pq.poll().s)
    }
    return answer.toString()
}

data class MyString(val s: String) : Comparable<MyString> {
    override fun compareTo(other: MyString): Int = ("${other.s}${this.s}").compareTo("${this.s}${other.s}")

}