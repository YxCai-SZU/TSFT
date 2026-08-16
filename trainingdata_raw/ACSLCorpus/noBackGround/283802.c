#include <stdbool.h>
/*@
    requires (0 <= (len) < 0x80000000 &&
        \valid((list1) + (0 .. (len)-1)));
    ensures \result == true ==> \exists integer i; 0 <= i < len && list1[i] == value;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> list1[i] != value;
*/
bool contains_value(int *list1, int len, int value)
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> list1[k] != value;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        if (list1[i] == value)
        {
            //@ assert (0 <= (i) < (len) && (list1)[(i)] == (value));
            return true;
        }
        //@ assert list1[i] != value;
        i = i + 1;
        //@ assert (\forall integer k; (0) <= k < (i) ==> (list1)[k] != (value));
    }
    //@ assert \forall integer k; 0 <= k < len ==> list1[k] != value;
    return false;
}
