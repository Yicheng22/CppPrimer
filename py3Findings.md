# Leetcode  Python3 Practice

## 406. Queue Rreconstruction by Height

* sort() by key use lambda

  ```python
  vector = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
  # sort vector, first element decrease, second element increase
  vector.sort(key = lambda element: -element[0],element[1])
  ```
