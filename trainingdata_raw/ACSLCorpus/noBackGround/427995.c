#include <stdint.h>
#include <stdbool.h>

/*@
  requires \valid(list+(0..len-1));
  requires 0 <= len <= 0xffffffff;
  assigns \nothing;
  ensures 0 <= \result <= (unsigned)len;
  ensures \forall integer i; 0 <= i < len ==> (list[i] == element) ==> \result >= 1;
  ensures \forall integer i; 0 <= i < len ==> (list[i] != element) ==> \result <= (unsigned)len - 1;
*/
unsigned count_occurrences(int *list, unsigned len, int element)
{
    unsigned count = 0;
    unsigned i = 0;
    /*@
      loop invariant 0 <= i <= len;
      loop invariant ((count) <= (unsigned)(i));
      loop invariant (\forall integer j; 0 <= j < (i) ==> ((list)[j] == (element)) ==> (count) >= 1);
      loop invariant (\forall integer j; 0 <= j < (i) ==> ((list)[j] != (element)) ==> (count) <= (unsigned)(i) - 1);
      loop invariant len <= 0xffffffff;
      loop assigns count, i;
      loop variant len - i;
    */
    while (i < len)
    {
        //@ assert i < len;
        if (list[i] == element)
        {
            //@ assert list[i] == element;
            count++;
        }
        i++;
    }
    //@ assert i == len;
    return count;
}
