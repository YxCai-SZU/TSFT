#include <stdbool.h>
#include <stdlib.h>

/*@
    requires (1 <= (k) <= 100 && 0 <= (x) <= 100);
    requires \valid(result + (0..(2*k-2)));
    assigns result[0..(2*k-2)];
    ensures \forall integer i; 0 <= i < 2*k-1 ==> (-1000000 <= (result[i]) <= 1000000);
    ensures result[0] == ((x) - (k) + 1);
    ensures result[2*k-2] == ((x) + (k) - 1);
    ensures (\forall integer i; 0 <= i < (2*(k)-1) ==> 
            (result)[i] == (x) - (k) + 1 + i);
*/
void func(long k, long x, long *result) {
    long i;
    long start;
    long end;
    long idx = 0;

    //@ assert (1 <= (k) <= 100 && 0 <= (x) <= 100);
    start = x - (k - 1);
    end = x + (k - 1) + 1;
    i = start;

    /*@
        loop invariant start <= i <= end;
        loop invariant 0 <= idx <= 2*k-1;
        loop invariant idx == i - start;
        loop invariant \forall integer j; 0 <= j < idx ==> result[j] == start + j;
        loop invariant \forall integer j; 0 <= j < idx ==> (-1000000 <= (result[j]) <= 1000000);
        loop assigns i, idx, result[0..(2*k-2)];
        loop variant end - i;
    */
    while (i < end) {
        //@ assert start <= i < end;
        result[idx] = i;
        idx = idx + 1;
        i = i + 1;
        //@ assert idx == i - start;
    }

    //@ assert i == end;
    //@ assert idx == 2*k-1;
}
