#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *p, size_t n) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int64_t)n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];

    logic integer max(integer a, integer b) = a > b ? a : b;
    logic integer min(integer a, integer b) = a < b ? a : b;
*/

/*@
    requires valid_array(p, n);
    ensures \result >= 1 && \result <= (int32_t)n;
    assigns \nothing;
*/
int32_t func(size_t n, int64_t *p)
{
    int32_t count = 1;
    int32_t index = 1;
    size_t p_index = 1;

    /*@
        loop invariant 1 <= p_index <= n;
        loop invariant 1 <= count <= (int32_t)p_index;
        loop invariant 1 <= index <= (int32_t)p_index;
        loop invariant valid_array(p, n);
        loop assigns count, index, p_index;
        loop variant n - p_index;
    */
    while (p_index < n)
    {
        //@ assert p_index >= 1 && p_index < n;
        if (p[p_index - 1] < p[p_index])
        {
            index += 1;
        }
        else
        {
            //@ assert count <= (int32_t)p_index && index <= (int32_t)p_index;
            count = count < index ? count : index;
            index = 1;
        }
        p_index += 1;
    }

    //@ assert count <= (int32_t)n && index <= (int32_t)n;
    count = count < index ? count : index;
    return count;
}
