#include <stdint.h>
#include <stdbool.h>

/* ===== First code snippet functions ===== */

/*@
predicate valid_range(integer a) = 1 <= a && a <= 10;

lemma lemma1: \forall integer a, b, c;
    valid_range(a) && valid_range(b) && valid_range(c) ==> a + b + c <= 30;

lemma lemma2: \forall integer a, b, c;
    valid_range(a) && valid_range(b) && valid_range(c) ==> a + b + c >= 3;

lemma lemma3: \forall integer a, b, c;
    valid_range(a) && valid_range(b) && valid_range(c) ==> 
    a + b + c >= 3 && a + b + c <= 30;
*/

void calc_example_5(int x, int y) {
    //@ assert x - y > 0;
}

int non_trivial(int a, int b, int c) {
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 1 <= c && c <= 10;
    return 1;
}

int non_trivial_2(int a, int b, int c) {
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 1 <= c && c <= 10;
    return 1;
}

/* ===== Second code snippet functions ===== */

/*@
    predicate valid_range2(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    logic integer compute_result(integer a, integer b) =
        6 - a - b;

    lemma result_range: \forall integer a, b;
        valid_range2(a, b) ==> 0 <= compute_result(a, b) && compute_result(a, b) <= 6;
*/

int32_t func2(uint32_t a, uint32_t b)
{
    uint32_t answer;
    
    //@ assert valid_range2(a, b);
    //@ assert compute_result(a, b) >= 0;
    //@ assert compute_result(a, b) <= 6;
    
    answer = 6 - a - b;
    
    //@ assert a != b;
    
    if (answer == 0) {
        return -1;
    } else {
        //@ assert answer == compute_result(a, b);
        //@ assert (int32_t)answer == compute_result(a, b);
        return (int32_t)answer;
    }
}

/* ===== Third code snippet functions ===== */

/*@
    predicate is_valid_range(integer n, integer k) =
        1 <= n && n <= 100 && 1 <= k && k <= 100;

    logic integer half_plus_remainder(integer n) =
        n / 2 + n % 2;

    lemma half_remainder_lemma:
        \forall integer n; 1 <= n <= 100 ==> half_plus_remainder(n) >= 0;
*/

bool func3(unsigned long n, unsigned long k)
{
    bool result;

    //@ assert is_valid_range(n, k);
    //@ assert half_plus_remainder(n) >= 0;

    if (n == 1 && k == 1)
    {
        //@ assert k <= half_plus_remainder(n);
        result = true;
        return result;
    }

    if (k <= n / 2 + n % 2)
    {
        //@ assert k <= half_plus_remainder(n);
        result = true;
        return result;
    }
    else
    {
        //@ assert !(k <= half_plus_remainder(n));
        result = false;
        return result;
    }
}

/* ===== Fourth code snippet functions ===== */

/*@
    predicate has_seven(integer n) =
        n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7;
*/

bool func4(unsigned int n)
{
    bool check = false;
    unsigned int temp = n;

    //@ assert 100 <= temp <= 999;

    if (temp / 100 == 7)
    {
        check = true;
    }
    else if ((temp / 10) % 10 == 7)
    {
        check = true;
    }
    else if (temp % 10 == 7)
    {
        check = true;
    }

    //@ assert check == (temp / 100 == 7 || (temp / 10) % 10 == 7 || temp % 10 == 7);
    return check;
}

/* ===== Synthesized complex function ===== */

int lottery_ticket_validation_system(
    int ticket_id, int player_choice, int bonus_number,
    uint32_t a, uint32_t b,
    unsigned long n, unsigned long k,
    unsigned int num)
{
    //@ assert valid_range(ticket_id);
    //@ assert valid_range(player_choice);
    //@ assert valid_range(bonus_number);
    
    int range_check = non_trivial(ticket_id, player_choice, bonus_number);
    //@ assert range_check == 1;
    
    int32_t checksum = func2(a, b);
    //@ assert checksum == compute_result(a, b);
    
    bool qualifies_special = func3(n, k);
    //@ assert qualifies_special == (k <= half_plus_remainder(n));
    
    bool has_lucky_seven = func4(num);
    //@ assert has_lucky_seven == (num / 100 == 7 || (num / 10) % 10 == 7 || num % 10 == 7);
    
    int consistency_check = non_trivial_2(ticket_id, player_choice, bonus_number);
    //@ assert consistency_check == 1;
    
    //@ assert ticket_id > player_choice ==> ticket_id - player_choice > 0;
    if (ticket_id > player_choice) {
        calc_example_5(ticket_id, player_choice);
    }
    
    //@ assert (range_check == 1 && checksum >= 0 && qualifies_special && has_lucky_seven && consistency_check == 1) ==> 1 == 1;
    
    return 1;
}

int main() {
    return 0;
}
