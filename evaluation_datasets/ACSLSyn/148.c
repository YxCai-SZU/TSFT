#include <stdint.h>
#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 179;

    logic integer compute_result(integer x) = (x - 1) * (x - 1) - (x - 1);

    lemma arithmetic_bounds:
        \forall integer x; valid_range(x) ==>
            (x - 1) >= 0 &&
            (x - 1) <= 178 &&
            (x - 1) * (x - 1) <= 178 * 178 &&
            compute_result(x) <= 178 * 178 - 1;
*/

int32_t func(int32_t x)
{
    int32_t result;
    
    //@ assert x - 1 >= 0;
    //@ assert x - 1 <= 178;
    //@ assert (x - 1) * (x - 1) <= 178 * 178;
    //@ assert (x - 1) * (x - 1) - (x - 1) <= 178 * 178 - 1;
    
    result = (x - 1) * (x - 1) - (x - 1);
    return result;
}

/*@ predicate valid_params(size_t n, int *h) =
      n >= 1 && n <= 100000 &&
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 1000000000;
*/

int func2(size_t n, int *h) {
    int cur = 0;
    int max = 0;
    size_t i = 0;

    while (i < n - 1) {
        //@ assert i < n-1 && i+1 < n;
        if (h[i + 1] <= h[i]) {
            cur = cur + 1;
        } else {
            if (max < cur) {
                max = cur;
            }
            cur = 0;
        }
        i = i + 1;
    }

    if (max < cur) {
        max = cur;
    }

    //@ assert max >= 0 && max <= n-1;
    return max;
}

int analyze_terrain(int32_t x, size_t n, int *h) {
    int32_t terrain_index;
    
    terrain_index = func(x);
    
    int max_descending_run = func2(n, h);
    
    //@ assert max_descending_run >= 0 && max_descending_run <= n-1;
    
    return max_descending_run;
}
