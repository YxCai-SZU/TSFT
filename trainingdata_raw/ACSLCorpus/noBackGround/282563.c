#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(l + (0 .. len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (l)[i] % 2 == 0);
    ensures \result == true;
    assigns \nothing;
*/
bool all_even(const int *l, size_t len)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> l[j] % 2 == 0;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (l)[i] % 2 == 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert l[i] % 2 == 0;
        i++;
    }
    return true;
}

int main()
{
    return 0;
}
