#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (a)[j] && (a)[j] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, size_t x, const int *a)
{
    size_t local_x = x;
    size_t i = 0;
    int count = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant local_x <= 10000;
        loop assigns i, local_x, count;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        if ((size_t)a[i] <= local_x)
        {
            //@ assert a[i] >= 1;
            local_x = local_x - (size_t)a[i];
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert count >= 0;
    return count;
}
