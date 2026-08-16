#include <stdbool.h>

/*@ predicate valid_input(integer a, integer b, integer c) =
    a >= 1 && a <= 100 &&
    b >= 1 && b <= 100 &&
    c >= 1 && c <= 200;
*/

/*@ logic integer sum(integer a, integer b) = a + b; */

/*@ lemma input_bounds:
    \forall integer a, b, c;
    valid_input(a, b, c) ==>
    a >= 1 && a <= 100 && b >= 1 && b <= 100 && c >= 1 && c <= 200;
*/

bool check_triangle(const int input[3]) {
    int a;
    int b;
    int c;
    
    a = input[0];
    b = input[1];
    c = input[2];
    
    //@ assert valid_input(a, b, c);
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 200;
    
    return a <= c && a + b >= c;
}

/*@ predicate is_valid_range(integer a, integer b, integer c) =
      1 <= a <= 5000 &&
      1 <= b <= 5000 &&
      1 <= c <= 10000;
*/

/*@ logic integer vector_at(integer k, integer a, integer b, integer c) =
      k == 0 ? a :
      k == 1 ? b :
      c;
*/

/*@ lemma vector_property:
      \forall integer a, b, c, k;
      is_valid_range(a, b, c) && 0 <= k < 3 ==>
      vector_at(k, a, b, c) == (k == 0 ? a : (k == 1 ? b : c));
*/

/*@ lemma sum_relation:
      \forall integer a, b, c;
      is_valid_range(a, b, c) ==>
      (a + b >= c) == (vector_at(0, a, b, c) + vector_at(1, a, b, c) >= vector_at(2, a, b, c));
*/

bool check_range(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int acnt = 0;
    unsigned int bcnt = 0;
    unsigned int ccnt = 0;
    unsigned int v[3];
    unsigned int index = 0;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    //@ assert v[0] == a && v[1] == b && v[2] == c;
    
    for (index = 0; index < 3; index++)
    {
        if (index == 0)
        {
            acnt = v[index];
        }
        else if (index == 1)
        {
            bcnt = v[index];
        }
        else if (index == 2)
        {
            ccnt = v[index];
        }
    }
    
    //@ assert acnt == a;
    //@ assert bcnt == b;
    //@ assert ccnt == c;
    
    return acnt + bcnt >= ccnt;
}

/*@ predicate is_valid_index(integer i, integer len) = 0 <= i < len; */
/*@ predicate is_valid_number(integer num) = 1 <= num <= 100; */
/*@ predicate is_valid_n(integer n) = 1 <= n <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x <= 10000; */

/*@ lemma numbers_range: \forall integer i; 
      is_valid_number(i) ==> 1 <= i <= 100; */

long count_steps(long n, long x, const long numbers[]) {
    long current_pos = 0;
    long count = 0;
    unsigned long index = 0;
    
    while (index < (unsigned long)(n - 1) && current_pos <= x) {
        //@ assert is_valid_number(numbers[index]);
        count += 1;
        current_pos += numbers[index];
        index += 1;
    }
    
    return count;
}

/* 
   Scenario: In a streaming protocol, packets arrive in triples (a, b, c) where:
   - a and b are sizes of two header parts
   - c is the total packet size
   The protocol requires that a <= c and a + b >= c (valid packet).
   We also need to ensure that a, b, c are within range for further processing.
   Additionally, we count how many valid packets we can process given a maximum
   total payload size x, using a sequence of numbers representing payload sizes.
   
   Data flow:
   1. First, check if the triple (a, b, c) forms a valid packet using check_triangle.
   2. Then, verify that the values are within a broader range using check_range.
   3. Finally, count how many such valid packets can be processed given a sequence
      of payload sizes, using count_steps.
*/

/*@ predicate valid_packet(integer a, integer b, integer c) =
      a >= 1 && a <= 100 &&
      b >= 1 && b <= 100 &&
      c >= 1 && c <= 200 &&
      a <= c && a + b >= c;
*/

/*@ predicate valid_packet_range(integer a, integer b, integer c) =
      1 <= a <= 5000 &&
      1 <= b <= 5000 &&
      1 <= c <= 10000 &&
      a + b >= c;
*/

/*@ predicate valid_processing(integer n, integer x) =
      1 <= n <= 100 &&
      1 <= x <= 10000;
*/

long process_packets(const int input[3], long n, long x, const long numbers[]) {
    bool triangle_ok;
    bool range_ok;
    long steps;
    
    triangle_ok = check_triangle(input);
    
    if (triangle_ok) {
        //@ assert valid_input(input[0], input[1], input[2]);
        //@ assert input[0] <= input[2] && input[0] + input[1] >= input[2];
        range_ok = check_range(input[0], input[1], input[2]);
    } else {
        range_ok = false;
    }
    
    if (triangle_ok && range_ok) {
        //@ assert valid_packet_range(input[0], input[1], input[2]);
        steps = count_steps(n, x, numbers);
    } else {
        steps = 0;
    }
    
    //@ assert (steps == 0) || (0 <= steps <= n);
    
    return steps;
}
