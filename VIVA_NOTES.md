# CAP2012 CA3 — Viva Notes

## 01. LC088 — Merge Sorted Array (Easy)

- **In simple words:** Put two already-sorted arrays together in sorted order, using the spare space at the end of the first array.
- **Steps:** Start at the end of both sorted portions; compare their current largest values; write the larger one at the end of `nums1`; continue until all values from `nums2` are placed.
- **Complexity:** O(m+n) time because each value is considered at most once; O(1) extra space because the output is written in the supplied array.
- **Tests:** `[1,2,3,0,0,0]`, `[2,5,6]` -> `[1,2,2,3,5,6]`; `[1]`, `[]` -> `[1]`; `[0]`, `[1]` with `m=0` -> `[1]`.
- **Follow-up:** Why fill from the back? **Answer:** Writing from the front could overwrite values from the first array that have not yet been compared.
- **Variation:** If no spare space were available, create a separate result array and merge into it, using O(m+n) extra space.

## 02. LC1281 — Subtract the Product and Sum of Digits of an Integer (Easy)

- **In simple words:** Find the product of a number's digits and subtract the sum of those digits.
- **Steps:** Get the last digit with `% 10`; update product and sum; remove that digit with `/ 10`; repeat until no digits remain.
- **Complexity:** O(d) time for d digits; O(1) extra space for the two running totals.
- **Tests:** `234` -> `15`; `4421` -> `21`; `10` -> `-1`.
- **Follow-up:** How is a digit obtained? **Answer:** `n % 10` gives the final decimal digit, and integer division by 10 removes it.
- **Variation:** For a negative input, first use its absolute value, then process its digits.

## 03. LC026 — Remove Duplicates from Sorted Array (Easy)

- **In simple words:** Keep one copy of each value in the sorted array and return the new logical length.
- **Steps:** Handle an empty array; keep a write index after the first unique value; scan the rest; copy a value only when it differs from the last kept value.
- **Complexity:** O(n) time for one scan; O(1) extra space because compaction happens in place.
- **Tests:** `[1,1,2]` -> length `2`, prefix `[1,2]`; `[0,0,1,1,2]` -> length `3`, prefix `[0,1,2]`; `[]` -> length `0`.
- **Follow-up:** Why does comparing only with the last kept value work? **Answer:** Sorting places all copies together, so the last kept value is the only prior value that can be a duplicate.
- **Variation:** For an unsorted array, sort first; then compact it, with O(n log n) total time.

## 04. LC027 — Remove Element (Easy)

- **In simple words:** Remove every copy of a chosen value and return the length of the remaining prefix.
- **Steps:** Set the write index to zero; scan every value; when it is not the target, copy it at the write index and advance that index.
- **Complexity:** O(n) time because the array is scanned once; O(1) extra space because values are overwritten in place.
- **Tests:** `[3,2,2,3]`, target `3` -> length `2`, prefix `[2,2]`; `[0,1,2,2,3,0,4,2]`, target `2` -> length `5`, prefix `[0,1,3,0,4]`; `[4,4]`, target `4` -> length `0`.
- **Follow-up:** Must the remaining values keep their original order? **Answer:** This implementation preserves the order, though the problem only requires the correct values in the returned prefix.
- **Variation:** If order does not matter, swap a target value with the last unchecked value to reduce writes in some inputs.

## 05. LC509 — Fibonacci Number (Easy)

- **In simple words:** Return the value at position `n` in the sequence starting `0, 1`.
- **Steps:** Return `n` for positions zero and one; remember the previous two values; repeatedly add them and shift forward until reaching `n`.
- **Complexity:** O(n) time because each position is computed once; O(1) extra space because only two prior values are stored.
- **Tests:** `2` -> `1`; `4` -> `3`; `10` -> `55`.
- **Follow-up:** Why not use plain recursion? **Answer:** Plain recursion recalculates the same smaller Fibonacci values many times, making it exponential.
- **Variation:** If many queries are made, precompute the sequence once in an array up to the largest requested index.

## 06. LC206 — Reverse Linked List (Easy)

