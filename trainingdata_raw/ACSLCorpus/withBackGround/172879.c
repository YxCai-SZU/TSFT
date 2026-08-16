#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ logic integer sum_of_two(integer a, integer b, integer c, integer d, integer idx) =
    idx == 0 ? a + b :
    idx == 1 ? a + c :
    idx == 2 ? a + d :
    idx == 3 ? b + c :
    idx == 4 ? b + d :
    c + d; */

/*@ lemma sum_in_range: \forall integer a, b, c, d;
      1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000 ==>
      \forall integer i; 0 <= i <= 5 ==> 2 <= sum_of_two(a,b,c,d,i) <= 20000; */

/*@ requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result >= 0;
    ensures \result == a + b || \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d || \result == c + d;
    assigns \nothing;
 */
int func(int a, int b, int c, int d) {
    int v[6];
    int min_val;
    int i;
    
    v[0] = a + b;
    v[1] = a + c;
    v[2] = a + d;
    v[3] = b + c;
    v[4] = b + d;
    v[5] = c + d;
    
    min_val = v[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 6;
        loop invariant \exists integer j; 0 <= j < i && min_val == v[j];
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= v[k];
        loop invariant \forall integer k; 0 <= k < 6 ==> 
            v[k] == a + b || v[k] == a + c || v[k] == a + d ||
            v[k] == b + c || v[k] == b + d || v[k] == c + d;
        loop invariant 1 <= a <= 10000 && 1 <= b <= 10000 && 
                       1 <= c <= 10000 && 1 <= d <= 10000;
        loop invariant v[0] == a + b && v[1] == a + c && v[2] == a + d &&
                       v[3] == b + c && v[4] == b + d && v[5] == c + d;
        loop assigns i, min_val;
        loop variant 6 - i;
     */
    while (i < 6) {
        //@ assert 0 <= i < 6;
        if (v[i] < min_val) {
            min_val = v[i];
        }
        i++;
    }
    
    //@ assert \exists integer j; 0 <= j < 6 && min_val == v[j];
    //@ assert \forall integer k; 0 <= k < 6 ==> min_val <= v[k];
    return min_val;
}

int main() {
    return 0;
}
