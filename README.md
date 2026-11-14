# CAP2012 CA3 — LeetCode Solutions

Solutions are written in C++ and grouped by LeetCode difficulty. Each source
file can be pasted into LeetCode; code used only by the local examples is
guarded by `#ifdef LOCAL_TEST`.

| S.No. | LeetCode problem | Difficulty | Topic | Approach |
|---:|---|---|---|---|
| 01 | LC088 Merge Sorted Array | Easy | Arrays, two pointers | Fill the first array from the end using the larger of the two remaining values. |
| 02 | LC1281 Subtract the Product and Sum of Digits of an Integer | Easy | Number, arithmetic | Visit each digit once and maintain its product and sum. |
| 03 | LC026 Remove Duplicates from Sorted Array | Easy | Arrays, two pointers | Copy each new value to the next write position. |
| 04 | LC027 Remove Element | Easy | Arrays, two pointers | Copy values that differ from the target into a compact prefix. |
| 05 | LC509 Fibonacci Number | Easy | Dynamic programming | Build the sequence from the two previous values. |
| 06 | LC206 Reverse Linked List | Easy | Linked list | Reverse each link iteratively while keeping the next node safe. |
| 07 | LC083 Remove Duplicates from Sorted List | Easy | Linked list | Skip adjacent equal-valued nodes in the sorted list. |
| 08 | LC020 Valid Parentheses | Easy | Stack, strings | Use a vector as a stack of opening brackets and match each close. |
| 09 | LC232 Implement Queue using Stacks | Easy | Stack, queue | Use input and output vectors as stacks to produce FIFO order. |
| 10 | LC189 Rotate Array | Medium | Arrays, in-place | Reverse the whole array and then reverse each resulting section. |
| 11 | LC092 Reverse Linked List II | Medium | Linked list | Move nodes to the front of the selected section. |
| 12 | LC061 Rotate List | Medium | Linked list | Form a temporary ring, locate the new tail, and break the ring. |
| 13 | LC155 Min Stack | Medium | Stack | Store the minimum at each stack depth in a second vector. |
| 14 | LC622 Design Circular Queue | Medium | Queue, array | Track the front and count; wrap array positions using modulo. |
| 15 | LC023 Merge k Sorted Lists | Hard | Linked list, divide and conquer | Merge pairs of lists in rounds, linking existing nodes in order. |
| 16 | LC032 Longest Valid Parentheses | Hard | Stack, strings | Track unmatched-parenthesis indices and calculate valid spans. |

## Local tests

Compile and run any solution from this repository folder:

```text
g++ -DLOCAL_TEST -o test Easy/05_LC509_FibonacciNumber_Easy.cpp
test
```

Each file's local test program prints expected and actual results. The
`LOCAL_TEST` guard keeps its `main()` and any test-only `ListNode` definition
out of the LeetCode submission.
