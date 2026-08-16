/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000;

    logic integer sum_ab(integer a, integer b) = a + b;

    lemma sum_ab_positive: \forall integer a, b; valid_params(a, b, 1000) ==> sum_ab(a, b) > 0;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= a + b;
        loop invariant sum == i;
        loop invariant i <= a + b;
        loop invariant sum <= a + b;
        loop invariant valid_params(a, b, c);
        loop assigns i, sum;
        loop variant a + b - i;
    */
    while (i < a + b) {
        sum += 1;
        i += 1;
    }
    
    //@ assert sum == a + b;
    
    return sum >= c;
}

int main() {
    return 0;
}
