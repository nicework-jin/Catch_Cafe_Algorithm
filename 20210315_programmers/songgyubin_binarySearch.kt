package programmers

private fun solution(info: Array<String>, query: Array<String>): IntArray {

    val dic: MutableMap<String, ArrayList<Int>> = mutableMapOf()
    info.forEach {
        val s_score = it.substringAfterLast(" ")
        val key = it.substring(0 until it.length - s_score.length).split(" ")


        fun make(pos: Int, str: String) {

            if (pos == 4) {
                if (dic[str] == null) {
                    dic[str] = ArrayList()
                }

                dic[str]!!.add(s_score.toInt())
                return
            }

            make(pos + 1, str + key[pos])
            make(pos + 1, "$str-")

        }
        make(0, "")
    }

    val answer = ArrayList<Int>()

    for (key in dic.keys) {
        dic[key]!!.sort()
    }

    query.forEach {
        val sScore = it.substringAfterLast(" ")
        val qKey = it.substring(0 until it.length - sScore.length - 1).replace(" and ", "")

        if (dic[qKey] == null) {
            answer.add(0)
            return@forEach
        } else if (dic[qKey]!!.size == 0) {
            answer.add(0)
            return@forEach
        }


        val sortedScore = dic[qKey]!!

        var left = 0
        var right = sortedScore.size
        val target = sScore.toInt()

        while (left < right) {

            val mid = (left + right) / 2

            if (sortedScore[mid] >= target) {
                right = mid

            } else {
                left = mid + 1
            }

        }

        answer.add(sortedScore.size - left)

    }

    return answer.toIntArray()
}
