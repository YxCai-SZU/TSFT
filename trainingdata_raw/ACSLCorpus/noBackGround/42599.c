#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n;
    requires \valid(a + (0 .. n-1));
    assigns \nothing;
    ensures \result == true <==> (\forall integer j; 0 <= j < (n) ==>
            ((a)[j] % 2 == 0 ==> ((a)[j] % 3 == 0 || (a)[j] % 5 == 0)));
*/
bool func(size_t n, unsigned long long *a)
{
    bool flag = true;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant flag == true <==> (\forall integer j; 0 <= j < (index) ==>
            ((a)[j] % 2 == 0 ==> ((a)[j] % 3 == 0 || (a)[j] % 5 == 0)));
        loop assigns flag, index;
        loop variant n - index;
    */
    while (index < n)
    {
        unsigned long long v = a[index];
        if (v % 2 == 0)
        {
            if (!(v % 3 == 0 || v % 5 == 0))
            {
                flag = false;
            }
        }
        index++;
    }

    //@ assert flag == true <==> (\forall integer j; 0 <= j < (n) ==>             ((a)[j] % 2 == 0 ==> ((a)[j] % 3 == 0 || (a)[j] % 5 == 0)));
    return flag;
}
