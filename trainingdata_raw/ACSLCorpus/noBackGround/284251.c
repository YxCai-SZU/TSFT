#include <stddef.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
     1 <= (b) && (b) <= 100 &&
     1 <= (c) && (c) <= 100);
    ensures \result <= a+b+c;
    ensures \result == a+b || \result == a+c || \result == b+c;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t v[3];
    size_t min_value;
    size_t i;
    
    //@ assert (1 <= (a) && (a) <= 100 &&      1 <= (b) && (b) <= 100 &&      1 <= (c) && (c) <= 100);
    
    v[0] = a + b;
    v[1] = a + c;
    v[2] = b + c;
    
    min_value = v[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= v[k];
        loop invariant \exists integer k; 0 <= k < i && min_value == v[k];
        loop invariant v[0] == a+b && v[1] == a+c && v[2] == b+c;
        loop invariant (1 <= (a) && (a) <= 100 &&
     1 <= (b) && (b) <= 100 &&
     1 <= (c) && (c) <= 100);
        loop assigns min_value, i;
    */
    while (i < 3)
    {
        if (v[i] < min_value) {
            min_value = v[i];
        }
        i++;
    }
    
    //@ assert min_value == v[0] || min_value == v[1] || min_value == v[2];
    //@ assert min_value <= a+b+c;
    return min_value;
}
