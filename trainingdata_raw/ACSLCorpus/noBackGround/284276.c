#include <stddef.h>
#include <stdint.h>

/*@
    requires n >= 1 && n <= 100000;
    requires m >= 1 && m <= 100000;
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100000);
    requires ((m) >= 1 && (m) <= 100000 &&
        \valid((w) + (0 .. (m)-1)) &&
        \forall size_t i; 0 <= i < (m) ==> (w)[i] >= 1 && (w)[i] <= 100000);
    assigns \nothing;
    ensures \result >= 0;
*/
int64_t func(size_t n, size_t m, const int64_t *h, const int64_t *w) {
    int64_t min_h = 100000000000;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant min_h >= 0;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100000);
        loop invariant ((m) >= 1 && (m) <= 100000 &&
        \valid((w) + (0 .. (m)-1)) &&
        \forall size_t i; 0 <= i < (m) ==> (w)[i] >= 1 && (w)[i] <= 100000);
        loop assigns i, min_h;
        loop variant m - i;
    */
    while (i < m) {
        int64_t ww = w[i];
        int64_t min_h_ = min_h;
        size_t j = 0;

        /*@
            loop invariant 0 <= j <= n;
            loop invariant min_h_ >= 0;
            loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100000);
            loop invariant ((m) >= 1 && (m) <= 100000 &&
        \valid((w) + (0 .. (m)-1)) &&
        \forall size_t i; 0 <= i < (m) ==> (w)[i] >= 1 && (w)[i] <= 100000);
            loop assigns j, min_h_;
            loop variant n - j;
        */
        while (j < n) {
            int64_t hh = h[j];
            int64_t abs_diff = (hh >= ww) ? (hh - ww) : (ww - hh);
            
            //@ assert abs_diff >= 0;
            
            if (j == 0 || abs_diff < min_h_) {
                min_h_ = abs_diff;
            }
            j++;
        }
        
        if (i == 0 || min_h_ < min_h) {
            min_h = min_h_;
        }
        i++;
    }
    return min_h;
}
