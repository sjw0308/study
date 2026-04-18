# 그리디 (LeetCode Version)

기존 백준(BOJ) 문제집의 그리디 알고리즘 문제들을 LeetCode의 동일하거나 가장 유사한 문제로 매칭한 리스트입니다.
| 문제 분류 | BOJ 번호 | BOJ 제목 | LeetCode 문제 | 유사도 |
| :--: | :--: | :--: | :--: | :--: |
| 연습 문제 | 11047 | 동전 0 | [860. Lemonade Change](https://leetcode.com/problems/lemonade-change/) | 보통 (단순 탐욕법) |
| 연습 문제 | 1931 | 회의실 배정 | [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | 동일 |
| 연습 문제 | 2217 | 로프 | [1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) | 보통 |
| 연습 문제 | 1026 | 보물 | [1874. Minimize Product Sum of Two Arrays (Premium)](https://leetcode.com/problems/minimize-product-sum-of-two-arrays/) | 동일 |
| 기본 문제 | 11399 | ATM | [2037. Minimum Number of Moves to Seat Everyone](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/) | 보통 (정렬 후 합산) |
| 기본 문제 | 2457 | 공주님의 정원 | [1024. Video Stitching](https://leetcode.com/problems/video-stitching/) | 높음 |
| 기본 문제 | 1541 | 잃어버린 괄호 | [241. Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) | 보통 |
| 기본 문제 | 11501 | 주식 | [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | 높음 |
| 기본 문제 | 1744 | 수 묶기 | [1005. Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/) | 보통 |
| 기본 문제 | 2847 | 게임을 만든 동준이 | [945. Minimum Increments to Make Array Unique](https://leetcode.com/problems/minimum-increments-to-make-array-unique/) | 보통 |
| 기본 문제 | 1439 | 뒤집기 | [1888. Minimum Number of Flips to Make the Binary String Alternating](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/) | 보통 |
| 기본 문제 | 11000 | 강의실 배정 | [253. Meeting Rooms II (Premium)](https://leetcode.com/problems/meeting-rooms-ii/) | 동일 |
| 기본 문제 | 15903 | 카드 합체 놀이 | [1167. Minimum Cost to Connect Sticks (Premium)](https://leetcode.com/problems/minimum-cost-to-connect-sticks/) | 동일 |
| 응용 문제 | 2170 | 선 긋기 | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) | 높음 |
| 응용 문제 | 1700 | 멀티탭 스케줄링 | [605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/) | 낮음 (LRU/최적 페이지 교체 알고리즘 유사체 부재) |
| 응용 문제 | 8980 | 택배 | [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/) | 낮음 (용량 제한 스케줄링) |
| 응용 문제 | 7570 | 줄 세우기 | [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | 높음 (LIS 응용) |

---
### 💡 참고 사항
* **회의실 배정:** LeetCode의 `435. Non-overlapping Intervals`와 `253. Meeting Rooms II`는 그리디 스케줄링의 가장 전형적인 인터뷰 문제입니다.
* **주식 문제:** 백준 `11501`은 뒤에서부터 탐색하는 그리디라면, LeetCode의 `Best Time to Buy and Sell Stock` 시리즈는 다양한 제약 조건(단 한 번, 무제한, 쿨타임 등)에서의 그리디/DP를 배울 수 있습니다.
* **구현 차이:** `멀티탭 스케줄링(1700)`이나 `택배(8980)` 같은 고난도 그리디는 LeetCode에서 완전히 동일한 문제를 찾기 어려워, 가장 유사한 스케줄링 로직을 사용하는 문제로 대체했습니다.