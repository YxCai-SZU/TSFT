#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 1 <= n && n <= 1000000; */
/*@ predicate valid_m_range(integer m) = 1 <= m && m <= 10000; */
/*@ predicate valid_element(integer x) = 1 <= x && x <= 10000; */
/*@ predicate valid_array(int *v, integer m) = 
      \forall integer i; 0 <= i < m ==> valid_element(v[i]); */

/*@ lemma sum_bound: 
      \forall integer i, integer s; 
      0 <= i && s >= 0 && s <= i * 10000 ==> 
      \forall integer x; valid_element(x) ==> s + x >= 0 && s + x <= (i+1) * 10000; */

/*@ requires valid_range(n);
    requires valid_m_range(m);
    requires \valid(v + (0 .. m-1));
    requires valid_array(v, m);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
long func(long n, long m, int *v) {
    long s = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant s >= 0;
        loop invariant s <= i * 10000;
        loop invariant valid_array(v, m);
        loop invariant valid_range(n);
        loop invariant valid_m_range(m);
        loop assigns s, i;
    */
    while (i < (size_t)m) {
        //@ assert 0 <= i < m;
        //@ assert valid_element(v[i]);
        s += v[i];
        i++;
    }
    
    long ans;
    if (n - s > 0) {
        ans = n - s;
        //@ assert ans >= 0;
        //@ assert ans <= n;
    } else {
        ans = -1;
        //@ assert ans == -1;
    }
    
    return ans;
}
