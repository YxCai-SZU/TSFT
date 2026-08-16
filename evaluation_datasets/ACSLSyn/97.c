#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_uint32(integer x) = 0 <= x <= 4294967295;
    
    logic integer bitwise_or(integer a, integer b) = a | b;
    
    lemma or_identity: \forall integer x; is_uint32(x) ==> bitwise_or(x, 0) == x;
*/

unsigned int func_or(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    //@ assert is_uint32(a);
    //@ assert is_uint32(b);
    
    result = a | b;
    
    //@ assert result == bitwise_or(a, b);
    
    return result;
}

/*@
    predicate valid_array(int *a, integer n) =
        n >= 2 && n <= 100 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;

    logic integer min_value(integer p, integer i) =
        p < i ? p : i;
*/

int func_min(size_t n, int *a) {
    int p = 1000;
    size_t index = 0;
    
    while (index < n) {
        int i = a[index];
        //@ assert i >= 1 && i <= 100;
        p = p < i ? p : i;
        index++;
    }
    int ans = p;
    //@ assert ans >= 0 && ans <= 1000;
    return ans;
}

/*@
    predicate a_in_range(integer a) = -100 <= a && a <= 100;
    predicate b_in_range(integer b) = -100 <= b && b <= 100;
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate a_le_b_plus_one(integer a, integer b) = a <= b + 1;
    
    lemma func_lemma:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) && a_le_b(a, b) ==> 
        a_le_b_plus_one(a, b);
*/

void func_bound(int a, int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert a_le_b(a, b);
    //@ assert -100 <= b + 1 && b + 1 <= 101;
    
    if (a + 1 <= b) {
        //@ assert a + 1 <= b;
    } else {
        //@ assert a <= b + 1;
    }
}

/*@
    // Scenario: Decoding a simple protocol packet
    // The packet consists of: 
    //   - a header containing a 32-bit flags field (or-combined flags)
    //   - a payload array of integers (size between 2 and 100)
    //   - a range constraint pair (a, b) where a <= b and both in [-100, 100]
    // The function validates that the combined flags are non-zero, 
    // the minimum payload value is within [0, 1000], 
    // and the range constraint a <= b is preserved as a <= b+1 after processing.
    
    predicate valid_packet(unsigned int flags, int *payload, size_t n, int a, int b) =
        is_uint32(flags) && flags > 0 &&
        valid_array(payload, n) &&
        a_in_range(a) && b_in_range(b) && a_le_b(a, b);
    
    predicate processed_packet(unsigned int flags, int min_val, int a, int b) =
        is_uint32(flags) && flags > 0 &&
        min_val >= 0 && min_val <= 1000 &&
        a_le_b_plus_one(a, b);
*/
int process_packet(unsigned int flags, size_t n, int *payload, int a, int b)
{
    unsigned int processed_flags = func_or(flags, 0);
    //@ assert processed_flags == bitwise_or(flags, 0);
    //@ assert processed_flags == flags;
    //@ assert processed_flags > 0;
    
    int min_val = func_min(n, payload);
    //@ assert min_val >= 0 && min_val <= 1000;
    
    func_bound(a, b);
    //@ assert a_le_b_plus_one(a, b);
    
    //@ assert processed_flags > 0 && is_uint32(processed_flags);
    //@ assert min_val >= 0 && min_val <= 1000;
    //@ assert a_le_b_plus_one(a, b);
    
    return min_val;
}

int main(void) {
    unsigned int flags = 0x0F;
    int payload[] = {50, 30, 80, 10, 90};
    size_t n = 5;
    int a = -10;
    int b = 20;
    
    int result = process_packet(flags, n, payload, a, b);
    
    return 0;
}