- **In simple words:** Make the last node of a linked list become its first node.
- **Steps:** Keep `previous` and `current` pointers; save `current->next`; point the current node backward; advance both pointers; return the final previous node.
- **Complexity:** O(n) time because each node is visited once; O(1) extra space because only pointers are used.
- **Tests:** `1->2->3->4->5` -> `5->4->3->2->1`; empty list -> empty list; `7` -> `7`.
- **Follow-up:** Why save the next pointer first? **Answer:** Reversing the link would otherwise lose access to the rest of the original list.
- **Variation:** A recursive version can reverse the tail first, but uses O(n) call-stack space.

## 07. LC083 — Remove Duplicates from Sorted List (Easy)

- **In simple words:** Keep just one node for each value in a sorted linked list.
- **Steps:** Check the current node and its next node; if values match, bypass and delete the next node; otherwise advance; stop at the tail.
- **Complexity:** O(n) time because the list is traversed once; O(1) extra space because links are updated in place.
- **Tests:** `1->1->2` -> `1->2`; `1->1->2->3->3` -> `1->2->3`; empty list -> empty list.
- **Follow-up:** Why is it enough to compare neighboring nodes? **Answer:** In a sorted list, equal values appear consecutively.
- **Variation:** To keep only values that occur once, first count each run, then link only runs of length one.

## 08. LC020 — Valid Parentheses (Easy)

- **In simple words:** Check whether each opening bracket is closed by the correct type in the correct order.
- **Steps:** Push opening brackets on a vector used as a stack; for every closing bracket, require and remove a matching top; accept only if no openings remain.
- **Complexity:** O(n) time because each character is processed once; O(n) extra space in the case of all opening brackets.
- **Tests:** `"()"` -> true; `"()[]{}"` -> true; `"([)]"` -> false.
- **Follow-up:** Why does the last opened bracket need to close first? **Answer:** Nested brackets follow last-in, first-out order, which is exactly a stack's behavior.
- **Variation:** To validate brackets mixed with other characters, explicitly ignore characters that are not brackets.

## 09. LC232 — Implement Queue using Stacks (Easy)

- **In simple words:** Build a first-in, first-out queue using two last-in, first-out stacks.
- **Steps:** Push new items onto the input stack; before reading/removing the front, if the output stack is empty, move every input item onto it; read or remove its top.
- **Complexity:** Amortized O(1) per operation; each item moves from input to output at most once. Space is O(n) for stored items.
- **Tests:** push `1,2`, peek -> `1`; pop -> `1`, then pop -> `2`; new queue `empty()` -> true.
- **Follow-up:** Why is `pop` amortized O(1) despite transferring items? **Answer:** Each item is transferred only once, so the transfer cost is spread across the queue operations.
- **Variation:** A thread-safe queue would need synchronization around pushes, transfers, and removals.

## 10. LC189 — Rotate Array (Medium)

- **In simple words:** Move each array value `k` positions to the right, wrapping values from the end to the start.
- **Steps:** Reduce `k` modulo the length; reverse the whole array; reverse the first `k` values; reverse the remaining values.
- **Complexity:** O(n) time across three reversals; O(1) extra space because swaps are in place.
- **Tests:** `[1,2,3,4,5,6,7]`, `k=3` -> `[5,6,7,1,2,3,4]`; `[-1,-100,3,99]`, `k=2` -> `[3,99,-1,-100]`; `[1,2]`, `k=0` -> `[1,2]`.
- **Follow-up:** Why reduce `k` modulo the length? **Answer:** Every full-length rotation restores the original array.
- **Variation:** To rotate left, use the same method with `length - (k % length)` right rotations.

## 11. LC092 — Reverse Linked List II (Medium)

- **In simple words:** Reverse only the nodes between two one-based positions in a list.
- **Steps:** Use a dummy node so the head can be changed uniformly; stop just before the section; repeatedly take the next section node and insert it at the section's front.
- **Complexity:** O(n) time to reach and reverse the section; O(1) extra space for pointers.
- **Tests:** `1->2->3->4->5`, positions `2..4` -> `1->4->3->2->5`; `5`, positions `1..1` -> `5`; `1->2->3`, positions `1..3` -> `3->2->1`.
- **Follow-up:** What does the dummy node solve? **Answer:** It gives the head a predecessor, so reversing from position one needs no special link case.
- **Variation:** To reverse a zero-based half-open range, adjust the initial traversal and number of front insertions to match those bounds.

