#include <stddef.h>

/*@
    requires \valid(listval + (0 .. len-1));
    requires ((len) > 0);
    assigns \nothing;
    ensures ((\result) <= (len) &&
        \forall integer j; 0 <= j < (len) ==> ((listval)[j] == (val) ==> (\result) > 0));
*/
size_t count_val(const int *listval, size_t len, int val)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (listval[j] == val ==> count > 0);
        loop invariant len > 0;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        if (listval[i] == val)
        {
            //@ assert count + 1 > 0;
            count++;
        }
        //@ assert \forall integer j; 0 <= j < i + 1 ==> (listval[j] == val ==> count > 0);
        i++;
    }
    //@ assert count <= len;
    //@ assert \forall integer j; 0 <= j < len ==> (listval[j] == val ==> count > 0);
    return count;
}
