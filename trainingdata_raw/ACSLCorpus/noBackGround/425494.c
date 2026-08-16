#include <stdbool.h>

/*@
  requires \valid(list1 + (0 .. 2)) && \valid(list2 + (0 .. 2));
  requires (\forall integer i; 0 <= i < (3) ==> 1 <= (list1)[i] && (list1)[i] <= 100) && (\forall integer i; 0 <= i < (3) ==> 1 <= (list2)[i] && (list2)[i] <= 100);
  ensures \result >= 0 && \result <= 3;
  assigns \nothing;
*/
int count_common(int *list1, int *list2)
{
    int count = 0;
    int i = 0;
    /*@
      loop invariant 0 <= i <= 3;
      loop invariant 0 <= i <= 3;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant \forall integer k; 0 <= k < i ==> (list1[k] == list2[k] ==> count >= 1);
      loop invariant (\forall integer i; 0 <= i < (3) ==> 1 <= (list1)[i] && (list1)[i] <= 100);
      loop invariant (\forall integer i; 0 <= i < (3) ==> 1 <= (list2)[i] && (list2)[i] <= 100);
      loop assigns i, count;
      loop variant 3 - i;
    */
    while (i < 3 && i < 3)
    {
        if (list1[i] == list2[i])
        {
            //@ assert list1[i] == list2[i] ==> count >= 0;
            count += 1;
        }
        i += 1;
    }
    //@ assert count >= 0 && count <= 3;
    return count;
}
