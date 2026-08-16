#include <stdint.h>
#include <stdbool.h>

/*@ requires 1 <= k <= 2000;
    requires 1 <= n <= 2000;
    requires \valid(s + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) - 1 ==> (s)[i] < (s)[i + 1] &&
      \forall integer i; 0 <= i < (n) ==> 0 <= (s)[i] && (s)[i] < (k));
    ensures 0 <= \result <= k;
*/
int64_t func(int64_t k, int64_t n, int64_t *s) {
    int64_t m = 0;
    int64_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= m <= k;
        loop invariant (\forall integer i; 0 <= i < (n) - 1 ==> (s)[i] < (s)[i + 1] &&
      \forall integer i; 0 <= i < (n) ==> 0 <= (s)[i] && (s)[i] < (k));
        loop invariant \forall integer j; 0 <= j < i ==> 
            ((s[(j+1)%n]) - (s[j]) < 0 ? (k) + (s[(j+1)%n]) - (s[j]) : (s[(j+1)%n]) - (s[j])) <= m;
        loop assigns m, i;
    */
    while (i < n) {
        int64_t next_index = (i + 1) % n;
        int64_t diff;
        
        if (s[next_index] - s[i] < 0) {
            diff = k + s[next_index] - s[i];
        } else {
            diff = s[next_index] - s[i];
        }
        
        //@ assert 0 <= diff < k;
        
        if (diff > m) {
            m = diff;
        }
        
        //@ assert m <= k;
        i++;
    }
    
    int64_t result = k - m;
    //@ assert 0 <= result <= k;
    return result;
}
