# LeetCode C++ Practice

## 1. Two Sum

* include map vector when needed
* map is hashtable
* map.find(key) == map.end() **equal to**  key not existed in the map
* array use {} instead of [] in the python

## 2. Add Two Numbers

* pointer to implement linkedList

## 3. Longest Substring Without Repeating Characters

* optimized sliding window: using map to memorize the last seen duplicated characters
* c++ will convert character to int when use in vector: when s = "apa", v['a'] == v[97] == v[s.at[2]]

## 4.Median of Two Sorted Array

* binary search the divide point in one the array. the position in other array can be calculated.
* when len( left_part) == len(right_part)  maxLeft < minRight, we can find the median

## 8.String to Integer(atoi)

* INT_MAX, INT_MIN belong to \<limits.h\>

## 135. Candy

* greedy algorithm: proof of the correctness
* accmulate(v.begin(), v.end(),0) included in \<numeric>

## 406. Queue Reconstruction by Height

* sort(v.begin(), v.end(), function)
* sort  2d vector, first element descending, second element ascending

  ```cpp
  sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b) {
       return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
       });
  ```

## 432. Minimum Number of Arrows to Burst Ballons

* count the non-overlapping ballon. same edge also count as overlapping like [1,2] and [2,3]

## 435. Non-overlapping Intervals

* lambda expression to sort in the desired way
* two-dimension vectors: vector<vector\<int\>>
* greedy algorith: if two interval overlapped, save the one have small end. [1,4] and [3,5], remove [3,5]

## 455.Assign Cookies

* sort(v.begin(), v.end()) included in \<algorithm>
* greedy algorithm: proof of the correctness

## 605. Can Place Flowers

* good truth table practice: three condition need to meet, position == 0, before is 0 , after is 0
  before is 0 consist of i == 0 || v[i-1] == 0, so does after is 0
* for or "||" operation, if first argument is true. The program won\'t evaluate the second
  if (i==0|| v[i-1] == 0) , only when i != 0, v[i-1] will be evaluated. Therefore, the code won\'t access v[0-1]

# To-do

## Learn accmulate()

## proof of greedy algorithm 135,435,455,605
