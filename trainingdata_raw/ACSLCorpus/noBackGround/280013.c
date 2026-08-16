#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(list + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len && list[i] == element ==> \result >= 1;
    ensures \forall integer i; 0 <= i < len && list[i] != element ==> \result >= 0;
*/
size_t count_occurrences(const int *list, size_t len, int element)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && list[j] == element ==> count >= 1;
        loop invariant \forall integer j; 0 <= j < i && list[j] != element ==> count >= 0;
        loop invariant len > 0;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        if (list[i] == element)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}

int main(void)
{
    return 0;
}
