#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer division(integer x, integer d) = x / d;
    logic integer modulus(integer x, integer d) = x % d;
    
    lemma division_modulus_identity:
        \forall integer x, d; d != 0 ==> 
            division(x, d) * d + modulus(x, d) == x;
*/

bool func_first(unsigned long long x) {
    unsigned long long n;
    unsigned long long a;
    
    n = x / 2000;
    a = x % 2000;
    
    //@ assert n * 2000 + a == x;
    
    return n >= 1 || a != 0;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer a, integer b) = 0 <= b && b <= a;
    predicate result_condition(integer a, integer b, integer res) = res == (a == b);
*/

int func_second_a(unsigned int a, unsigned int b) {
    //@ assert a_in_range(a);
    //@ assert b_in_range(a, b);
    return a == b;
}

/*@
    predicate a_in_range2(integer a) = -100 <= a && a <= 100;
    predicate b_in_range2(integer b) = -100 <= b && b <= 100;
    predicate result_condition2(integer a, integer b, integer res) = res == (a >= 0 && b < 0);
*/

int func_second_b(int a, int b) {
    //@ assert a_in_range2(a);
    //@ assert b_in_range2(b);
    return a >= 0 && b < 0;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

bool func_third(int s, int w)
{
    bool result;

    //@ assert valid_range(s);
    //@ assert valid_range(w);
    
    result = s > w;
    return result;
}

bool validate_packet(unsigned long long packet_size, 
                     unsigned int src_port, unsigned int dest_port,
                     int flag_a, int flag_b,
                     int payload_size, int window_size)
{
    bool size_ok;
    bool port_match;
    bool flag_termination;
    bool payload_exceeds_window;
    bool result;
    
    size_ok = func_first(packet_size);
    
    port_match = func_second_a(src_port, dest_port);
    flag_termination = func_second_b(flag_a, flag_b);
    
    payload_exceeds_window = func_third(payload_size, window_size);
    
    result = size_ok && port_match && flag_termination && payload_exceeds_window;
    
    //@ assert result == ((packet_size >= 2000 || packet_size % 2000 != 0) && (src_port == dest_port) && (flag_a >= 0 && flag_b < 0) && (payload_size > window_size));
    
    return result;
}
