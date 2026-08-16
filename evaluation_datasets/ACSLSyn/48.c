#include <stdbool.h>
#include <stddef.h>

/* ============================================================
   Scenario: Video Frame Processing Pipeline
   Description:
   We are processing a sequence of video frames. Each frame has
   a "quality score" (a) and a "motion vector magnitude" (b).
   The first function (func1) checks if the frame is "odd-quality"
   (i.e., double product of a and b is odd) — this indicates a
   special frame that needs additional processing.
   The second function (func2) computes an adjusted timestamp
   offset for the frame based on its x (frame index) and y
   (frame duration, must be even).
   The third function (func3) counts how many "duplicate frames"
   exist in a buffer of frame indices (where consecutive equal
   values indicate a duplicate).
   The synthesized function processes a batch of frames: it takes
   a frame index x, duration y (even), quality params a,b, and
   an array a of frame indices. It computes the adjusted timestamp
   offset, checks if the frame is odd-quality, and counts duplicates
   in the array. The final assert verifies that the returned
   "duplicate count" is within valid bounds and that the odd-quality
   flag is consistent with the input parameters.
============================================================ */

/* ====== Original func1 (odd-quality check) ====== */
/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3;

    logic integer product(integer a, integer b) = a * b;

    logic integer double_product(integer a, integer b) = product(a, b) * 2;

    lemma product_bound: \forall integer a, b; is_valid_range(a, b) ==> product(a, b) <= 9;

    lemma double_product_bound: \forall integer a, b; is_valid_range(a, b) ==> double_product(a, b) <= 18;
*/

bool func1(unsigned long long a, unsigned long long b)
{
    unsigned long long prod;
    unsigned long long double_prod;
    bool result;

    //@ assert is_valid_range(a, b);
    
    //@ assert product(a, b) <= 9;
    prod = a * b;
    
    //@ assert double_product(a, b) <= 18;
    double_prod = prod * 2;
    
    if (double_prod % 2 != 0) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (double_product(a, b) % 2 != 0);
    return result;
}

/* ====== Original func2 (timestamp offset) ====== */

long func2(long x, long y)
{
    long half_y;
    //@ assert y >= 2 && y <= 100;
    //@ assert x >= 1 && x <= 100;
    
    if (y >= 0)
    {
        long count = 0;
        long temp_y = y;
        while (temp_y >= 2)
        {
            temp_y -= 2;
            count += 1;
        }
        half_y = count;
    }
    else
    {
        long count = 0;
        long temp_y = y;
        while (temp_y <= -2)
        {
            temp_y += 2;
            count -= 1;
        }
        half_y = count;
    }
    
    //@ assert half_y == y / 2;
    //@ assert x + half_y >= 1;
    //@ assert x + half_y <= 150;
    
    long result = x + half_y;
    return result;
}

/* ====== Original func3 (duplicate count) ====== */
/*@ predicate valid_array(int *a, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

/*@ lemma cnt_bounds:
      \forall integer n, cnt, b;
      n >= 1 && n <= 200000 && 0 <= cnt && cnt <= b && b <= n ==> 0 <= cnt && cnt <= n;
*/

int func3(int n, int *a) {
    int cnt = 0;
    int b = 0;
    
    while (b < n) {
        //@ assert 0 <= b < n;
        if (b + 1 < n && a[b] == a[b + 1]) {
            cnt += 1;
            b += 2;
        } else {
            b += 1;
        }
        //@ assert 0 <= cnt <= b;
    }
    //@ assert cnt >= 0 && cnt <= n;
    return cnt;
}

/* ============================================================
   Synthesized Function: process_frame_batch
   Combines func1, func2, func3 into a realistic pipeline.
   - x: frame index (1..100)
   - y: frame duration (even, 1..100)
   - a, b: quality parameters (1..3 each)
   - arr: array of frame indices (size n, valid array)
   - n: size of arr (1..200000)
   The function computes:
     1) offset = func2(x, y) -> adjusted timestamp
     2) odd_flag = func1(a, b) -> is this an odd-quality frame?
     3) dup_cnt = func3(n, arr) -> duplicate frames in buffer
   The final assert verifies that:
     - dup_cnt is in [0, n]
     - odd_flag is consistent with double_product(a,b) % 2 != 0
   This is a high-level property about the output state.
============================================================ */

int process_frame_batch(long x, long y, unsigned long long a, unsigned long long b, int n, int *arr) {
    long offset = func2(x, y);
    //@ assert offset == x + (y / 2);  // from func2 ensures
    
    bool odd_flag = func1(a, b);
    //@ assert odd_flag == (double_product(a, b) % 2 != 0);  // from func1 ensures
    
    int dup_cnt = func3(n, arr);
    //@ assert dup_cnt >= 0 && dup_cnt <= n;  // from func3 ensures
    
    //@ assert dup_cnt >= 0 && dup_cnt <= n && (odd_flag == (double_product(a, b) % 2 != 0));
    
    return dup_cnt;
}
