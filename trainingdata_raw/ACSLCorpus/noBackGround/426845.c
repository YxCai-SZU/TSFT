#include <limits.h>

/*@
    requires (1 <= (p) && (p) <= 100 &&
      1 <= (q) && (q) <= 100 &&
      1 <= (r) && (r) <= 100);
    ensures \result <= p+q || \result <= q+r || \result <= p+r;
    ensures \result >= p+q || \result >= q+r || \result >= p+r;
    assigns \nothing;
*/
int func(int p, int q, int r) {
    int min_pq;
    int min_res;
    
    //@ assert (1 <= (p) && (p) <= 100 &&       1 <= (q) && (q) <= 100 &&       1 <= (r) && (r) <= 100);
    
    if (p + q < q + r) {
        min_pq = p + q;
    } else {
        min_pq = q + r;
    }
    
    //@ assert min_pq == p+q || min_pq == q+r;
    
    if (min_pq < p + r) {
        min_res = min_pq;
    } else {
        min_res = p + r;
    }
    
    //@ assert min_res == (((p+q) <= (q+r) && (p+q) <= (p+r)) ? (p+q) : (((q+r) <= (p+r)) ? (q+r) : (p+r)));
    //@ assert min_res <= p+q || min_res <= q+r || min_res <= p+r;
    //@ assert min_res >= p+q || min_res >= q+r || min_res >= p+r;
    
    return min_res;
}
