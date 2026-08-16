/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
    ensures \result == 0 <==> !((a) < (b) && (b) < (c));
    assigns \nothing;
*/
_Bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int i;
    
    if (a < b && b < c) {
        return 1;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10000;
            loop invariant !((a) < (b) && (b) < (c));
            loop assigns i;
        */
        while (i < 10000) {
            i = i + 1;
        }
        //@ assert a >= b || b >= c;
        return 0;
    }
}
