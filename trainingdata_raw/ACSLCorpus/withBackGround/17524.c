#include <stdbool.h>

/*@ predicate exists_min(int *s, integer i, integer min_val) =
      \exists integer j; 0 <= j < i && min_val == s[j];
*/

/*@ predicate forall_min(int *s, integer i, integer min_val) =
      \forall integer k; 0 <= k < i ==> min_val <= s[k];
*/

/*@ lemma min_in_set: 
      \forall int *s, integer i, integer min_val;
        exists_min(s, i, min_val) && forall_min(s, i, min_val) && i == 4 ==>
        (min_val == s[0] || min_val == s[1] || min_val == s[2] || min_val == s[3]);
*/

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int s[4];
    int min_val;
    int i;
    
    s[0] = a + c;
    s[1] = a + d;
    s[2] = b + c;
    s[3] = b + d;
    
    min_val = s[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 4;
        loop invariant exists_min(&s[0], i, min_val);
        loop invariant forall_min(&s[0], i, min_val);
        loop assigns min_val, i;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (s[i] < min_val) {
            min_val = s[i];
        }
        i = i + 1;
    }
    
    //@ assert exists_min(&s[0], 4, min_val);
    //@ assert forall_min(&s[0], 4, min_val);
    return min_val;
}
