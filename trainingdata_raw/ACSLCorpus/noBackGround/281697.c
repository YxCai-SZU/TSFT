#include <stddef.h>

/*@ requires 0 <= list1_len;
    ensures \result <= list1_len;
    assigns \nothing;
*/
size_t count_greater_than(const int *list1, size_t list1_len, int threshold)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant i <= list1_len;
        loop invariant count <= i;
        loop assigns i, count;
        loop variant list1_len - i;
    */
    while (i < list1_len)
    {
        if (list1[i] > threshold)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}

/*@ requires (0 <= (h1) && (h1) <= 23 &&
      0 <= (m1) && (m1) <= 59) && (0 <= (h2) && (h2) <= 23 &&
      0 <= (m2) && (m2) <= 59);
    requires 0 <= k && k <= 100000;
    requires (((h1) < (h2)) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result >= -k;
    ensures \result <= (h2 - h1) * 60 + (m2 - m1);
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_minutes = h1 * 60 + m1;
    int end_minutes = h2 * 60 + m2;
    int ans = end_minutes - start_minutes;
    
    //@ assert ans >= -k;
    //@ assert ans <= (h2 - h1) * 60 + (m2 - m1);
    
    return ans - k;
}
