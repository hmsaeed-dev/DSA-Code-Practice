# Arrays in C++

## 1. Theory, Types & Memory

- fixed-size collection of elements of the **same type** stored in **contiguous memory**, accessed by index (0-based). Size must be a compile-time constant for built-in arrays (`int a[n]` with runtime `n` is a VLA: not standard C++, only a GCC/Clang extension).
- **Address formula:** `addr(a[i]) = base + i * sizeof(T)`. With lower bound LB: `base + (i - LB) * w`. This is why access is O(1).
- **Indexing identity:** `a[i] == *(a + i) == *(i + a) == i[a]`. Pointer arithmetic scales by `sizeof(T)`; `p + 1` moves to the next element, not the next byte.
- **Types:** 1D array; 2D/multi-dimensional (stored **row-major** in C++); jagged (array of pointers, rows of different lengths); dynamic (`new T[n]`); `std::array<T,N>` (fixed, stack, no decay); `std::vector<T>` (dynamic, resizable, heap).
- **2D address:** row-major `base + (i * cols + j) * w`; column-major `base + (j * rows + i) * w`. C/C++ use row-major, so iterate rows in the outer loop and columns in the inner loop for cache speed.
- **Storage:** local arrays live on the **stack** (a huge local like `int a[10000000]` overflows it: make it global/static or use `vector`); `new[]` and `vector` data live on the **heap**; global/static arrays live in the data segment.
- **Initialization:** local `int a[5];` = garbage; global/static = zero; `int a[5] = {1,2};` -> `{1,2,0,0,0}`; `int a[5] = {};` -> all zero; `int a[] = {1,2,3};` size deduced as 3.
- **Pros:** O(1) random access, cache-friendly (spatial locality), no per-element pointer overhead, simple. **Cons:** fixed size (static arrays), O(n) insert/delete in the middle (shifting), no bounds checking, resizing means reallocation + copy.
- **Applications:** lookup/frequency tables, DP tables, matrices/images, buffers, base of heaps, hash tables, stacks, queues, sorting and searching input.

## 2. Complexity

| Operation                    | Static array       | `std::vector` (dynamic)             | Notes                                |
| ---------------------------- | ------------------ | ------------------------------------- | ------------------------------------ |
| Access / update a[i]         | O(1)               | O(1)                                  | direct address calculation           |
| Search (unsorted)            | O(n)               | O(n)                                  | linear search                        |
| Search (sorted)              | O(log n)           | O(log n)                              | binary search                        |
| Insert at end                | O(1) if space left | O(1) amortized (O(n) on reallocation) | `push_back`                        |
| Insert at beginning / middle | O(n)               | O(n)                                  | shift elements right                 |
| Delete at end                | O(1)               | O(1)                                  | `pop_back`                         |
| Delete at beginning / middle | O(n)               | O(n)                                  | shift elements left                  |
| Traversal                    | O(n)               | O(n)                                  | best cache behavior of any structure |
| Space                        | n * sizeof(T)      | n * sizeof(T) + spare capacity        | no per-node overhead                 |

Counts worth knowing: subarrays (contiguous) = n(n+1)/2, subsequences = 2^n, pairs = n(n-1)/2, permutations = n!. Sorting: `std::sort` O(n log n) (introsort, not stable), `stable_sort` O(n log n), counting sort O(n + k).

## 3. C++ Implementation Essentials

```cpp
int a[5] = {1, 2};                          // {1,2,0,0,0}
int b[] = {1, 2, 3};                        // size deduced = 3
int n = sizeof(b) / sizeof(b[0]);           // 3 (only where b is a true array, not a pointer)

void f(int a[], int n);                     // a decays to int*: sizeof(a) is pointer size
void g(int (&a)[5]);                        // reference to array keeps the size
void h(int a[][3], int rows);               // 2D param: column count is mandatory

int* p = new int[n]();                      // zero-initialized heap array
delete[] p;                                 // new[] pairs with delete[]

int** m = new int*[r];                      // dynamic 2D / jagged
for (int i = 0; i < r; i++) m[i] = new int[c];
for (int i = 0; i < r; i++) delete[] m[i];
delete[] m;

vector<int> v(n, 0); v.push_back(5); v.reserve(100);
vector<vector<int>> grid(r, vector<int>(c, 0));
array<int, 5> s = {1, 2, 3, 4, 5};          // s.size(), s.at(i), copyable, no decay
```

