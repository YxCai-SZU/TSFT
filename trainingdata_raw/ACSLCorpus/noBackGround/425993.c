/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * (r) * 3142 / 1000);
*/
long func(int r) {
    long pi = 3142;
    long ans = 0;
    long temp = 2 * (long)r * pi;
    long count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 3142;
        loop invariant ans == 0;
        loop invariant temp >= 0;
        loop invariant temp == 2 * (long)r * pi - 1000 * count;
        loop invariant count >= 0;
        loop assigns temp, count;
    */
    while (temp >= 1000) {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
    }
    
    ans = count;
    //@ assert ans == (2 * (r) * 3142 / 1000);
    return ans;
}

int main() {
    return 0;
}
