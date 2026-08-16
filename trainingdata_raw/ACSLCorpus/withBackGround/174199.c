#include <limits.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */
/*@ predicate is_odd(integer x) = (x & 1) != 0; */

/*@
    requires \valid(list1 + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < len ==> 
        ((list1[i] & 1) == 0 ==> \result >= list1[i]) && 
        ((list1[i] & 1) != 0 ==> \result >= list1[i]);
*/
int max_even_odd(int *list1, int len) {
    int max_even = INT_MIN;
    int max_odd = INT_MIN;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> 
            ((list1[k] & 1) == 0 ==> max_even >= list1[k]) && 
            ((list1[k] & 1) != 0 ==> max_odd >= list1[k]);
        loop invariant max_even >= INT_MIN;
        loop invariant max_odd >= INT_MIN;
        loop assigns i, max_even, max_odd;
        loop variant len - i;
    */
    while (i < len) {
        int num = list1[i];
        if ((num & 1) == 0) {
            if (num > max_even) {
                max_even = num;
            }
        } else {
            if (num > max_odd) {
                max_odd = num;
            }
        }
        i++;
    }
    
    //@ assert \forall integer k; 0 <= k < len ==> ((list1[k] & 1) == 0 ==> max_even >= list1[k]) && ((list1[k] & 1) != 0 ==> max_odd >= list1[k]);
    
    if (max_even > max_odd) {
        //@ assert \forall integer k; 0 <= k < len ==> ((list1[k] & 1) == 0 ==> max_even >= list1[k]) && ((list1[k] & 1) != 0 ==> max_even >= list1[k]);
        return max_even;
    } else {
        //@ assert \forall integer k; 0 <= k < len ==> ((list1[k] & 1) == 0 ==> max_odd >= list1[k]) && ((list1[k] & 1) != 0 ==> max_odd >= list1[k]);
        return max_odd;
    }
}
