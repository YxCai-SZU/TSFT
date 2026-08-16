#include <stdbool.h>

/*@ requires \valid(a+(0..4));
    requires (\forall integer i; 0 <= i < 5 ==> 0 <= (a)[i] <= 123);
    requires ((a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
    requires 0 <= k <= 123;
    ensures \result == (a[4] - a[0] <= k);
*/
bool func(int* a, int k)
{
    bool ans;
    int i;
    
    //@ assert (\forall integer i; 0 <= i < 5 ==> 0 <= (a)[i] <= 123);
    //@ assert ((a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
    //@ assert 0 <= k <= 123;
    
    ans = (a[4] - a[0] <= k) ? true : false;
    
    //@ assert ans == (a[4] - a[0] <= k);
    
    i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= (a)[i] <= 123);
        loop invariant ((a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
        loop invariant 0 <= k <= 123;
        loop invariant ans == (a[4] - a[0] <= k);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i <= 5;
        //@ assert (\forall integer i; 0 <= i < 5 ==> 0 <= (a)[i] <= 123);
        //@ assert ((a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
        //@ assert 0 <= k <= 123;
        //@ assert ans == (a[4] - a[0] <= k);
        
        i = i + 1;
    }
    
    //@ assert ans == (a[4] - a[0] <= k);
    return ans;
}
