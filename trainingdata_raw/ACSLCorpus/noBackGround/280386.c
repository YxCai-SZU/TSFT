#include <stddef.h>
#include <stdbool.h>

/*@ requires m <= n;
    requires \valid(list1 + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==>
            (list1[i] < m || list1[i] > n || (list1[i] >= m && list1[i] <= n));
*/
size_t count_target_range(const int* list1, size_t len, int m, int n)
{
    size_t count = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==>
                      (list1[j] < m || list1[j] > n || (list1[j] >= m && list1[j] <= n));
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        int x = list1[i];
        //@ assert ((0 <= (i) < (len)) ==>       ((((list1)[(i)]) < ((m)) || ((list1)[(i)]) > ((n))) || (((m)) <= ((list1)[(i)]) && ((list1)[(i)]) <= ((n)))));
        if (x >= m && x <= n)
        {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
