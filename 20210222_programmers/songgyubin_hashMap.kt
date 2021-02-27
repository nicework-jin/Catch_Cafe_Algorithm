package programmers

private fun main() {

//    println(solution())
}

private fun solution(clothes: Array<Array<String>>): Int {
    var answer = 1
    val spy : HashMap<String, Int> = HashMap()
    for (i in clothes.indices) {
        val tmp = clothes[i]
        if (!spy.containsKey(tmp[1])){
            spy[tmp[1]] = 1
        }
        else{
            spy.replace(tmp[1],spy[tmp[1]]!!+1)
        }
    }
    for (i in spy.keys) {
        answer *= (spy[i]!!.toInt() + 1)
    }
    return answer - 1
}