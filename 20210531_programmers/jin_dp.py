import heapq

MAX_TIME = 500001


def solution(N, road, K):
    # 1번 마을에 있는 음식점이 K 이하의 시간에 배달이 가능한 마을의 개수를 return 하면 됩니다.

    graph = [[] for _ in range(N)]
    for a, b, c in road:
        graph[a - 1].append([b - 1, c])
        graph[b - 1].append([a - 1, c])

    minimum_time_per_nodes = [MAX_TIME] * N

    heapq.heappush(q := [], [target_to_q := 0, curr_time := 0])
    minimum_time_per_nodes[0] = 0
    while q:
        target_to_q, curr_time = heapq.heappop(q)
        for target_to_mtpn, time in graph[target_to_q]:
            if (expect_time := curr_time + time) > K:
                continue
            if expect_time >= minimum_time_per_nodes[target_to_mtpn]:
                continue
            minimum_time_per_nodes[target_to_mtpn] = expect_time
            heapq.heappush(q, [target_to_mtpn, expect_time])
    return len([x for x in minimum_time_per_nodes if x < MAX_TIME])


if __name__ == '__main__':
    # N = 5
    # road = [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]]
    # K = 3

    N = 6
    road = [[1, 2, 1], [1, 3, 2], [2, 3, 2], [3, 4, 3], [3, 5, 2], [3, 5, 3], [5, 6, 1]]
    K = 4
    print(solution(N, road, K))
