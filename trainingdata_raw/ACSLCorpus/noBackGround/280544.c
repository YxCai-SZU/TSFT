#include <stdbool.h>

/*@
    requires len >= 0;
    requires len < 0x80000000;
    requires \valid(list + (0 .. len-1));
    ensures \result == true ==> \exists integer i; 0 <= i < len && list[i] == value;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> list[i] != value;
    assigns \nothing;
*/
bool contains_value(int *list, int len, int value)
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (list)[k] != (value));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list[i] == value)
        {
            //@ assert (0 <= (i) < (len) && (list)[(i)] == (value));
            return true;
        }
        i = i + 1;
    }
    return false;
}
