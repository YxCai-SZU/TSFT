#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(test_tup + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (test_tup)[i] <= 20);
    requires (0 <= (threshold) <= 20);
    ensures (0 <= (\result) <= 5);
    ensures \forall integer i; 0 <= i < 5 && test_tup[i] > threshold ==> \result > 0;
    assigns \nothing;
*/
size_t count_expressions(int *test_tup, int threshold)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && test_tup[j] > threshold ==> count > 0;
        loop invariant ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (test_tup)[i] <= 20);
        loop invariant (0 <= (threshold) <= 20);
        loop assigns i, count;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        if (test_tup[i] > threshold)
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}

int main()
{
    return 0;
}
