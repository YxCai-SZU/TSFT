#include <stdbool.h>

/*@
    requires (\valid((input) + (0..2)) &&
        (input)[0] >= 1 && (input)[0] <= 100 &&
        (input)[1] >= 1 && (input)[1] <= 100 &&
        (input)[2] >= 1 && (input)[2] <= 100);
    ensures \result >= 0 && \result <= 3;
    ensures \result == 3 ==> (input[0] == input[1] && input[1] == input[2]);
    ensures \result == 2 ==> ((input[0] == input[1] || input[1] == input[2] || input[0] == input[2]) &&
                             (input[0] != input[1] || input[1] != input[2] || input[0] != input[2]));
    ensures \result == 0 ==> (input[0] != input[1] && input[1] != input[2] && input[0] != input[2]);
    assigns \nothing;
*/
int count_equal_triplets(int *input)
{
    int a;
    int b;
    int c;
    int count;

    a = input[0];
    b = input[1];
    c = input[2];
    count = 0;

    if (a == b)
    {
        count += 1;
    }
    if (b == c)
    {
        count += 1;
    }
    if (a == c)
    {
        count += 1;
    }

    //@ assert count == (((a) == (b) ? 1 : 0) + ((b) == (c) ? 1 : 0) + ((a) == (c) ? 1 : 0));
    //@ assert count == 3 ==> (a == b && b == c);
    //@ assert count == 2 ==> ((a == b || b == c || a == c) && (a != b || b != c || a != c));
    //@ assert count == 0 ==> (a != b && b != c && a != c);

    return count;
}
