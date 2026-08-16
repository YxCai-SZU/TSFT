#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (input)[i] <= 100);
    ensures \result <==> ((3) == 3 &&
        (input)[1] < (input)[2] && (input)[2] < (input)[0]);
    assigns \nothing;
*/
bool func(unsigned int *input)
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    size_t i;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> (input)[i] <= 100);
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> input[j] <= 100;
        loop assigns i;
    */
    for (i = 0; i < 3; i++)
    {
        //@ assert input[i] <= 100;
    }

    //@ assert (b < c && c < a) ==> ((3) == 3 &&         (input)[1] < (input)[2] && (input)[2] < (input)[0]);

    if (b < c && c < a)
    {
        //@ assert ((3) == 3 &&         (input)[1] < (input)[2] && (input)[2] < (input)[0]);
        return true;
    }
    else
    {
        //@ assert !((3) == 3 &&         (input)[1] < (input)[2] && (input)[2] < (input)[0]);
        return false;
    }
}
