#include <stdbool.h>
#include <stddef.h>

/*@ requires
      ((p_len) >= 2 && (p_len) <= 200000 &&
      \forall integer i; 0 <= i < (p_len) - 1 ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i; 0 <= i < (p_len) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (p_len) ==> (p)[i] != (p)[j]);
    ensures
      \result >= 0;
*/
int func(int n, int *p, int p_len)
{
    int count = 0;
    int index = 1;
    
    /*@ loop invariant
          1 <= index <= p_len - 1;
      loop invariant
          count >= 0;
      loop invariant
          ((p_len) >= 2 && (p_len) <= 200000 &&
      \forall integer i; 0 <= i < (p_len) - 1 ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i; 0 <= i < (p_len) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (p_len) ==> (p)[i] != (p)[j]);
      loop invariant
          count <= index - 1;
      loop assigns
          count, index;
    */
    while (index < p_len - 1)
    {
        //@ assert index < p_len;
        if (p[index - 1] < p[index] && p[index] < p[index + 1])
        {
            count += 1;
        }
        if (p[index - 1] > p[index] && p[index] > p[index + 1])
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}
