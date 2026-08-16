#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10;

    predicate condition_a(integer a, integer b, integer c) =
        a == 5 && (b == 5 || c == 5 || (b == 7 || c == 7));

    predicate condition_b(integer a, integer b, integer c) =
        b == 5 && (a == 5 || c == 5 || (a == 7 || c == 7));

    predicate condition_c(integer a, integer b, integer c) =
        c == 5 && (a == 5 || b == 5 || (a == 7 || b == 7));

    predicate expected_result(integer a, integer b, integer c) =
        condition_a(a, b, c) || condition_b(a, b, c) || condition_c(a, b, c);
 */

bool func_pattern(int a, int b, int c)
{
    int k = 0;
    int s = 0;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    if (a == 5) {
        k += 1;
    }
    if (b == 5) {
        k += 1;
    }
    if (c == 5) {
        k += 1;
    }

    if (a == 7) {
        s += 1;
    }
    if (b == 7) {
        s += 1;
    }
    if (c == 7) {
        s += 1;
    }

    //@ assert 0 <= k <= 3;
    //@ assert 0 <= s <= 3;

    return k > 0 && (k == 1 && s > 0 || k >= 2);
}

/*@ predicate nonnegative(integer x) = x >= 0; */

uint32_t func_perimeter(uint32_t a, uint32_t b)
{
    uint32_t min_val;
    uint32_t result;

    min_val = (a < b) ? a : b;
    result = (a * 2 + b * 2) - (min_val * 2);

    if (a == 0 && b == 0)
    {
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}

enum PowerSource {
    Battery,
    Solar,
    Electric
};

struct PowerSource_Battery {
    unsigned int capacity;
};

struct PowerSource_Solar {
    unsigned int efficiency;
};

struct PowerSource_Electric {
    unsigned int power_rating;
};

union PowerSource_union {
    struct PowerSource_Battery battery;
    struct PowerSource_Solar solar;
    struct PowerSource_Electric electric;
};

struct PowerSource_wrapper {
    enum PowerSource tag;
    union PowerSource_union data;
};

/*@
    predicate is_battery(struct PowerSource_wrapper p) =
        p.tag == Battery;

    predicate is_stronger_than(struct PowerSource_wrapper s, struct PowerSource_wrapper t) =
        (s.tag == Battery && t.tag == Battery) ==> (s.data.battery.capacity > t.data.battery.capacity);

    lemma verify_power_source:
        \forall struct PowerSource_wrapper e;
            is_battery(e) ==> is_battery(e);
*/

bool verify_power_source(struct PowerSource_wrapper *p) {
    //@ assert p->tag == Battery;
    return p->tag == Battery;
}


bool configure_node(int a, int b, int c, uint32_t cap_a, uint32_t cap_b, struct PowerSource_wrapper *p) {
    bool pattern_valid;
    uint32_t redundancy;
    bool power_ok;

    pattern_valid = func_pattern(a, b, c);

    redundancy = func_perimeter(cap_a, cap_b);

    power_ok = verify_power_source(p);

    bool node_configured = pattern_valid && (redundancy > 0) && power_ok;

    //@ assert node_configured ==> (p->tag == Battery && expected_result(a, b, c));

    return node_configured;
}

int main() {
    return 0;
}
