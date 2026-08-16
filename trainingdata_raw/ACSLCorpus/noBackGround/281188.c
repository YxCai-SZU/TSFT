#include <stdbool.h>
#include <stdint.h>

/*@
    requires size == 3;
    requires \valid_read(arr + (0 .. size-1));
    requires (\forall int i; (0 <= (i) < ((size))) ==> (1 <= ((arr)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= 198;
*/
uint32_t func(uint32_t *arr, int size)
{
    uint32_t max;
    uint32_t min;
    int i;

    max = arr[0];
    min = arr[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant (\forall int i; (0 <= (i) < ((size))) ==> (1 <= ((arr)[i]) <= 100));
        loop invariant (\forall int i; (0 <= (i) < ((i))) ==> (max) >= (arr)[i]);
        loop invariant (\forall int i; (0 <= (i) < ((i))) ==> (min) <= (arr)[i]);
        loop invariant max >= min;
        loop invariant max <= 100;
        loop invariant min >= 1;
        loop invariant max - min <= 99;
        loop assigns max, min, i;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert (0 <= (i) < (size));
        //@ assert (1 <= (arr[i]) <= 100);
        
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
        if (arr[i] < min)
        {
            min = arr[i];
        }
        
        i += 1;
    }
    
    //@ assert max - min <= 99;
    return max - min;
}

int main()
{
    return 0;
}
