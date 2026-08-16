#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (numbers)[i] <= 100);
    ensures \result <= 100;
    ensures \result == numbers[0] || \result == numbers[1] || \result == numbers[2];
    ensures \result == ((3) <= 0 ? 0 :
        ((3) == 1 ? (numbers)[0] :
        ((3) == 2 ? ((numbers)[0] >= (numbers)[1] ? (numbers)[0] : (numbers)[1]) :
        ((numbers)[0] >= (numbers)[1] && (numbers)[0] >= (numbers)[2] ? (numbers)[0] :
        ((numbers)[1] >= (numbers)[0] && (numbers)[1] >= (numbers)[2] ? (numbers)[1] : (numbers)[2])))));
*/
unsigned int func(unsigned int *numbers)
{
    unsigned int max;
    int i;

    max = numbers[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] <= max;
        loop invariant max <= 100;
        loop invariant max == numbers[0] || max == numbers[1] || max == numbers[2];
        loop assigns max, i;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
        i++;
    }
    return max;
}
