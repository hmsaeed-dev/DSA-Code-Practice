# Linked List in C++

## 1. Theory, Types & Memory

- linear collection of **self-referential nodes** (data + pointer(s) to the same node type). Nodes are **non-contiguous**, allocated on the heap (`new`), released with `delete`. The list is reached only via `head` (optionally `tail`). Grows/shrinks dynamically, with no capacity or resizing.
- **SLL (singly):** `data` + `next`; forward traversal only; tail `next = nullptr`.
- **DLL (doubly):** `prev`, `data`, `next`; bidirectional; head `prev = nullptr`, tail `next = nullptr`.
- **CSLL (circular singly):** tail `next` -> head; no `nullptr` anywhere.
- **CDLL:** tail `next` -> head and head `prev` -> tail.
- **Header list:** dummy/sentinel node at the front holding metadata (node count, max value); removes empty-list edge cases.
- **Node:** `struct Node { int data; Node* next; Node(int v) : data(v), next(nullptr) {} };` (struct = public by default; a `class Node` needs `public:` members or `friend class LinkedList`). A node cannot contain a `Node` by value (infinite size), only `Node*`.
- **Sizes:** `sizeof(Node*)` is 4 B (32-bit) or 8 B (64-bit) regardless of payload. `sizeof(Node)` for `int + pointer` is **16 B on 64-bit** (4 B padding).
- **Pros:** O(1) insert/delete at a known position, no shifting, no reallocation, flexible size.
- **Cons:** no random access, extra pointer memory per node, poor cache locality (poor spatial locality -> many cache misses), no efficient binary search.
- **Applications:** stacks/queues (O(1) at head/tail), hash-table chaining, graph adjacency lists, LRU cache (DLL + hash map), undo/redo and browser history (DLL), round-robin scheduling and Josephus problem (circular), polynomial arithmetic, allocator free-lists.

## 2. Complexity

| Operation                    | Array / `std::vector`    | Singly LL                          | Doubly LL               |
| ---------------------------- | -------------------------- | ---------------------------------- | ----------------------- |
| Access k-th                  | O(1)                       | O(n)                               | O(n)                    |
| Search (unsorted)            | O(n)                       | O(n)                               | O(n)                    |
| Search (sorted)              | O(log n) binary search     | O(n) (no random access)            | O(n)                    |
| Insert at beginning          | O(n)                       | O(1)                               | O(1)                    |
| Insert at end (with tail)    | O(1) amortized             | O(1)                               | O(1)                    |
| Insert at end (no tail)      | O(1) amortized             | O(n)                               | O(n)                    |
| Insert at position k         | O(n)                       | O(n) (walk) + O(1) link            | O(n) + O(1)             |
| Insert after known pointer p | O(n)                       | O(1)                               | O(1)                    |
| Delete at beginning          | O(n)                       | O(1)                               | O(1)                    |
| Delete at end (with tail)    | O(1)                       | O(n) (needs predecessor)           | O(1) via `tail->prev` |
| Delete given pointer p       | O(n)                       | O(n), or O(1) with node-copy trick | O(1)                    |
| Length (no size counter)     | O(1)                       | O(n)                               | O(n)                    |
| Extra space per node         | 0 (besides spare capacity) | 1 pointer (4/8 B)                  | 2 pointers (8/16 B)     |

All linked-list traversal is O(n) time, O(1) space unless recursive (then O(n) stack).

## 3.

- **Modifying head inside a function:** passing `Node* head` by value changes only a local copy. Use `Node** head` (C style, call `f(&head)`, write `*head`) or `Node*& head` (idiomatic C++)
- **Memory leak:** reassigning/overwriting a pointer (or losing `head`) before `delete` orphans heap memory. **Dangling pointer:** `delete temp; temp->next;` is undefined behavior, so save `next` first, and set the pointer to `nullptr` after delete.
- **Linking order matters:** on insertion set `n->next = cur->next` *before* `cur->next = n`, otherwise the rest of the list is lost. In a DLL update all four links.
- **Rule of three/five:** a class owning raw nodes needs a destructor, copy constructor and copy assignment (or move versions); otherwise delete them. `new`/`delete` pair, never mix with `malloc`/`free` or `delete[]`.
- **Smart pointers:** `unique_ptr<Node>` next-links give automatic cleanup, but destroying a very long list recurses and can overflow the stack, so free iteratively. For DLL use `shared_ptr` forward and `weak_ptr` backward to avoid cycles.
- **STL:** `std::list<T>` = doubly linked (bidirectional iterators, `push_front/back`, `size()` O(1), O(1) `splice`, member `sort()` because `std::sort` needs random access). `std::forward_list<T>` = singly linked (forward iterators, one pointer per node, **no `size()`, no `push_back`**, uses `push_front`, `insert_after`, `erase_after`, `before_begin()`). Neither supports `[]`. Erasing from a list invalidates only iterators to the erased element (unlike `vector`, which invalidates from the point of change or on reallocation).

## 4. Algorithmic Patterns & Edge Cases