- **Array-to-pointer decay:** when passed to a function an array becomes `T*`, so the size is lost (pass `n` separately) and changes affect the **original**. Arrays are never copied by value and cannot be returned from a function (use `vector`, `std::array`, or a pointer).
- **Arrays are not assignable:** `a = b` is illegal and `a == b` compares addresses, not contents. The array name is a non-modifiable lvalue (`a++` is illegal, `p++` on a pointer is fine). Copy with a loop, `std::copy`, `memcpy` (trivial types), or use `vector`/`std::array`, which support `=` and `==`.
- **`&a` vs `a`:** `a` decays to `int*` (first element); `&a` is `int(*)[5]`, and `&a + 1` jumps past the whole array. Pointer subtraction gives the element count (`ptrdiff_t`).
- **Out-of-bounds access** (including `a[-1]` and `a[n]`) is **undefined behavior**: no exception, may silently corrupt memory. `vector::at(i)` / `array::at(i)` throw `std::out_of_range`; `operator[]` does not check.
- **Memory rules:** `new[]` must be freed with `delete[]` (using `delete` is UB), free each row of a jagged array before the row-pointer array, set pointers to `nullptr` after delete, and prefer `vector` or `unique_ptr<int[]>` to avoid leaks.
- **`vector` internals:** `size()` = elements used, `capacity()` = allocated; growth is geometric (about 2x on GCC, 1.5x on MSVC), which makes `push_back` amortized O(1). Reallocation **invalidates** all iterators/pointers/references; `reserve(n)` avoids it. `shrink_to_fit()` trims capacity. `vector<bool>` is a bit-packed special case (not a real `bool` array).
- **Erase idiom:** `v.erase(remove(v.begin(), v.end(), x), v.end());` removes all `x` in O(n) (C++20: `erase(v, x)`). Erasing inside a range-for loop invalidates iterators.
- **Useful algorithms (`<algorithm>`, `<numeric>`):** `sort`, `reverse`, `rotate`, `fill`, `accumulate`, `max_element`, `min_element`, `count`, `find`, `lower_bound`, `upper_bound`, `binary_search`, `unique` (sorted input), `next_permutation`, `iota`.

## 4. Algorithmic Patterns & Edge Cases

```cpp
// prefix sum: sum(l..r) = pre[r+1] - pre[l]
vector<long long> pre(n + 1, 0);
for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];

// Kadane (max subarray sum)
long long best = a[0], cur = a[0];
for (int i = 1; i < n; i++) { cur = max((long long)a[i], cur + a[i]); best = max(best, cur); }

// binary search on sorted array (index or -1)
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;           // avoids (lo + hi) overflow
    if (a[mid] == x) return mid;
    else if (a[mid] < x) lo = mid + 1; else hi = mid - 1;
}
return -1;

// rotate left by k: three reversals, O(n) time, O(1) space
k %= n; reverse(a, a + k); reverse(a + k, a + n); reverse(a, a + n);

// Dutch national flag: sort 0/1/2 in one pass
int lo = 0, mid = 0, hi = n - 1;
while (mid <= hi) {
    if (a[mid] == 0) swap(a[lo++], a[mid++]);
    else if (a[mid] == 1) mid++;
    else swap(a[mid], a[hi--]);
}

// remove duplicates from sorted array (two pointers), returns new length
int k = 1; for (int i = 1; i < n; i++) if (a[i] != a[k - 1]) a[k++] = a[i];

// Boyer-Moore majority vote (then verify the candidate)
int cand = 0, cnt = 0;
for (int x : a) { if (cnt == 0) cand = x; cnt += (x == cand) ? 1 : -1; }
```

