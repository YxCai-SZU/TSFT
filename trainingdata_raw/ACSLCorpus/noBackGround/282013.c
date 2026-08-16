#include <limits.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures \result >= 0;
    ensures \result == (((A) + (B) + 1) / 2);
    assigns \nothing;
*/
int func(int A, int B)
{
    int sum;
    int avg;
    int count;
    int temp_sum;

    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100);
    sum = A + B;
    avg = 0;
    count = 0;
    temp_sum = sum;

    /*@
        loop invariant 1 <= A && A <= 100;
        loop invariant 1 <= B && B <= 100;
        loop invariant sum == A + B;
        loop invariant 0 <= temp_sum;
        loop invariant temp_sum <= sum;
        loop invariant 0 <= count;
        loop invariant count <= sum / 2;
        loop invariant sum == temp_sum + 2 * count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    if (temp_sum == 1)
    {
        count += 1;
    }

    avg = count;

    //@ assert avg >= 0;
    //@ assert avg == (((A) + (B) + 1) / 2);
    return avg;
}

int main()
{
    return 0;
}
