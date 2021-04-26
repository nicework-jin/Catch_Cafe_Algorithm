@file:JvmName("Songgyubin_implementsKt")

package programmers

import java.util.*
import kotlin.collections.ArrayDeque


private fun main() {
    val s = "abcd"
    val a = ArrayDeque<Char>()
    for (i in 0 until s.length) {
        a.add(s[i])
    }
    /* for (i in 0 until a.size){
         println(a.removeFirst())
     }*/
//    println(a.joinToString(""))
    println(solution("[)(]"))
}

private fun solution(s: String): Int {
    var answer: Int = 0

    var ad = java.util.ArrayDeque<Char>()
    for (i in s.indices) ad.add(s[i])
    var rotatedS = ad
    for (i in s.indices) {
        if (isRight(rotatedS.joinToString(""))) answer += 1
        rotatedS = rotate(rotatedS)
    }
    return answer
}

private fun rotate(s: java.util.ArrayDeque<Char>): java.util.ArrayDeque<Char> {
    val head = s.removeFirst()
    s.addLast(head)
    return s
}

private fun isRight(s: String): Boolean {
    val stack = Stack<Char>()
    for (i in 0 until s.length) {
        try {
            when (s[i]) {
                '[' -> stack.add('[')
                ']' -> {
                    if (stack.peek() != '[') return false
                    stack.pop()
                }
                '{' -> stack.add('{')
                '}' -> {
                    if (stack.peek() != '{') return false
                    stack.pop()
                }
                '(' -> stack.add('(')
                ')' -> {
                    if (stack.peek() != '(') return false
                    stack.pop()
                }
            }
        } catch (e: Exception) {
            return false
        }
    }
    return if (stack.isEmpty()) true else false
}