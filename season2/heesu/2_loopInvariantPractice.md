# Problem

- Consider the searching problem:

- Input: A sequence of _n_ numbers _A = {a1, a2, ..., an}_ and a value _v_.
- Output: An index _i_ such that _v = A[i]_ or the special value _NIL_ if _v_ does not appear in _A_.

- Write pseudocode for linear search, which scans through the sequence, looking for _v_. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulﬁlls the three necessary properties.

# Pseudo code
```
for idx = 1 to A.length
  val = A[idx]
  if val == v
    return idx

return NIL
```

# Proof
- Loop Invariant : 수열 A의 [1, idx-1]번째 원소 중에는 v와 값이 같은 원소가 없다.
- Initialization :  idx가 1일 때, 1부터 idx-1의 사이에는 아무것도 없다. 따라서 v와 같은 값인 원소가 존재할 수 없다.
- Maintenance : if문을 만족(idx번째 원소 값이 v와 같다)하지 못한 경우에만 idx값이 1씩 증가하며 다음 반복문이 시작된다.
반복문을 시작하기 직전 증가한 idx의 값이 if문을 만족하는 상황에도, idx-1까지의 원소는 모두 if문을 만족하지 못 했으므로 v와 값이 다르다.
- Termination : if문을 만족(idx번째 원소 값이 v와 같다)하거나 모든 원소가 조건을 통과하지 못 하고 idx=A.length+1이 되었을 때 반복문이 종료된다. 각각의 경우에 모두 1부터 idx-1번째 원소 중에는 v와 같은 값을 가지는 원소가 없다.
