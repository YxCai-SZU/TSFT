#include <stdint.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <= b;
    ensures \result == ((((((((a))) < (((b)))) ? (((((a))) < (((c)))) ? (((a))) : (((c)))) : (((((b))) < (((c)))) ? (((b))) : (((c))))) + ((((b))) * (((c))) / 2)) < (b)) ?
            (((b)) * ((c)) / 2) :
            (((b)) * ((c)) / 2) - (((((((a))) < (((b)))) ? (((((a))) < (((c)))) ? (((a))) : (((c)))) : (((((b))) < (((c)))) ? (((b))) : (((c))))) + ((((b))) * (((c))) / 2)) - (b)));
*/
uint64_t find_odd_bars(uint64_t a, uint64_t b, uint64_t c) {
    uint64_t min_val;
    uint64_t odd_bars;
    uint64_t total_bars;
    uint64_t diff;
    uint64_t result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert b * c <= 100 * 100;
    //@ assert b * c >= 1 * 1;

    if (a < b) {
        if (a < c) {
            min_val = a;
        } else {
            min_val = c;
        }
    } else {
        if (b < c) {
            min_val = b;
        } else {
            min_val = c;
        }
    }

    //@ assert min_val == (((a) < (b)) ? (((a) < (c)) ? (a) : (c)) : (((b) < (c)) ? (b) : (c)));

    odd_bars = b * c / 2;
    //@ assert odd_bars == ((b) * (c) / 2);

    total_bars = min_val + odd_bars;
    //@ assert total_bars == (((((a)) < ((b))) ? ((((a)) < ((c))) ? ((a)) : ((c))) : ((((b)) < ((c))) ? ((b)) : ((c)))) + (((b)) * ((c)) / 2));

    if (total_bars < b) {
        result = odd_bars;
    } else {
        diff = total_bars - b;
        result = odd_bars - diff;
    }

    //@ assert result == ((((((((a))) < (((b)))) ? (((((a))) < (((c)))) ? (((a))) : (((c)))) : (((((b))) < (((c)))) ? (((b))) : (((c))))) + ((((b))) * (((c))) / 2)) < (b)) ?             (((b)) * ((c)) / 2) :             (((b)) * ((c)) / 2) - (((((((a))) < (((b)))) ? (((((a))) < (((c)))) ? (((a))) : (((c)))) : (((((b))) < (((c)))) ? (((b))) : (((c))))) + ((((b))) * (((c))) / 2)) - (b)));
    //@ assert result <= b;
    return result;
}
