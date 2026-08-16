#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid_read(a + (0 .. n-1));
    requires n > 0 && m > 0;
    requires n <= 100000 && m <= 100000;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < n ==> a[i] <= (uint64_t)m);
*/
bool func(uint64_t *a, uint32_t n, uint32_t m)
{
    bool flag = true;
    uint32_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant flag == true <==> (\forall integer i; 0 <= i < (index) ==> (a)[i] <= (uint64_t)(m));
        loop assigns flag, index;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert 0 <= index < n;
        if (a[index] > (uint64_t)m)
        {
            flag = false;
        }
        index++;
    }
    return flag;
}
