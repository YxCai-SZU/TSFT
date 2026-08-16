/*@
    requires 1 <= A <= 10000;
    requires 1 <= B <= 10000;
    ensures \result == 1 <==> (((A) % 2 == 0) || ((B) % 2 == 0));
*/
_Bool func(unsigned int A, unsigned int B) {
    _Bool A_is_even = 0;
    _Bool B_is_even = 0;
    _Bool ans = 0;
    unsigned int a = A;
    unsigned int b = B;

    /*@
        loop invariant 0 <= a;
        loop invariant a <= A;
        loop invariant ((a) % 2) == ((A) % 2);
        loop assigns a;
    */
    while (a > 1) {
        //@ assert a >= 2;
        a -= 2;
    }

    if (a == 0) {
        A_is_even = 1;
    }

    /*@
        loop invariant 0 <= b;
        loop invariant b <= B;
        loop invariant ((b) % 2) == ((B) % 2);
        loop assigns b;
    */
    while (b > 1) {
        //@ assert b >= 2;
        b -= 2;
    }

    if (b == 0) {
        B_is_even = 1;
    }

    ans = A_is_even || B_is_even;
    return ans;
}
