#include <stdbool.h>
#include <stdint.h>

/*@ predicate in_range_16bit(integer x) = 0 <= x <= 65535; */

bool main_16bit(uint16_t a, uint16_t b) {
    bool res;
    res = ((a & b) == ((a & b) & 0xFFFF));
    return res;
}

/*@
    predicate valid_range(integer x) = 3 <= x <= 20;

    logic integer possible_sum(integer a, integer b) = a + b;
    logic integer possible_double_b(integer b) = b * 2 - 1;
    logic integer possible_double_a(integer a) = a * 2 - 1;

    lemma result_properties:
        \forall integer a, b, res;
        valid_range(a) && valid_range(b) &&
        (res == possible_sum(a, b) || 
         res == possible_double_b(b) || 
         res == possible_double_a(a)) ==>
        res >= 2;
*/

int func(int a, int b) {
    int ans;
    ans = a + b;
    if (b >= a + 1) {
        ans = b * 2 - 1;
    }
    if (a >= b + 1) {
        ans = a * 2 - 1;
    }
    //@ assert ans == possible_sum(a, b) || ans == possible_double_b(b) || ans == possible_double_a(a);
    //@ assert ans >= 2;
    return ans;
}

/*@ predicate is_valid_date(integer m, integer d) =
      m <= 12 && d <= 31 && 2019 - m - d >= 0; */

/*@ predicate same_month_different_day(integer m1, integer d1, integer m2, integer d2) =
      m1 == m2 && d2 > d1; */

/*@ predicate different_month(integer m1, integer m2) =
      m2 > m1; */

/*@ lemma precond_implies_choice:
      \forall integer m1, d1, m2, d2;
        is_valid_date(m1, d1) && is_valid_date(m2, d2) &&
        (same_month_different_day(m1, d1, m2, d2) || different_month(m1, m2)) ==>
        (m1 == m2 && d2 > d1) || (m2 > m1); */

int date_func(unsigned int m1, unsigned int d1, unsigned int m2, unsigned int d2)
{
    int res;
    if (m1 != m2) {
        res = 1;
    } else {
        res = 0;
    }
    //@ assert res == 0 || res == 1;
    return res;
}

int process_packet(uint16_t packet_id, uint16_t checksum, int header_version, int payload_size,
                   unsigned int month, unsigned int day, unsigned int month2, unsigned int day2)
{
    bool checksum_valid;
    int data_size;
    int date_order;
    int result;

    checksum_valid = main_16bit(checksum, packet_id);

    data_size = func(header_version, payload_size);

    date_order = date_func(month, day, month2, day2);

    if (checksum_valid && data_size >= 2 && date_order == 1) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    //@ assert result == 1 ==> (checksum & packet_id) == ((checksum & packet_id) & 0xFFFF);
    return result;
}
