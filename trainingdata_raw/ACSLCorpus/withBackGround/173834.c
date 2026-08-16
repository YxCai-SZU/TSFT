/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer loop_sum(integer i) = (i - 1) * 500;

    lemma loop_sum_bound: \forall integer k, i; 
        1 <= k <= 100 && 1 <= i <= k + 1 ==> 
        loop_sum(i) <= 100 * 500;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (500 * k >= x);
*/
int func(unsigned int k, unsigned int x) {
    unsigned int i;
    unsigned int sum;
    
    i = 1;
    sum = 0;
    
    /*@
        loop invariant 1 <= i <= k + 1;
        loop invariant sum == loop_sum(i);
        loop invariant valid_params(k, x);
        loop assigns i, sum;
        loop variant k + 1 - i;
    */
    while (i <= k) {
        sum += 500;
        i += 1;
    }
    
    //@ assert sum == 500 * k;
    
    return sum >= x;
}

int main() {
    return 0;
}
