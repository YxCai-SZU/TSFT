#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result >= 1;
    ensures \result <= x;
    ensures ((x) % (\result) == 0);
*/
size_t func(size_t x)
{
    size_t i = 1;
    //@ ghost size_t original_x = x;
    
    /*@
        loop invariant 1 <= i <= x;
        loop invariant x == original_x;
        loop invariant \forall integer j; 1 <= j < i ==> !((x) % (j) == 0);
        loop assigns i;
        loop variant x - i;
    */
    while (i < x)
    {
        //@ assert 1 <= i < x;
        if (x % i == 0)
        {
            //@ assert ((x) % (i) == 0);
            return i;
        }
        //@ assert !((x) % (i) == 0);
        i = i + 1;
    }
    //@ assert i == x;
    //@ assert ((x) % (x) == 0);
    return x;
}

int main()
{
    return 0;
}
