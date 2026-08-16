/*@
    requires 1 <= n <= 10000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 1000 == 0;
    ensures \result == 0 ==> n % 1000 != 0;
*/
int func(int n) {
    int temp_n;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n <= n;
        loop invariant temp_n >= 0;
        loop invariant temp_n % 1000 == n % 1000;
        loop assigns temp_n;
    */
    while (temp_n >= 1000) {
        //@ assert temp_n >= 1000;
        temp_n -= 1000;
    }
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= -1000;
        loop invariant temp_n < 1000;
        loop invariant temp_n % 1000 == n % 1000;
        loop assigns temp_n;
    */
    while (temp_n < 0) {
        //@ assert temp_n < 0;
        temp_n += 1000;
    }
    
    if (temp_n == 0) {
        //@ assert ((n) % 1000 == 0);
        return 1;
    } else {
        //@ assert ((n) % 1000 != 0);
        return 0;
    }
}
