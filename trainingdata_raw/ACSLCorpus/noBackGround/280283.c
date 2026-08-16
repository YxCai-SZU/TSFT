/*@
    requires (1 <= (n) && (n) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= n;
*/
long func(long n) {
    long temp_n;
    long temp_n_3;
    long count;
    
    temp_n = n;
    temp_n_3 = 0;
    count = 0;
    
    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 1000000000000) &&
        0 <= (temp_n) && (temp_n) <= (n) &&
        (temp_n_3) == 0 &&
        0 <= (count) && (count) <= (n) / 3 &&
        (temp_n) == (n) - 3 * (count));
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3) {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        count += 1;
    }
    temp_n_3 = count;
    
    if (temp_n == 0) {
        count = temp_n_3;
    } else if (temp_n == 1) {
        count = temp_n_3 + 1;
    } else if (temp_n == 2) {
        count = temp_n_3 + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
