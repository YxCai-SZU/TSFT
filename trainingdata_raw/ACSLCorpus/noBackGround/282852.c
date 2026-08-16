#include <stdbool.h>

/*@
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 123);
    requires 1 <= k && k <= 123;
    ensures \result == true <==> (\forall integer i; 0 <= i < (5) ==> (x)[i] <= (k));
    assigns \nothing;
*/
bool func(int *x, int k)
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 123);
        loop invariant 1 <= k && k <= 123;
        loop invariant \forall integer j; 0 <= j < i ==> x[j] <= k;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        int a = x[i];
        if (a > k)
        {
            //@ assert !(\forall integer i; 0 <= i < (5) ==> (x)[i] <= (k));
            return false;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (5) ==> (x)[i] <= (k));
    return true;
}
