#include <stdbool.h>

/*@
    requires (1 <= (A) <= 20);
    requires (1 <= (B) <= 20);
    ensures ((\result) == (((A)) * 3) || (\result) == (((B)) * 3) ||
        (\result) == (((((A))) * 3) - 1) || (\result) == (((((B))) * 3) - 1));
    ensures \result > 0;
*/
int func(int A, int B)
{
    int max_value;
    int result;

    //@ assert A <= 20 && B <= 20;
    if (A > B) {
        max_value = A;
    } else {
        max_value = B;
    }

    //@ assert max_value <= 20;
    //@ assert max_value * 3 <= 60;
    result = max_value * 3;

    if (result > 20) {
        //@ assert result == ((max_value) * 3);
        //@ assert result - 1 == ((((max_value)) * 3) - 1);
        return result - 1;
    } else {
        //@ assert result == ((max_value) * 3);
        return result;
    }
}
