/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 31415 * r / 10000;
*/
long func(long r) {
    long ans;
    long temp;
    long count;
    long div;
    
    ans = 0;
    temp = r * 2 * 31415;
    count = 0;
    div = 10000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= temp <= 2 * 31415 * 100;
        loop invariant temp == r * 2 * 31415 - count * 10000;
        loop invariant count * 10000 <= r * 2 * 31415;
        loop assigns temp, count;
    */
    while (temp >= div) {
        temp -= div;
        count += 1;
    }
    
    ans = count;
    
    //@ assert ans == 2 * 31415 * r / 10000;
    
    return ans;
}

int main() {
    return 0;
}
