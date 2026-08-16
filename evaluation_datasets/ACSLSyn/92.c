#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates from original functions */
/*@
    predicate valid_input(integer i) = 1 <= i <= 1000000000;
    
    logic integer expected_result(integer i) = ((i - 1) / 2 + 1) / 2;
*/

/*@
    predicate is_valid_palindrome(integer n) =
      n >= 100 &&
      (n == 100 || n == 101 || n == 111 || n == 121 || n == 131 ||
       n == 141 || n == 151 || n == 161 || n == 171 || n == 181 || n == 191);
*/

/*@
    predicate exactly_two_fives(integer a, integer b, integer c) =
        (a == 5 && b == 5 && c == 7) ||
        (a == 5 && b == 7 && c == 5) ||
        (a == 7 && b == 5 && c == 5);
 */

/* Original function 1: computes (input-1)/2+1 then /2 */
uint64_t func1(uint64_t input)
{
    uint64_t x;
    uint64_t half_x;
    uint64_t result;
    
    x = input - 1;
    //@ assert x == input - 1;
    
    half_x = x / 2 + 1;
    //@ assert half_x == (input - 1) / 2 + 1;
    
    result = half_x / 2;
    return result;
}

/* Original function 2: checks if n is a palindrome in a limited set */
bool is_palindrome_c(unsigned int n) {
    bool result;
    //@ assert 0 <= n <= 100;
    
    if (n >= 100) {
        switch (n) {
            case 100: case 101: case 111: case 121: case 131:
            case 141: case 151: case 161: case 171: case 181: case 191:
                //@ assert n >= 100 && is_valid_palindrome(n);
                result = true;
                break;
            default:
                //@ assert n >= 100 && !is_valid_palindrome(n);
                result = false;
                break;
        }
    } else {
        //@ assert n < 100;
        result = false;
    }
    
    return result;
}

/* Original function 3: checks if exactly two values are 5 and one is 7 */
bool func3(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int count5;
    unsigned int count7;
    count5 = 0;
    count7 = 0;

    //@ assert count5 == 0 && count7 == 0;

    if (a == 5) {
        count5 += 1;
    }
    if (a == 7) {
        count7 += 1;
    }
    if (b == 5) {
        count5 += 1;
    }
    if (b == 7) {
        count7 += 1;
    }
    if (c == 5) {
        count5 += 1;
    }
    if (c == 7) {
        count7 += 1;
    }

    //@ assert count5 == 2 && count7 == 1 ==> exactly_two_fives(a, b, c);

    return count5 == 2 && count7 == 1;
}

/* 
 * Scenario: A simple data validation system for a game score processor.
 * The system takes a raw score input (1 to 1e9), computes a compressed score,
 * then checks if the compressed score (mod 100) matches a palindrome condition,
 * and finally verifies that the three components of the raw score (split into 
 * three 10-range values) satisfy the "exactly_two_fives" property.
 * 
 * This simulates a real-world scenario where data is transformed and validated
 * through multiple stages.
 */

bool process_score(uint64_t raw_score) {
    uint64_t compressed;
    unsigned int a, b, c;
    bool palindrome_ok, fives_ok;
    
    compressed = func1(raw_score);
    //@ assert compressed == expected_result(raw_score);
    
    a = (unsigned int)(raw_score % 10);
    b = (unsigned int)((raw_score / 10) % 10);
    c = (unsigned int)((raw_score / 100) % 10);
    
    //@ assert compressed % 100 <= 100;
    palindrome_ok = is_palindrome_c((unsigned int)(compressed % 100));
    
    fives_ok = func3(a, b, c);
    
    //@ assert (palindrome_ok && fives_ok) ==> (is_valid_palindrome((uint64_t)(compressed % 100)) && exactly_two_fives(a, b, c));
    
    return palindrome_ok && fives_ok;
}
