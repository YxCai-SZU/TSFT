#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ====== Original functions (adapted with type adjustments for integration) ====== */

/* func1: checks if m is in [2n, 4n] and even */
/*@
    predicate is_valid_range_1(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    predicate result_condition(integer n, integer m) =
        n * 2 <= m && m <= n * 4 && m % 2 == 0;
*/
int func1(int n, int m)
{
    int result;
    result = (n * 2 <= m && m <= n * 4 && m % 2 == 0);
    return result;
}

/* func2: checks if x is in a strictly increasing array of 5 elements in [0,123] */
/*@
    predicate array_in_range(int* a, integer len) =
        \forall integer i; 0 <= i < len ==> 0 <= a[i] && a[i] <= 123;

    predicate array_strictly_increasing(int* a, integer len) =
        len == 5 && a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4];

    predicate element_in_array(int* a, integer len, int x) =
        x == a[0] || x == a[1] || x == a[2] || x == a[3] || x == a[4];
*/
bool func2(int* a, int x)
{
    size_t i = 0;
    while (i < 5) {
        if (a[i] == x) {
            return true;
        }
        i++;
    }
    return false;
}

/* func3: checks if x has a special hundreds digit (111,222,...,999) */
/*@
    predicate is_special(integer x) =
        (x / 100 * 100 == 111) ||
        (x / 100 * 100 == 222) ||
        (x / 100 * 100 == 333) ||
        (x / 100 * 100 == 444) ||
        (x / 100 * 100 == 555) ||
        (x / 100 * 100 == 666) ||
        (x / 100 * 100 == 777) ||
        (x / 100 * 100 == 888) ||
        (x / 100 * 100 == 999);
*/
bool func3(unsigned int x)
{
    unsigned int mul_result = (x / 100) * 100;
    bool condition_result = (mul_result == 111) || (mul_result == 222) ||
                            (mul_result == 333) || (mul_result == 444) ||
                            (mul_result == 555) || (mul_result == 666) ||
                            (mul_result == 777) || (mul_result == 888) ||
                            (mul_result == 999);
    return condition_result;
}

/* func4: computes a * (1 + a + a*a) for 1<=a<=10 */
/*@
    predicate valid_range_4(integer a) = 1 <= a && a <= 10;
    logic integer target_result_4(integer a) = a * (1 + a + a * a);
*/
uint32_t func4(uint32_t a)
{
    uint32_t result = a * (1 + a + a * a);
    return result;
}

/* ====== Synthesized function: Student ID validation system ====== */

/* Scenario: A university registration system validates student IDs.
   Each ID consists of:
   - A department code (n, 1..100) and a student number (m, 1..100) that must satisfy: 2n <= m <= 4n and m even.
   - A list of 5 special course codes (array a, strictly increasing, each in [0,123]).
   - A year code (x, 1..100000) where the hundreds digit is special (111,222,...,999).
   - A checksum (a, 1..10) used to compute a validation value.

   The system checks all four conditions and returns true only if all pass.
*/

/*@
    predicate valid_student_id(int n, int m, int* a, int x, unsigned int year, uint32_t checksum) =
        is_valid_range_1(n, m) &&
        result_condition(n, m) &&
        \valid(a + (0 .. 4)) &&
        array_in_range(a, 5) &&
        array_strictly_increasing(a, 5) &&
        0 <= x && x <= 123 &&
        element_in_array(a, 5, x) &&
        1 <= year && year <= 100000 &&
        is_special(year) &&
        valid_range_4(checksum) &&
        target_result_4(checksum) == 30;
*/

bool validate_student_id(int n, int m, int* a, int x, unsigned int year, uint32_t checksum)
{
    bool cond1, cond2, cond3, cond4;

    cond1 = func1(n, m);

    cond2 = func2(a, x);

    cond3 = func3(year);

    cond4 = (func4(checksum) == 30);

    //@ assert cond1 ==> result_condition(n, m);
    //@ assert cond2 ==> element_in_array(a, 5, x);
    //@ assert cond3 ==> is_special(year);
    //@ assert cond4 ==> (target_result_4(checksum) == 30);

    //@ assert (cond1 && cond2 && cond3 && cond4) ==> valid_student_id(n, m, a, x, year, checksum);

    return cond1 && cond2 && cond3 && cond4;
}
