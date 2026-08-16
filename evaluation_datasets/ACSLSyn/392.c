#include <stdbool.h>

/* 
 * Scenario: A geometry-based access control system for a secure facility.
 * 
 * The system processes a 4-digit access code (a, b, c, d) where:
 * - a is the user clearance level (1-100)
 * - b is the security zone (1-100)
 * - c is the time slot (1-100)
 * - d is the authentication factor (1-100)
 * 
 * The access decision is based on:
 * 1. The classification of the code pattern (func1: determines if all same, two same, or all different)
 * 2. The access range check (func2: checks if clearance a is within allowed range based on b, c, d)
 * 3. The area capacity calculation (func3: computes (a+b)*h/2 where h is even)
 * 4. The authentication parity check (func4: checks if product of squares of a,b is odd)
 * 
 * The final access decision is: grant access if and only if:
 * - The code pattern is classified as type 2 (exactly two equal values) AND
 * - The access range check passes AND
 * - The area capacity is at least 50 AND
 * - The authentication parity check is true (odd product)
 */

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? 1 :
        ((a == b && a != c) || (a != b && a == c) || (a != b && b == c)) ? 2 : 3;

    lemma result_range: \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        1 <= func_result(a, b, c) <= 3;
*/

int func1(long long a, long long b, long long c)
{
    long long x;
    long long y;
    long long z;
    long long temp;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    x = a;
    y = b;
    z = c;

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    if (x == y && y == z)
    {
        //@ assert x == y && y == z;
        return 1;
    }
    else if (x == y || y == z)
    {
        //@ assert x == y || y == z;
        return 2;
    }
    else
    {
        //@ assert x != y && y != z && x != z;
        return 3;
    }
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer safe_sub(integer b, integer c) = b >= c ? b - c : 0;
    
    lemma sub_nonnegative:
        \forall integer b, c; 1 <= b <= 100 && 1 <= c <= 100 && b >= c ==> b - c >= 0;
    
    lemma sub_upper_bound:
        \forall integer b, c, d; 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100 && b >= c ==> 
            b - c + d <= b + d;
    
    lemma d_nonnegative:
        \forall integer d; 1 <= d <= 100 ==> d >= 0;
*/

bool func2(int a, int b, int c, int d)
{
    bool result;
    
    if (b >= c)
    {
        //@ assert b >= c && b - c + d >= 0;
        //@ assert b >= c && b - c + d <= b + d;
        result = (a <= b - c + d);
    }
    else
    {
        //@ assert b < c && d >= 0;
        result = (a <= d);
    }
    
    return result;
}

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer target_result(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma sum_bound: \forall integer a, b, h;
        valid_input(a, b, h) ==> 1 <= (a + b) * h <= 200 * 100;
*/

int func3(int a, int b, int h)
{
    int sum;
    int result;
    int temp_sum;
    int count;

    //@ assert valid_input(a, b, h);
    
    sum = (a + b) * h;
    
    //@ assert 1 <= sum <= 200 * 100;
    
    result = 0;
    temp_sum = sum;
    count = 0;

    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum + 2 * count == sum;
    }

    result = count;
    //@ assert result == target_result(a, b, h);
    return result;
}

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    predicate result_condition(integer a, integer b, bool r) = 
        r == ((a * b) % 2 != 0);
*/

/*@
    logic integer square(integer x) = 
        (x == 1) ? 1 : 
        (x == 2) ? 4 : 
        9;
*/

/*@
    lemma square_bounds:
        \forall integer x; 1 <= x <= 3 ==> 1 <= square(x) <= 9;
*/

/*@
    lemma product_bounds:
        \forall integer x, y; 
        1 <= x <= 9 && 1 <= y <= 9 ==> 1 <= x * y <= 81;
*/

bool func4(unsigned long long a, unsigned long long b) {
    unsigned long long a_square;
    unsigned long long b_square;
    unsigned long long product;
    bool is_odd;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    
    if (a == 1) {
        a_square = 1;
    } else if (a == 2) {
        a_square = 4;
    } else {
        a_square = 9;
    }
    
    //@ assert a_square == square(a);
    //@ assert 1 <= a_square <= 9;
    
    if (b == 1) {
        b_square = 1;
    } else if (b == 2) {
        b_square = 4;
    } else {
        b_square = 9;
    }
    
    //@ assert b_square == square(b);
    //@ assert 1 <= b_square <= 9;
    
    product = a_square * b_square;
    
    //@ assert 1 <= product <= 81;
    
    is_odd = (product % 2) != 0;
    
    //@ assert is_odd == ((a * b) % 2 != 0);
    
    return is_odd;
}

bool access_control_system(
    long long a1, long long b1, long long c1,
    int a2, int b2, int c2, int d2,
    int a3, int b3, int h3,
    unsigned long long a4, unsigned long long b4)
{
    int classification;
    bool range_check;
    int capacity;
    bool parity_check;
    bool access_granted;
    
    classification = func1(a1, b1, c1);
    //@ assert classification >= 1 && classification <= 3;
    
    range_check = func2(a2, b2, c2, d2);
    //@ assert range_check == ((b2 >= c2 && a2 <= b2 - c2 + d2) || (b2 < c2 && a2 <= d2));
    
    capacity = func3(a3, b3, h3);
    //@ assert capacity == target_result(a3, b3, h3);
    
    parity_check = func4(a4, b4);
    //@ assert parity_check == ((a4 * b4) % 2 != 0);
    
    access_granted = (classification == 2) && range_check && (capacity >= 50) && parity_check;
    
    //@ assert access_granted == (func_result(a1, b1, c1) == 2 && ((b2 >= c2 && a2 <= b2 - c2 + d2) || (b2 < c2 && a2 <= d2)) && target_result(a3, b3, h3) >= 50 && ((a4 * b4) % 2 != 0));
    
    return access_granted;
}
