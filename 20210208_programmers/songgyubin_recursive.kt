package programmers


private fun main() {
    val numbers = intArrayOf(1, 1, 1, 1, 1)
    val target = 3
    println(solution(numbers, target))
}

private fun solution(numbers: IntArray, target: Int): Int {
    var answer = 0
    answer = calc(numbers, target, numbers[0], 1) + calc(numbers, target, -numbers[0], 1)
    return answer
}

private fun calc(numbers: IntArray, target: Int, sum: Int, i: Int): Int {
    if (i == numbers.size) {
        return if (sum == target)
            1
        else 0
    }
    var result = 0
    result += calc(numbers, target, sum + numbers[i], i + 1)
    result += calc(numbers, target, sum - numbers[i], i + 1)
    return result


}

