#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) = -100 <= a <= 100;
    
    logic integer sum_val(integer a, integer b) = a + b;
    logic integer diff_val(integer a, integer b) = a - b;
    logic integer prod_val(integer a, integer b) = a * b;
    
    lemma prod_bounds: 
        \forall integer a, b; 
        is_valid_range(a) && is_valid_range(b) ==> -10000 <= prod_val(a, b) <= 10000;
*/

/*@
    requires is_valid_range(A) && is_valid_range(B);
    ensures \result == sum_val(A, B) || \result == diff_val(A, B) || \result == prod_val(A, B);
    ensures \result >= sum_val(A, B);
    ensures \result >= diff_val(A, B);
    ensures \result >= prod_val(A, B);
    assigns \nothing;
*/
int func(int A, int B) {
    int sum;
    int diff;
    int prod;
    int values[3];
    int max_val;
    int i;
    
    sum = A + B;
    diff = A - B;
    //@ assert is_valid_range(A) && is_valid_range(B);
    //@ assert -10000 <= A * B <= 10000;
    prod = A * B;
    
    values[0] = sum;
    values[1] = diff;
    values[2] = prod;
    
    max_val = values[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \exists integer k; 0 <= k < i && max_val == values[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= values[j];
        loop invariant values[0] == sum_val(A, B);
        loop invariant values[1] == diff_val(A, B);
        loop invariant values[2] == prod_val(A, B);
        loop assigns i, max_val;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (values[i] > max_val) {
            max_val = values[i];
        }
        i = i + 1;
    }
    
    return max_val;
}

int main() {
    return 0;
}
