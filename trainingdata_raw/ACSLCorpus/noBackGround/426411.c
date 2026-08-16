/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100) && (1 <= (e) && (e) <= 100);
    ensures \result == 1 <==> a + b + c + d >= e;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e) {
    int sum;
    int i;
    
    sum = a + b + c + d;
    
    //@ assert sum == a + b + c + d;
    //@ assert 1 <= e && e <= 100;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant sum == a + b + c + d;
        loop invariant 1 <= e && e <= 100;
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant 1 <= c && c <= 100;
        loop invariant 1 <= d && d <= 100;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10) {
        i = i + 1;
    }
    
    return sum >= e ? 1 : 0;
}
