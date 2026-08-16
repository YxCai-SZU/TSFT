#include <stdbool.h>

/*@ requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures \result == (C >= A && C <= B);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    //@ assert -100 <= A <= 100;
    //@ assert -100 <= B <= 100;
    //@ assert -100 <= C <= 100;
    //@ assert (C >= A && C <= B) || !(C >= A && C <= B);
    return C >= A && C <= B;
}

/*@ requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures \result == (C >= A && C <= B);
    assigns \nothing;
*/
bool func2(int A, int B, int C)
{
    //@ assert -100 <= A <= 100;
    //@ assert -100 <= B <= 100;
    //@ assert -100 <= C <= 100;
    //@ assert (C >= A && C <= B) || !(C >= A && C <= B);
    return C >= A && C <= B;
}

int main()
{
    return 0;
}
