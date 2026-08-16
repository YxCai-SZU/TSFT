#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (k) && (k) <= 500 &&
        1 <= (n) && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n && h[i] >= k ==> \result >= 1;
    ensures \forall integer i; 0 <= i < n && h[i] < k ==> \result >= 0;
*/
size_t func(unsigned int k, size_t n, unsigned int *h)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
        (count) >= 0 &&
        (count) <= (i) &&
        \forall integer j; 0 <= j < (i) ==> 1 <= (h)[j] && (h)[j] <= 500 &&
        \forall integer j; 0 <= j < (i) ==> ((h)[j] >= (k) ==> (count) >= 1) && ((h)[j] < (k) ==> (count) >= 0));
        loop assigns i, count;
    */
    while (i < n)
    {
        //@ assert 0 <= i && i < n;
        if (h[i] >= k)
        {
            //@ assert h[i] >= k;
            count++;
            //@ assert count >= 1;
        }
        else
        {
            //@ assert h[i] < k;
            //@ assert count >= 0;
        }
        i++;
        //@ assert (0 <= (i) && (i) <= (n) &&         (count) >= 0 &&         (count) <= (i) &&         \forall integer j; 0 <= j < (i) ==> 1 <= (h)[j] && (h)[j] <= 500 &&         \forall integer j; 0 <= j < (i) ==> ((h)[j] >= (k) ==> (count) >= 1) && ((h)[j] < (k) ==> (count) >= 0));
    }
    //@ assert i == n;
    //@ assert (0 <= ((n)) && ((n)) <= (n) &&         (count) >= 0 &&         (count) <= ((n)) &&         \forall integer j; 0 <= j < ((n)) ==> 1 <= (h)[j] && (h)[j] <= 500 &&         \forall integer j; 0 <= j < ((n)) ==> ((h)[j] >= (k) ==> (count) >= 1) && ((h)[j] < (k) ==> (count) >= 0));
    return count;
}