- **Two pointers:** sorted array pair-sum (`l` and `r` move inward), remove duplicates, partitioning, merge two sorted arrays in O(n+m), reverse in place. Typically turns O(n^2) into O(n).
- **Sliding window:** fixed size k (max sum of k elements, running sum add/remove) or variable (longest/shortest subarray with a condition, expand right and shrink left). O(n).
- **Prefix sum / difference array:** prefix sum answers range-sum queries in O(1) after O(n) build; difference array `d[l] += v, d[r+1] -= v` does range updates in O(1), then prefix-sum it to recover values. 2D prefix sums work the same for submatrix sums.
- **Kadane:** maximum subarray sum in O(n); handle all-negative arrays by initializing with `a[0]`, not 0.
- **Hashing:** two-sum on unsorted data in O(n) with `unordered_map` (value -> index); frequency counting with `a[x]++` when values are small (counting array).
- **Missing / duplicate number in 1..n:** sum formula `n(n+1)/2` (use `long long` to avoid overflow) or XOR of all indices and values (`x ^ x = 0`, `x ^ 0 = x`). **Cyclic sort** places each value at index `value-1` in O(n), O(1) space.
- **Second largest / min / max:** one pass with two variables (update on `>` for largest, `>` and `<` for second largest, careful with duplicates).
- **Binary search variants:** first/last occurrence, `lower_bound` (first >= x), `upper_bound` (first > x), search in rotated sorted array, binary search on the answer. Always `mid = lo + (hi - lo) / 2`.
- **Matrix patterns:** transpose (swap `a[i][j]` and `a[j][i]` for `j > i`), rotate 90 degrees clockwise = transpose then reverse each row, spiral traversal with four boundaries, diagonal elements satisfy `i == j` (main) and `i + j == n - 1` (anti), row-major loops for speed.
- **Sorting facts:** insertion/bubble/selection O(n^2); merge sort O(n log n) stable, O(n) extra; quick sort O(n log n) average, O(n^2) worst; heap sort O(n log n) in place; counting sort O(n + k); `sort` needs random-access iterators (not `list`).
- **Mandatory edge cases:** (1) empty array (`n == 0`), (2) single element, (3) all equal elements, (4) all negative values, (5) already sorted or reverse sorted, (6) index `0` and `n-1` boundaries in loops (`i+1` and `i-1` out of range), (7) `k > n` in rotations (use `k %= n`), (8) integer overflow in sums/products (use `long long`), (9) duplicates.

## 5. High-Yield MCQ Facts & Traps

- **Access is O(1)** because of contiguous layout and the address formula; insertion/deletion in the middle is O(n) due to shifting; search in a sorted array is O(log n) but requires random access.
- **`sizeof` trap:** inside a function `sizeof(arr)` gives the **pointer size** (4 or 8), not the array size, because the parameter decayed. `sizeof(arr)/sizeof(arr[0])` works only in the scope where `arr` was declared.
- **Unsigned underflow:** `for (size_t i = n - 1; i >= 0; i--)` loops forever (`size_t` is never negative); `v.size() - 1` on an empty vector wraps to a huge number.
- **No bounds checking:** `a[5]` on `int a[5]` is UB (may "work" and print garbage); `at()` throws `std::out_of_range`.
- **Printing an array name** with `cout << a` prints the address (except `char[]`, which prints as a C-string and needs a `'\0'` terminator or it runs on).
- **Array size rules:** size must be a constant expression; zero-length arrays are not standard; `int a[3] = {1,2,3,4}` is a compile error (too many initializers).
- **Comparison:** `a == b` on arrays compares addresses (false for two different arrays even with equal contents).
- **Pointer arithmetic:** `*(a + 2)` is `a[2]`; `p + 1` advances by `sizeof(*p)` bytes; subtracting two pointers into the same array gives an element count; `a + n` is the valid one-past-the-end pointer (do not dereference it).
- **2D arrays:** `int a[3][4]` is contiguous, 12 ints, row-major; `a[i][j] == *(*(a + i) + j)`; passing to functions requires all dimensions except the first. `int**` is **not** the same type as `int[3][4]`.
- **Dynamic memory:** `new[]` pairs with `delete[]` (mixing = UB); `new int[n]` is uninitialized, `new int[n]()` is zero-initialized; forgetting to free = memory leak; freeing twice = UB.
- **Vector traps:** `capacity() >= size()`; `push_back` may invalidate iterators/references; `v[i]` does not grow the vector; `resize` changes size, `reserve` changes capacity only; `vector<int> v(5)` is five zeros, `vector<int> v{5}` is one element with value 5.
- **Rotation:** reversal algorithm is O(n) time, O(1) space; naive one-by-one rotation by k is O(n * k).
- **Memory vs lists:** arrays have zero per-element pointer overhead and the best cache locality; linked lists win only on frequent middle insert/delete with a known position.
- **Binary search** requires a **sorted** array; `mid = (lo + hi) / 2` can overflow for large indices, so use `lo + (hi - lo) / 2`.
- **Best structure for:** indexed access, fixed-size data, matrices, DP tables, sorting/searching -> array/vector; unknown growth -> `vector`; frequent middle inserts with known node handles -> linked list.
