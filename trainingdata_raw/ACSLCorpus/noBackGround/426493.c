/*@
    requires 0 <= a < 1000;
    requires 0 <= b < 1000;
    ensures \result >= 0;
    ensures \result <= a + b + 1;
*/
unsigned long func(unsigned long a, unsigned long b) {
    unsigned long sum;
    unsigned long result;
    unsigned long i;
    unsigned long remainder_a;
    unsigned long remainder_b;
    unsigned long remainder_sum;

    sum = a + b + 1;
    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= sum;
        loop invariant result >= 0;
        loop invariant result <= i;
        loop invariant 0 <= a < 1000;
        loop invariant 0 <= b < 1000;
        loop assigns i, result, remainder_a, remainder_b, remainder_sum;
    */
    while (i < sum) {
        remainder_a = a % 5;
        remainder_b = b % 5;
        remainder_sum = sum % 5;

        //@ assert remainder_a >= 0 && remainder_a < 5;
        if (remainder_a + remainder_b >= remainder_sum) {
            result += 1;
        }
        i += 1;
    }

    //@ assert result >= 0;
    //@ assert result <= sum;
    return result;
}
