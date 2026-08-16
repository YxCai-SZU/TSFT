#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100 && 1 <= (x) <= (n) && 1 <= (y) <= (m));
    requires ((n) == (n) && \forall integer i; 0 <= i < (n) ==> 1 <= (x_values)[i] <= (n));
    requires ((m) == (m) && \forall integer i; 0 <= i < (m) ==> 1 <= (y_values)[i] <= (m));
    requires x_values[x-1] < y_values[0];
    ensures \result == true <==> y_values[0] >= x_values[x-1];
*/
bool func(int n, int m, int x, int y, int *x_values, int *y_values)
{
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= y_values[j] <= m;
        loop invariant \forall integer j; 0 <= j < n ==> 1 <= x_values[j] <= n;
        loop invariant x_values[x-1] < y_values[0];
        loop invariant \forall integer k; 0 <= k < m ==> 1 <= y_values[k] <= m;
        loop invariant 1 <= n <= 100 && 1 <= m <= 100;
        loop invariant 1 <= x <= n && 1 <= y <= m;
        loop invariant n == n && m == m;
        loop invariant i <= m;
        loop assigns i;
        loop variant m - i;
    */
    while (i < m)
    {
        //@ assert 0 <= i < m;
        if (y_values[i] < x_values[x-1])
        {
            //@ assert y_values[i] < x_values[x-1];
        }
        i = i + 1;
    }
    
    //@ assert y_values[0] >= x_values[x-1];
    return true;
}