- **Floyd's cycle detection (tortoise & hare):** `slow = slow->next; fast = fast->next->next;` cycle exists iff `slow == fast` (check `fast && fast->next` first). **Cycle start:** reset `slow = head`, advance both one step until they meet (distance head -> start equals meeting point -> start, modulo cycle length). **Cycle length:** freeze one pointer at the meeting point, advance the other and count steps until they meet again. To remove the cycle, stop at the node whose `next` is the start and set it to `nullptr`. O(n) time, O(1) space.
- **Middle node:** fast moves 2, slow moves 1; when fast hits the end, slow is the middle (for even length it is the second middle with `while(fast && fast->next)`, the first middle with `while(fast->next && fast->next->next)`).
- **Iterative reversal:** `prev = nullptr, curr = head`; loop `next = curr->next; curr->next = prev; prev = curr; curr = next;` then `head = prev`. O(n) time, O(1) space.
- **Recursive reversal:** O(n) time, O(n) call-stack space.
- **K-th node from end:** two pointers; advance the first k steps, then move both until the first is `nullptr`.
- **Delete k-th from end:** same with a dummy node so the head can be removed uniformly.
- **Intersection of two lists (Y-shape):** compute lengths, advance the longer by the difference, walk together until pointers are equal. Or redirect: `p1 = p1 ? p1->next : head2; p2 = p2 ? p2->next : head1;` meets at the intersection or at `nullptr`. Compare node **addresses**, not values.
- **Merge two sorted lists:** dummy head + tail pointer, pick the smaller node each time, attach the leftover. O(n+m) time, O(1) space.
- **Sort a list:** **merge sort** is the best fit, O(n log n) time (O(log n) stack, or O(1) bottom-up). Quick sort works poorly and heap sort is not practical without random access. Insertion sort on a list is O(n^2).
- **Palindrome check:** find middle, reverse the second half, compare, (restore). O(n) time, O(1) space.
- **Dummy (sentinel) node technique:** put a dummy before `head` so insert/delete at the front needs no special case, then return `dummy.next`.
- **Circular lists:** traverse with `do { ... } while (p != head);` (a plain `while (p != nullptr)` loops forever). Keeping only a **tail** pointer gives O(1) insert at both front (`tail->next`) and back. Josephus problem = repeatedly delete every k-th node of a CSLL.
- **Mandatory edge cases:** (1) `head == nullptr` (empty), (2) `head->next == nullptr` (single node), (3) changing the head (update the head pointer), (4) changing the tail (set the previous node's `next = nullptr`, update `tail`), (5) never dereference `p->next->next` without checking both, (6) duplicates and value not found.

## 5. High-Yield MCQ Facts & Traps

- **Random access / binary search:** impossible in O(1)/O(log n) on a linked list, even if sorted; search is O(n) always.
- **Null pointers:** SLL has 1 null pointer (tail `next`), DLL has 2 (head `prev`, tail `next`), circular lists have 0 (unless empty).
- **Deleting at the end of an SLL is O(n)** (needs the predecessor) even with a tail pointer; with a DLL it is O(1). Inserting at the end is O(1) only if a tail pointer exists. Insertion/deletion at the head is O(1) for every type, so stack push/pop use the head.
- **Queue with linked list:** enqueue at tail, dequeue at head, both O(1) with a tail pointer.
- **Delete a node given only a pointer in O(1) (SLL trick):** copy `node->next->data` into `node`, set `node->next = node->next->next`, free the old next. **Fails for the last node**, and invalidates other pointers/iterators to the removed next node.
- **Skip list:** probabilistic layered linked lists giving O(log n) average search, insert and delete.
- **XOR linked list:** memory-efficient DLL storing `prev XOR next` in a single `uintptr_t` field; traversal needs the address of one neighbour; unsafe with garbage collectors and smart pointers.
- **Insert in a sorted SLL** is O(n) (find position) but O(1) once the position is known. **Length** without a counter is O(n).
- **Cache locality:** arrays win on traversal speed in practice because of spatial locality, even where Big-O is equal.
- **Recursion trap:** recursive reversal/traversal of a long list can overflow the stack; O(n) auxiliary space.
- **Pointer-copy trap:** `Node* a = b;` copies the address, not the node; both point to the same node, so deleting through one dangles the other. Assigning `Node n = *p;` copies the node (its `next` still points to the old successor).
- **Pass-by-value trap:** `void insert(Node* head, int x)` cannot change the caller's `head`; modifications of `head->next` still work, but reassigning `head` is lost.
- **Self-referential size:** a struct containing a pointer to its own type is legal; one containing itself by value is not.
- **Space overhead:** SLL stores n extra pointers, DLL stores 2n; vector overhead is only unused capacity.
- **STL traps:** `forward_list` has no `size()`/`push_back`; `list::size()` is O(1) since C++11; `std::sort(list.begin(), list.end())` does not compile, use `list.sort()`.
- **Best structure for:** frequent insert/delete in the middle with known positions -> linked list; frequent indexed access or sorting -> array/vector; O(1) delete of arbitrary node with a handle -> DLL.
