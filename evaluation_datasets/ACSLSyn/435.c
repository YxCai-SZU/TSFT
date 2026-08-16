#include <stdbool.h>

/* Scenario: A smart home energy management system that validates
   whether a set of device parameters can satisfy a power constraint.
   Data flow:
   1) Check three power readings form a valid triangle condition (func1)
   2) Check if three digits can form numbers divisible by 4 (func2)
   3) Check if five timestamps are within a maximum interval (func3)
   4) Check if a power consumption value is within expected range (func4)
   The synthesized function verifies if the system can enter energy-saving mode.
*/

/* --- Original function 1: Triangle condition check --- */
/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100;
    logic integer sum_condition(integer a, integer b, integer c) =
        (a + b == c || a + c == b || b + c == a) ? 1 : 0;
*/
bool func1(int a, int b, int c)
{
    bool result;
    
    if (a + b == c || a + c == b || b + c == a) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

/* --- Original function 2: Number divisibility check --- */
/*@
    predicate valid_numbers(int *arr) =
        \valid(arr + (0..2)) &&
        arr[0] >= 1 && arr[0] < arr[1] && arr[1] < arr[2] && arr[2] <= 9;
    logic integer number1(integer a, integer b, integer c) = a * 100 + b * 10 + c;
    logic integer number2(integer a, integer b, integer c) = a * 10 + b + c * 10;
    logic integer number3(integer a, integer b, integer c) = a * 10 + b + c;
*/
bool func2(int *numbers) {
    int number1_val, number2_val, number3_val;

    number1_val = numbers[0] * 100 + numbers[1] * 10 + numbers[2];
    number2_val = numbers[0] * 10 + numbers[1] + numbers[2] * 10;
    number3_val = numbers[0] * 10 + numbers[1] + numbers[2];

    bool result = (number1_val % 4 == 0) || (number2_val % 4 == 0) || (number3_val % 4 == 0);
    return result;
}

/* --- Original function 3: Timestamp interval check --- */
/*@
    predicate is_valid_params(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A && A <= 123 &&
        0 <= B && B <= 123 &&
        0 <= C && C <= 123 &&
        0 <= D && D <= 123 &&
        0 <= E && E <= 123 &&
        0 <= K && K <= 123 &&
        A < B && B < C && C < D && D < E;
    logic integer total_distance(integer A, integer B, integer C, integer D, integer E) =
        (B > A ? B - A : 0) +
        (C > B ? C - B : 0) +
        (D > C ? D - C : 0) +
        (E > D ? E - D : 0);
    lemma distance_correctness:
        \forall integer A, B, C, D, E;
        A < B && B < C && C < D && D < E ==> total_distance(A, B, C, D, E) == E - A;
*/
bool func3(int A, int B, int C, int D, int E, int K)
{    
    return E - A <= K;
}

/* --- Original function 4: Power range check --- */
/*@
    predicate in_range(integer a, integer b, integer x) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= x && x <= 200;
    logic integer sum(integer a, integer b) = a + b;
*/
bool func4(int a, int b, int x)
{    
    return (a <= x && x <= a + b);
}

/* --- Synthesized function: Energy-saving mode eligibility check --- */
/*@
    predicate energy_save_params(integer p1, integer p2, integer p3, int *digits,
                                 integer tA, integer tB, integer tC, integer tD, integer tE, integer K,
                                 integer base, integer limit, integer power) =
        is_valid_range(p1) && is_valid_range(p2) && is_valid_range(p3) &&
        valid_numbers(digits) &&
        is_valid_params(tA, tB, tC, tD, tE, K) &&
        in_range(base, limit, power);
*/
bool energy_save_mode_check(int p1, int p2, int p3, int *digits,
                            int tA, int tB, int tC, int tD, int tE, int K,
                            int base, int limit, int power)
{
    bool condition1, condition2, condition3, condition4;
    bool result;
    
    condition1 = func1(p1, p2, p3);
    
    condition2 = func2(digits);
    
    condition3 = func3(tA, tB, tC, tD, tE, K);
    
    condition4 = func4(base, limit, power);
    
    result = condition1 && condition2 && condition3 && condition4;
    
    return result;
}
