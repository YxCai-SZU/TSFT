/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n * 800 - 200 * (n / 15);
    assigns \nothing;
*/
long func(long n) {
    long result;
    long count;
    long temp_n;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant result == n * 800;
        loop invariant count >= 0;
        loop invariant count <= n / 15;
        loop invariant temp_n == n - 15 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15) {
        temp_n -= 15;
        count += 1;
    }
    
    //@ assert 0 <= count * 200 <= 200 * (n / 15);
    //@ assert n * 800 >= 200 * (n / 15);
    
    result -= 200 * count;
    return result;
}
