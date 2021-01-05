package programmers

private lateinit var hs: HashSet<Int>
private lateinit var vis: BooleanArray
private fun main() {

    println(solution("011"))
}

private fun solution(numbers: String): Int {
    hs = HashSet()
    vis = BooleanArray(numbers.length)
    for (i in 1..numbers.length) {
        comb(numbers, "", i)
    }
    return hs.size
}

private fun comb(num: String, s: String, n: Int) {
    if (s.length == n) {
        if (isPrime(s.toInt())) hs.add(s.toInt())
        return
    }
    for (i in num.indices) {
        if (vis[i]) continue
        vis[i] = true
        comb(num, s + num[i], n)
        vis[i] = false
    }

}

private fun isPrime(num: Int): Boolean {
    if (num == 1 || num == 0) return false
    for (i in 2 until num) {
        if (num % i == 0) return false
    }
    return true

}