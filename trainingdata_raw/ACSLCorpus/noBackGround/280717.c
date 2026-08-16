#include <stdint.h>
#include <stdbool.h>

/*@
    requires n >= 2 && n <= 20;
    requires \valid(a + (0..n-1));
    requires \valid(b + (0..n-1));
    requires \valid(c + (0..n-2));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] && (b)[i] <= 50);
    requires (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (c)[i] && (c)[i] <= 50);
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    ensures \result >= 0;
    ensures \result <= 2000;
*/
int64_t func(int64_t n, int64_t* a, int64_t* b, int64_t* c)
{
    int64_t sum = 0;
    int64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= i * 100;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (b)[i] && (b)[i] <= 50);
        loop invariant (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (c)[i] && (c)[i] <= 50);
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n)
    {
        int64_t num = a[i];
        //@ assert 1 <= num && num <= n;
        sum += b[num - 1];
        
        if (i > 0)
        {
            if (a[i] == a[i - 1] + 1)
            {
                //@ assert 2 <= num && num <= n;
                sum += c[num - 2];
            }
        }
        
        i += 1;
    }
    
    //@ assert sum >= 0;
    //@ assert sum <= 2000;
    return sum;
}
