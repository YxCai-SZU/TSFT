/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate c_in_range(integer c) = 1 <= c && c <= 100;
    predicate d_in_range(integer d) = 1 <= d && d <= 100;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d);
    ensures c_in_range(c) && d_in_range(d);
*/
void func(int a, int b, int c, int d)
{
    // Variable declarations at the top
    int e;
    int f;

    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    e = 3 * a + b;
    f = 3 * c + d;
}
