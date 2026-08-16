/*@
    requires (0 <= (a) && (a) <= 123) && (0 <= (b) && (b) <= 123) && (0 <= (c) && (c) <= 123) && (0 <= (d) && (d) <= 123) && (0 <= (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (((e) - (a)) <= k);
 */
int func(int a, int b, int c, int d, int e, int k)
{
    int dist;
    int result;

    //@ assert (0 <= (a) && (a) <= 123);
    //@ assert (0 <= (b) && (b) <= 123);
    //@ assert (0 <= (c) && (c) <= 123);
    //@ assert (0 <= (d) && (d) <= 123);
    //@ assert (0 <= (e) && (e) <= 123);
    //@ assert (0 <= (k) && (k) <= 123);
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    dist = e - a;
    
    //@ assert dist == ((e) - (a));
    
    if (dist <= k) {
        result = 1;
    } else {
        //@ assert dist > k;
        result = 0;
    }
    
    return result;
}
