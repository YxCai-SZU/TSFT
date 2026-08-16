#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (A) <= 3 && 1 <= (B) <= 3 && (A) != (B));
    ensures ((\result) == (6 - ((A)) - ((B))) &&
        1 <= (\result) <= 3 &&
        (\result) != (A) &&
        (\result) != (B));
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B)
{
    unsigned int answers[3];
    unsigned int result = 0;
    unsigned int i = 0;

    // Initialize array
    answers[0] = 1;
    answers[1] = 2;
    answers[2] = 3;

    // Set positions to 0 based on A and B
    //@ assert 1 <= A <= 3 && 1 <= B <= 3;
    answers[A - 1] = 0;
    answers[B - 1] = 0;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> (answers[k] == 0 || answers[k] == result);
        loop invariant \forall integer k; 0 <= k < 3 ==> (answers[k] == 0 || answers[k] == 1 || answers[k] == 2 || answers[k] == 3);
        loop invariant result == 0 || (1 <= result <= 3);
        loop invariant answers[0] != 0 || answers[1] != 0 || answers[2] != 0;
        loop assigns i, result;
        loop variant 3 - i;
    */
    while (i < 3)
    {
        if (answers[i] > 0)
        {
            result = answers[i];
            break;
        }
        i = i + 1;
    }

    //@ assert result == 6 - A - B;
    //@ assert 1 <= result <= 3;
    //@ assert result != A;
    //@ assert result != B;

    return result;
}
