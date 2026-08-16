/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires a >= 0;
    requires b >= 0;
    ensures \result == ((a * 2 + 1) / 2 < b);
*/
int func(long long a, long long b) {
    long long result;
    long long temp_a;
    long long count;
    
    result = 0;
    temp_a = a * 2 + 1;
    count = 0;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant a >= 0;
        loop invariant b >= 0;
        loop invariant result >= 0;
        loop invariant temp_a >= 0;
        loop invariant temp_a == a * 2 + 1 - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= (a * 2 + 1) / 2;
        loop assigns temp_a, count;
    */
    while (temp_a >= 2) {
        //@ assert temp_a >= 2;
        temp_a -= 2;
        count += 1;
    }
    
    result = count;
    //@ assert result == (a * 2 + 1) / 2;
    return result < b;
}
