#include <stdbool.h>

/*@ requires 1 <= input[0] && input[0] <= 100 &&
              1 <= input[1] && input[1] <= 100 &&
              1 <= input[2] && input[2] <= 100;
    ensures \result == (input[1] + input[2] >= input[0]);
*/
bool check_max_correctness(unsigned long long input[3])
{
    unsigned long long A;
    unsigned long long B;
    unsigned long long C;
    bool result;
    
    A = input[0];
    B = input[1];
    C = input[2];
    
    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100 &&         1 <= (C) && (C) <= 100);
    result = (B + C >= A);
    //@ assert result == (B + C >= A);
    return result;
}

/*@ requires 1 <= A && A <= 100 &&
              1 <= B && B <= 100 &&
              1 <= C && C <= 100;
    ensures \result <= ((B) + (C) + 1 + (C));
*/
unsigned long long func(unsigned long long A, unsigned long long B, unsigned long long C)
{
    unsigned long long ans;
    unsigned long long tmp;
    
    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100 &&         1 <= (C) && (C) <= 100);
    
    if (A + B + 1 < B + C + 1) {
        tmp = A + B + 1;
    } else {
        tmp = B + C + 1;
    }
    //@ assert tmp == (A + B + 1 < B + C + 1 ? A + B + 1 : B + C + 1);
    
    if (tmp > C + 1) {
        ans = tmp - 1;
    } else {
        ans = tmp;
    }
    //@ assert ans == (tmp > C + 1 ? tmp - 1 : tmp);
    
    //@ assert ans <= ((B) + (C) + 1 + (C));
    return ans;
}
