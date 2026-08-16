/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == 1 <==> (((a) < (c) && (c) < (b)) ||
        ((c) < (a) && (a) < (d)) ||
        ((a) < (d) && (d) < (b)));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int f = 0;
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;
    
    if (a < c && c < b) {
        f = 1;
    } else if (c < a && a < d) {
        f = 1;
    } else if (a < d && d < b) {
        f = 1;
    }
    
    //@ assert f == 1 <==> (((a) < (c) && (c) < (b)) ||         ((c) < (a) && (a) < (d)) ||         ((a) < (d) && (d) < (b)));
    return f;
}
