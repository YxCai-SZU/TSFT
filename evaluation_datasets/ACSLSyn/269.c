/* ============================================================
   Scenario: Network Packet Rate Limiter
   A function that tracks packet sequence numbers within a window,
   validates that a new packet's sequence number falls within the
   allowed range, and updates the sequence window length.

   Data Flow:
   1. Given a current window start (win_start), window size (win_size),
      and a new sequence number (seq_num), check if seq_num is in range.
   2. If it is in range, update the sequence window length by pushing
      (simulating adding the packet to the tracking buffer).
   3. The final output is the new sequence window length, which must be
      ≤ 100 (the max allowed window size).
   ============================================================ */

#include <stdbool.h>
#include <stdint.h>

/* ==================== Provided Functions (adapted) ==================== */

/* --- Function 1: Clamp value to a maximum (min(b/a, c)) --- */
/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    logic integer safe_div(integer b, integer a) = b / a;

    lemma div_bounds:
        \forall integer a, b;
        bounds(a, b, 100) ==> safe_div(b, a) <= 100;
*/

unsigned long clamp_div(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long ans;

    //@ assert bounds(a, b, c);
    //@ assert safe_div(b, a) <= 100;

    ans = b / a;
    if (ans > c)
    {
        ans = c;
    }

    //@ assert ans <= safe_div(b, a);
    //@ assert ans <= c;
    //@ assert ans == safe_div(b, a) || ans == c;

    return ans;
}

/* --- Function 2: Check if value x is in range [a, a+b] --- */
/*@
    predicate in_range(integer v) = 0 <= v <= 100;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_in_range:
        \forall integer a, b;
        in_range(a) && in_range(b) ==> 0 <= sum(a, b) <= 200;
*/

bool range_check(unsigned int a, unsigned int b, unsigned int x)
{
    unsigned int c;
    bool result;

    c = a + b;

    //@ assert in_range(a) && in_range(b) && in_range(x);
    //@ assert 0 <= c <= 200;

    if (x < a || x > c)
    {
        //@ assert x < a || x > c;
        result = false;
    }
    else
    {
        //@ assert x >= a && x <= c;
        result = true;
    }

    //@ assert result == (x >= a && x <= a + b);
    return result;
}

/* --- Function 3: Update sequence length (push) --- */
/*@
    predicate is_sequence_length_less_than_max(integer len) = len < 100;

    logic integer sequence_push_length(integer old_len) = old_len + 1;

    lemma sequence_push_preserves_length:
        \forall integer s_len;
        is_sequence_length_less_than_max(s_len) ==> 
        sequence_push_length(s_len) == s_len + 1;
*/

uint32_t sequence_push(uint32_t s_len, int v)
{
    uint32_t old_len = s_len;
    uint32_t new_len;
    
    //@ assert is_sequence_length_less_than_max(old_len);
    
    new_len = old_len + 1;
    
    //@ assert new_len == sequence_push_length(old_len);
    //@ assert new_len <= 100;
    
    return new_len;
}

/* ==================== Synthesized Function ==================== */

uint32_t process_packet(unsigned int win_start, unsigned int win_size, unsigned int seq_num)
{
    uint32_t new_len;

    unsigned long clamped_size = clamp_div(1, win_size, 100);
    //@ assert clamped_size <= 100;

    bool in_window = range_check(win_start, (unsigned int)clamped_size, seq_num);
    //@ assert in_window == (seq_num >= win_start && seq_num <= win_start + clamped_size);

    if (in_window)
    {
        //@ assert is_sequence_length_less_than_max((uint32_t)win_size);
        new_len = sequence_push((uint32_t)win_size, (int)seq_num);
        //@ assert new_len == sequence_push_length((uint32_t)win_size);
        //@ assert new_len == (uint32_t)(win_size + 1);
        //@ assert new_len <= 100;
    }
    else
    {
        new_len = (uint32_t)win_size;
        //@ assert new_len == (uint32_t)win_size;
        //@ assert new_len <= 100;
    }

    //@ assert new_len <= 100;
    //@ assert new_len == sequence_push_length((uint32_t)win_size) || new_len == (uint32_t)win_size;

    return new_len;
}

int main(void)
{
    process_packet(10, 20, 15);
    return 0;
}
