/* Scenario: Network packet priority classification system
 * Data flow:
 * 1. Extract 4 header fields (a,b,c,d) from packet and check non-zero total
 * 2. Compute parity-based adjustment value from two payload bytes (e,f)
 * 3. Check if adjusted value is divisible by 3 (protocol compatibility)
 * 4. Classify packet priority (1-3) based on three classification parameters (x,y,z)
 * The final output is a priority class that is always 1, 2, or 3.
 */

#include <limits.h>
#include <stdint.h>

/* ===== Function 1: Header field validation ===== */
/*@
    predicate non_zero_total(integer a, integer b, integer c, integer d) =
        a + b + c + d > 0;

    lemma result_non_zero:
        \forall integer a, b, c, d, r;
        (0 <= a <= 5 && 0 <= b <= 5 && 0 <= c <= 5 && 0 <= d <= 5 &&
        non_zero_total(a, b, c, d) && r >= 1) ==> r >= 1;
*/

unsigned int header_func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int result = 0;

    //@ assert a + b + c + d > 0;

    if (a > 0) {
        result += 5;
    } else if (b > 0) {
        result += 4;
    } else if (c > 0) {
        result += 3;
    } else if (d > 0) {
        result += 2;
    }

    //@ assert result >= 1;
    return result;
}

/* ===== Function 2: Parity-based adjustment ===== */
/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 == 1;
*/

int parity_func(int a, int b)
{
    int result = 0;
    int a_is_even = 0;
    int b_is_even = 0;
    int temp_a = a;
    int temp_b = b;

    while (temp_a >= 2)
    {
        temp_a -= 2;
    }
    //@ assert temp_a == 0 || temp_a == 1;
    if (temp_a == 0)
    {
        a_is_even = 1;
    }

    while (temp_b >= 2)
    {
        temp_b -= 2;
    }
    //@ assert temp_b == 0 || temp_b == 1;
    if (temp_b == 0)
    {
        b_is_even = 1;
    }

    if ((a_is_even && b_is_even) || (!a_is_even && !b_is_even))
    {
        result = a + b;
        //@ assert result == a + b;
    }
    else
    {
        result = a + b + 1;
        //@ assert result == a + b + 1;
    }

    //@ assert result >= 0;
    //@ assert result <= 40;
    return result;
}

/* ===== Function 3: Mod-3 compatibility check ===== */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer mod3(integer x) = x % 3;
    
    predicate condition_holds(integer a, integer b) = 
        mod3(a) == 0 || mod3(b) == 0 || mod3(a + b) == 0;
*/

int32_t mod3_func(uint32_t a, uint32_t b) {
    uint32_t aa;
    uint32_t bb;
    uint32_t cc;
    uint32_t c;
    
    aa = a;
    //@ assert 1 <= a <= 100;
    
    while (aa >= 3) {
        aa -= 3;
    }
    
    bb = b;
    //@ assert 1 <= b <= 100;
    
    while (bb >= 3) {
        bb -= 3;
    }
    
    cc = aa + bb;
    c = cc;
    
    while (c >= 3) {
        c -= 3;
    }
    
    if (aa == 0 || bb == 0 || c == 0) {
        return 1;
    } else {
        return 0;
    }
}

/* ===== Function 4: Priority classification ===== */
/*@
    predicate sorted(integer l1, integer l2, integer l3) =
        l1 <= l2 && l2 <= l3;

    predicate is_permutation(integer l1, integer l2, integer l3,
                             integer a, integer b, integer c) =
        (l1 == a || l1 == b || l1 == c) &&
        (l2 == a || l2 == b || l2 == c) &&
        (l3 == a || l3 == b || l3 == c) &&
        ( (l1 == a && l2 == b && l3 == c) ||
          (l1 == a && l2 == c && l3 == b) ||
          (l1 == b && l2 == a && l3 == c) ||
          (l1 == b && l2 == c && l3 == a) ||
          (l1 == c && l2 == a && l3 == b) ||
          (l1 == c && l2 == b && l3 == a) );

    lemma result_range:
        \forall integer a, b, c, l1, l2, l3, result;
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 &&
        is_permutation(l1, l2, l3, a, b, c) &&
        sorted(l1, l2, l3) &&
        ( (l3 == l2 && l1 == l2 && result == 3) ||
          (l3 == l2 && l1 != l2 && result == 2) ||
          (l3 != l2 && result == 1) ) ==>
        result >= 1 && result <= 3;
*/

int priority_func(int a, int b, int c)
{
    int l[3];
    int l1;
    int l2;
    int l3;
    int result;

    l[0] = a;
    l[1] = b;
    l[2] = c;

    if (l[0] <= l[1] && l[1] <= l[2]) {
        l1 = l[0];
        l2 = l[1];
        l3 = l[2];
    } else if (l[0] <= l[2] && l[2] <= l[1]) {
        l1 = l[0];
        l2 = l[2];
        l3 = l[1];
    } else if (l[1] <= l[0] && l[0] <= l[2]) {
        l1 = l[1];
        l2 = l[0];
        l3 = l[2];
    } else if (l[1] <= l[2] && l[2] <= l[0]) {
        l1 = l[1];
        l2 = l[2];
        l3 = l[0];
    } else if (l[2] <= l[0] && l[0] <= l[1]) {
        l1 = l[2];
        l2 = l[0];
        l3 = l[1];
    } else {
        l1 = l[2];
        l2 = l[1];
        l3 = l[0];
    }

    //@ assert sorted(l1, l2, l3);
    //@ assert is_permutation(l1, l2, l3, a, b, c);

    if (l3 == l2) {
        if (l1 == l2) {
            result = 3;
        } else {
            result = 2;
        }
    } else {
        result = 1;
    }

    //@ assert result >= 1 && result <= 3;
    return result;
}

/* ===== Synthesized Function: Network packet priority classification ===== */

int packet_priority_classifier(
    unsigned int h1, unsigned int h2, unsigned int h3, unsigned int h4,
    int p1, int p2,
    uint32_t c1, uint32_t c2,
    int x, int y, int z)
{
    int final_priority;

    unsigned int header_value = header_func(h1, h2, h3, h4);
    //@ assert header_value >= 1;

    int parity_adjustment = parity_func(p1, p2);
    //@ assert parity_adjustment >= 0 && parity_adjustment <= 40;

    int32_t mod3_compatible = mod3_func(c1, c2);

    if (mod3_compatible == 1) {
        final_priority = priority_func(x, y, z);
    } else {
        int adj_x = (x % 10) + (header_value % 3) + 1;
        int adj_y = (y % 10) + (parity_adjustment % 5) + 1;
        int adj_z = (z % 10) + ((header_value + parity_adjustment) % 7) + 1;
        
        if (adj_x < 1) adj_x = 1;
        if (adj_x > 100) adj_x = 100;
        if (adj_y < 1) adj_y = 1;
        if (adj_y > 100) adj_y = 100;
        if (adj_z < 1) adj_z = 1;
        if (adj_z > 100) adj_z = 100;
        
        final_priority = priority_func(adj_x, adj_y, adj_z);
    }

    //@ assert final_priority >= 1 && final_priority <= 3;
    return final_priority;
}
