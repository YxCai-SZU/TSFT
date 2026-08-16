#include <stdbool.h>

/*@ predicate valid_array(int *a) =
      \valid(a + (0..2)) &&
      a[0] >= 1 && a[0] <= 100 &&
      a[1] >= 1 && a[1] <= 100 &&
      a[2] >= 1 && a[2] <= 100;
*/

/*@ predicate min_property(integer min_val, integer a0, integer a1, integer a2) =
      min_val >= 0 &&
      (min_val <= a0 + a1 || min_val <= a1 + a2 || min_val <= a2 + a0);
*/

/*@ lemma array_length_3:
      \forall int *a; valid_array(a) ==> \valid(a + (0..2));
*/

/*@ lemma element_bounds:
      \forall int *a; valid_array(a) ==>
        a[0] >= 1 && a[0] <= 100 &&
        a[1] >= 1 && a[1] <= 100 &&
        a[2] >= 1 && a[2] <= 100;
*/

/*@ lemma sum_nonnegative:
      \forall integer x, y; x >= 1 && y >= 1 ==> x + y >= 0;
*/

/*@ requires valid_array(a);
    ensures \result >= 0;
    ensures min_property(\result, a[0], a[1], a[2]);
*/
int func(int *a)
{
    int min_val;
    int i;
    int j;
    int sum;
    
    min_val = a[0] + a[1];
    i = 0;
    
    /*@ loop invariant 0 <= i <= 3;
        loop invariant valid_array(a);
        loop invariant min_property(min_val, a[0], a[1], a[2]);
        loop assigns i, j, min_val, sum;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        j = i + 1;
        
        /*@ loop invariant 0 <= j <= 3;
            loop invariant valid_array(a);
            loop invariant min_property(min_val, a[0], a[1], a[2]);
            loop assigns j, min_val, sum;
            loop variant 3 - j;
        */
        while (j < 3)
        {
            sum = a[i] + a[j];
            if (sum < min_val)
            {
                min_val = sum;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return min_val;
}

int main()
{
    return 0;
}
