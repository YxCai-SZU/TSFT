#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 1000000);
    requires (1 <= (m) && (m) <= 10000);
    requires \valid(numbers + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (m) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 10000));
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
long func(long n, long m, const long *numbers) {
    long v = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= m;
        loop invariant v >= 0;
        loop invariant v <= ((index) * 10000);
        loop invariant \forall integer i; 0 <= i < index ==> v >= numbers[i];
        loop invariant (\forall integer i; 0 <= i < (m) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 10000));
        loop invariant (1 <= (n) && (n) <= 1000000);
        loop invariant (1 <= (m) && (m) <= 10000);
        loop assigns v, index;
        loop variant m - index;
    */
    while (index < (size_t)m) {
        //@ assert 0 <= index < m;
        //@ assert (1 <= (numbers[index]) && (numbers[index]) <= 10000);
        v += numbers[index];
        //@ assert v >= numbers[index];
        index++;
        //@ assert v <= ((index) * 10000);
    }
    
    if (n - v >= 0) {
        //@ assert n - v >= 0;
        //@ assert n - v <= n;
        return n - v;
    } else {
        //@ assert n - v < 0;
        return -1;
    }
}
