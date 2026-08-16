#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = -100 <= a <= 100; */

/*@ logic integer sum(integer a, integer b) = a + b; */
/*@ logic integer diff(integer a, integer b) = a - b; */
/*@ logic integer prod(integer a, integer b) = a * b; */

/*@ lemma product_bounds: 
      \forall integer a, b; 
      is_valid_range(a) && is_valid_range(b) ==> -10000 <= prod(a,b) <= 10000; */

/*@ requires is_valid_range(a) && is_valid_range(b);
    ensures \result == sum(a,b) || \result == diff(a,b) || \result == prod(a,b);
    ensures \result >= sum(a,b);
    ensures \result >= diff(a,b);
    ensures \result >= prod(a,b);
    assigns \nothing;
 */
int func(int a, int b) {
    int ar[3];
    int max_val;
    int i;
    
    //@ assert -10000 <= a * b <= 10000;
    ar[0] = a + b;
    ar[1] = a - b;
    ar[2] = a * b;
    
    max_val = ar[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= ar[k];
        loop invariant ar[0] == a + b && ar[1] == a - b && ar[2] == a * b;
        loop invariant -100 <= a <= 100 && -100 <= b <= 100;
        loop invariant \exists integer x, y; 0 <= x < 3 && 0 <= y < 3 && max_val == ar[x] && ar[x] >= ar[y];
        loop assigns max_val, i;
        loop variant 3 - i;
     */
    while (i < 3) {
        if (ar[i] > max_val) {
            max_val = ar[i];
        }
        i = i + 1;
    }
    
    return max_val;
}

int main() {
    return 0;
}
