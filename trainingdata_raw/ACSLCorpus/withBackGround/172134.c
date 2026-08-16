#include <stdbool.h>

/*@
    predicate contains_value(int *s, integer len, integer value) =
        \exists integer i; 0 <= i < len && s[i] == value;

    predicate has_unique_elements(int *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] != s[j];

    predicate is_sorted(int *s, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> s[i] <= s[j];

    lemma unique_implies_contains_first:
        \forall int *s, integer len;
            len > 0 && has_unique_elements(s, len) && is_sorted(s, len) ==>
                contains_value(s, len, s[0]);
*/

/*@
    requires len > 0;
    requires \valid(v + (0 .. len-1));
    ensures \result ==>
        contains_value(v, len, v[0]) &&
        is_sorted(v, len) &&
        has_unique_elements(v, len);
    assigns \nothing;
*/
bool func(int *v, int len)
{
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer k, l; 0 <= k < l <= i ==> v[k] != v[l];
        loop invariant \forall integer m, n; 0 <= m < n <= i ==> v[m] <= v[n];
        loop assigns i;
        loop variant len - 1 - i;
    */
    while (i < len - 1) {
        if (v[i] >= v[i + 1]) {
            return false;
        }
        
        i = i + 1;
    }
    
    //@ assert has_unique_elements(v, len);
    //@ assert is_sorted(v, len);
    //@ assert contains_value(v, len, v[0]);
    
    return true;
}
