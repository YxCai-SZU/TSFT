/*@
    requires (1 <= (n) <= 10000);
    ensures \result == n * 2 * 3 || \result == n * 2;
    ensures \result >= 0;
*/
int func(int n)
{
    int pi = 3;
    int circumference = 0;
    int i = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= i <= n;
        loop invariant circumference >= 0;
        loop invariant circumference == i * 2 * 3;
        loop assigns circumference, i;
    */
    while (i < n)
    {
        circumference += 2 * pi;
        i += 1;
    }
    
    //@ assert circumference == n * 2 * 3;
    return circumference;
}

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == n * 3;
    ensures \result >= 0;
*/
int area_circle(int n)
{
    int pi = 3;
    int area = 0;
    int i = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= i <= n;
        loop invariant area >= 0;
        loop invariant area == i * 3;
        loop assigns area, i;
    */
    while (i < n)
    {
        area += pi;
        i += 1;
    }
    
    //@ assert area == n * 3;
    return area;
}

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == n * 3 * 3;
    ensures \result >= 0;
*/
int volume_cylinder(int n)
{
    int pi = 3;
    int volume = 0;
    int i = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= i <= n;
        loop invariant volume >= 0;
        loop invariant volume == i * 3 * 3;
        loop assigns volume, i;
    */
    while (i < n)
    {
        volume += pi * pi;
        i += 1;
    }
    
    //@ assert volume == n * 3 * 3;
    return volume;
}
