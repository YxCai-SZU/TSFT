/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result <= a;
    ensures \result <= b;
    ensures \forall integer d; 1 <= d <= a && 1 <= d <= b ==> (((a) % (d) == 0 && (b) % (d) == 0) ==> d <= \result);
*/
unsigned long func(unsigned long a, unsigned long b) {
    unsigned long result = 0;
    unsigned long i = 1;

    /*@
        loop invariant 1 <= i <= a + 1;
        loop invariant result <= a;
        loop invariant result <= b;
        loop invariant \forall integer d; 1 <= d < i ==> (((a) % (d) == 0 && (b) % (d) == 0) ==> d <= result);
        loop assigns i, result;
        loop variant a + 1 - i;
    */
    while (i <= a && i <= b) {
        //@ assert 1 <= i <= a && 1 <= i <= b;
        if (a % i == 0 && b % i == 0) {
            result = i;
        }
        i += 1;
    }
    //@ assert i > a || i > b;
    return result;
}