## 12. LC061 — Rotate List (Medium)

- **In simple words:** Move the last `k` nodes of a list to its beginning.
- **Steps:** Find the length and tail; reduce rotations modulo the length; connect tail to head; walk to the new tail; break the ring and return the next node.
- **Complexity:** O(n) time for length and new-tail traversal; O(1) extra space.
- **Tests:** `1->2->3->4->5`, `k=2` -> `4->5->1->2->3`; `0->1->2`, `k=4` -> `2->0->1`; empty list -> empty list.
- **Follow-up:** Why make a ring temporarily? **Answer:** It lets the new tail link to the original head without changing nodes one by one.
- **Variation:** For left rotation, convert it to a right rotation of `length - (k % length)`.

## 13. LC155 — Min Stack (Medium)

- **In simple words:** Make a stack that can report its smallest current value quickly.
- **Steps:** Store every value in one vector; store a value in a second vector whenever it is no larger than the current minimum; remove from both when the popped value equals the current minimum.
- **Complexity:** O(1) per operation; O(n) space for the values and stored minimums.
- **Tests:** push `-2,0,-3`, getMin -> `-3`; pop, top -> `0`; getMin -> `-2`; push duplicate minimums and pop one -> minimum remains `2`.
- **Follow-up:** Why store duplicate minimum values too? **Answer:** If the same minimum is pushed more than once, it must remain the minimum after one copy is popped.
- **Variation:** A min queue can use two min stacks, one for incoming and one for outgoing values.

## 14. LC622 — Design Circular Queue (Medium)

- **In simple words:** Implement a fixed-capacity queue that reuses slots at the beginning after removals.
- **Steps:** Keep a vector, the front index, and the number of items; place new values at `(front + count) % capacity`; advance the front with modulo on removal.
- **Complexity:** O(1) per operation; O(k) space for a queue of capacity k.
- **Tests:** capacity `3`, enqueue `1,2,3`, then enqueue `4` -> false; dequeue then enqueue `4` -> true and rear `4`; capacity `1`, enqueue/dequeue -> true.
- **Follow-up:** How can full and empty be distinguished? **Answer:** Track the element count: zero is empty and capacity is full.
- **Variation:** To grow dynamically, allocate a larger array and copy values in queue order starting at the front.

## 15. LC023 — Merge k Sorted Lists (Hard)

- **In simple words:** Combine several individually sorted linked lists into one sorted list.
- **Steps:** Merge pairs of lists using pointer comparisons; double the pair interval each round; continue until one merged list remains.
- **Complexity:** O(N log k) time because each round processes all N nodes and there are about log k rounds; O(1) extra working space because existing nodes are linked.
- **Tests:** `[1,4,5]`, `[1,3,4]`, `[2,6]` -> `[1,1,2,3,4,4,5,6]`; no lists -> empty list; one list `-1->0->3` -> unchanged.
- **Follow-up:** Why is pairwise divide-and-conquer better than merging each list into the result one by one? **Answer:** Balanced rounds avoid repeatedly processing a growing result, giving O(N log k) time.
- **Variation:** A min-heap holding one current node per list also gives O(N log k) time, using O(k) extra space.

## 16. LC032 — Longest Valid Parentheses (Hard)

- **In simple words:** Find the length of the longest contiguous substring containing correctly matched parentheses.
- **Steps:** Store opening indices on a vector stack; seed it with `-1` as the boundary; on a closing bracket, pop; if empty, reset the boundary, otherwise measure the current valid span.
- **Complexity:** O(n) time because each index is pushed and popped at most once; O(n) extra space for indices.
- **Tests:** `"(()"` -> `2`; `")()())"` -> `4`; `"()(())"` -> `6`.
- **Follow-up:** What is the initial `-1` index for? **Answer:** It acts as the boundary before a valid substring that begins at index zero.
- **Variation:** A two-pass counter method can solve the parentheses-only version with O(1) extra space by scanning left-to-right and right-to-left.
