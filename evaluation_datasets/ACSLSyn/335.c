#include <stdbool.h>

/*@
    predicate less_than_ten(integer m) = m < 10;
    
    logic integer compute_result(integer n, integer m) =
        m < 10 ? n + m : n * 2 + (m - 10);
*/

int func1(int n, int m)
{
    int result;
    int condition;
    
    condition = m < 10;
    
    if (condition) {
        result = n + m;
    } else {
        result = n * 2 + (m - 10);
    }
    
    //@ assert result == compute_result(n, m);
    
    return result;
}

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 13;
    
    logic integer sum(integer a, integer b, integer c) = a + b + c;
    
    lemma sum_range: 
        \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        3 <= sum(a,b,c) && sum(a,b,c) <= 39;
*/

bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    unsigned int total = a + b + c;
    //@ assert total == sum(a,b,c);
    
    bool res = total >= 22;
    return res;
}

/*@
    predicate is_valid_range(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;

    logic integer total_sum(integer a, integer p) = a * 3 + p;

    lemma ret_bounds:
        \forall integer a, p, ret, temp_sum;
        is_valid_range(a, p) && 0 <= temp_sum && temp_sum <= total_sum(a, p) &&
        ret >= 0 && ret <= (total_sum(a, p) - temp_sum) / 2 ==>
        ret >= 0 && ret <= total_sum(a, p);
*/

int func3(int a, int p)
{
    int sum;
    int ret;
    int is_odd;
    int temp_sum;
    int increment;

    sum = a * 3 + p;
    ret = 0;
    is_odd = 0;
    temp_sum = sum;

    //@ assert 0 <= temp_sum && temp_sum <= a * 3 + p;
    //@ assert ret >= 0 && ret <= (a * 3 + p - temp_sum) / 2;

    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        ret += 1;
    }

    if (temp_sum == 1)
    {
        is_odd = 1;
    }

    increment = is_odd ? 1 : 0;

    //@ assert ret + increment >= 0;
    //@ assert ret + increment <= a * 3 + p;
    return ret + increment;
}

/* Scenario: Packet processing system
   The function processes a network packet with header fields n, m, and payload segments a, b, c.
   It computes a transformed header value, checks if the payload sum meets a threshold,
   and distributes the remaining payload size into chunks.
   The final assertion verifies that the output packet size is consistent with the input. */

int complex_packet_processing(int n, int m, unsigned int a, unsigned int b, unsigned int c, int p)
{
    int header_val = func1(n, m);
    //@ assert header_val == compute_result(n, m);
    
    bool payload_check = func2(a, b, c);
    //@ assert payload_check == (sum(a,b,c) >= 22);
    
    int payload_size = (int)(a + b + c);
    int distribution_val;
    
    if (payload_check) {
        distribution_val = func3(a, p);
        //@ assert distribution_val >= 0 && distribution_val <= a * 3 + p;
    } else {
        distribution_val = 0;
    }
    
    int total_size = header_val + payload_size + distribution_val;
    
    //@ assert total_size >= 0 && total_size <= compute_result(n, m) + (a + b + c) + (a * 3 + p);
    
    return total_size;
}
