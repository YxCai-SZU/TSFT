#include <stdbool.h>

/*@
    requires \valid(v+(0..4));
    requires ((5) == 5);
    requires (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123);
    requires (0 <= (k) <= 123);
    
    ensures \result == true <==> 
        \forall integer i, j; 0 <= i < j < 5 ==> ((v)[(j)] - (v)[(i)] <= (k) || (v)[(i)] - (v)[(j)] <= (k));
*/
bool func(int *v, int k)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    int diff = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\forall integer ix, jx; 0 <= ix < jx < (i) ==> (((v))[(jx)] - ((v))[(ix)] <= ((k)) || ((v))[(ix)] - ((v))[(jx)] <= ((k))));
        loop invariant ((5) == 5);
        loop invariant (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123);
        loop invariant (0 <= (k) <= 123);
        loop assigns i, j, a, b, diff;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        a = v[i];
        j = 0;
        
        /*@
            loop invariant 0 <= j <= 5;
            loop invariant (\forall integer ix, jx; 0 <= ix < jx < (i) ==> (((v))[(jx)] - ((v))[(ix)] <= ((k)) || ((v))[(ix)] - ((v))[(jx)] <= ((k))));
            loop invariant (\forall integer jx; 0 <= jx < (j) ==> 
            ((v)[jx] - (a) <= (k) || (a) - (v)[jx] <= (k)));
            loop invariant ((5) == 5);
            loop invariant (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123);
            loop invariant (0 <= (k) <= 123);
            loop assigns j, b, diff;
            loop variant 5 - j;
        */
        while (j < 5)
        {
            b = v[j];
            
            //@ assert 0 <= b && b <= 123;
            //@ assert 0 <= a && a <= 123;
            
            if (a > b) {
                diff = a - b;
            } else {
                diff = b - a;
            }
            
            if (diff > k) {
                // Empty block as in original
            }
            
            j = j + 1;
        }
        
        i = i + 1;
    }
    
    return true;
}
