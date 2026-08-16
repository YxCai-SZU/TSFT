#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 2 && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    ensures 0 <= \result && \result <= n;
*/
int64_t func(size_t n, int64_t* a)
{
    // Variable declarations at scope top
    size_t index = 0;
    int64_t an = 0;
    
    //@ assert ((n) >= 2 && (n) <= 100000 &&         \valid((a) + (0 .. (n)-1)) &&         \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    //@ assert index == 0 && an == 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= an <= index;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
        loop assigns index, an;
    */
    while (index < n)
    {
        //@ assert 0 <= index < n;
        //@ assert 1 <= a[index] && a[index] <= n;
        
        if (a[index] == an + 1) {
            an = a[index];
        }
        
        index++;
        //@ assert index <= n;
    }
    
    //@ assert index == n;
    //@ assert 0 <= an <= n;
    
    int64_t result = (int64_t)n - an;
    //@ assert 0 <= result && result <= n;
    return result;
}
