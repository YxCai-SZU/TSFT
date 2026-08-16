#include <stdbool.h>
#include <stddef.h>

/* ========== Function 1 (Swimming stroke validation) ========== */
typedef enum {
    Butterfly,
    Backstroke,
    Breaststroke,
    Freestyle
} StrokeTag;

typedef struct {
    StrokeTag tag;
    unsigned int time;
    bool DQ;
} Swimming;

/*@
    predicate is_butterfly{L}(Swimming e) = e.tag == Butterfly;
    predicate is_backstroke{L}(Swimming e) = e.tag == Backstroke;
    predicate is_breaststroke{L}(Swimming e) = e.tag == Breaststroke;
    predicate is_freestyle{L}(Swimming e) = e.tag == Freestyle;

    predicate legal_fly{L}(Swimming e) =
        !is_butterfly(e) ? false :
        e.DQ ? false :
        true;

    predicate fly_check{L}(Swimming e) =
        !is_butterfly(e) ? false :
        e.DQ ? false :
        true;

    lemma fly_check_equals_legal_fly:
        \forall Swimming e; fly_check(e) <==> legal_fly(e);
*/

bool fly(Swimming e) {
    bool result;
    //@ assert is_butterfly(e);
    
    if (e.tag == Butterfly) {
        if (e.DQ) {
            //@ assert !legal_fly(e);
            result = false;
        } else {
            //@ assert legal_fly(e);
            result = true;
        }
    } else {
        result = false;
    }
    
    return result;
}

/* ========== Function 2 (Vector condition check) ========== */

/*@
    predicate valid_vec(int *v, integer len) =
        len >= 3 &&
        1 <= v[0] <= 13 &&
        1 <= v[1] <= 13 &&
        1 <= v[2] <= 13;

    predicate matches_condition(int *v) =
        v[2] == v[0] + v[1] ||
        v[2] == v[1] - v[0] ||
        v[2] == v[0] * v[1];
*/

bool func_vec(int *v) {
    int sum;
    int diff;
    int prod;

    sum = v[0] + v[1];
    if (v[2] == sum) {
        return true;
    }
    
    diff = v[1] - v[0];
    //@ assert diff >= -12 && diff <= 12;
    if (v[2] == diff) {
        return true;
    }
    
    prod = v[0] * v[1];
    //@ assert prod >= 1 && prod <= 169;
    if (v[2] == prod) {
        return true;
    }
    
    return false;
}

/* ========== Function 3 (Pair validation) ========== */

/*@
  predicate valid_pair(integer x, integer y) =
    x == y || (x == -1 && y >= 0) || (x >= 0 && y == -1);

  predicate all_pairs_valid(int *x, int *y, integer len) =
    \forall integer i; 0 <= i < len ==> valid_pair(x[i], y[i]);

  lemma len_equal_maintains:
    \forall int *x, *y, integer len;
      len < 0x80000000 && all_pairs_valid(x, y, len) ==>
        all_pairs_valid(x, y, len);
*/

bool func_pairs(int *x, int *y, size_t len) {
    size_t i = 0;
    while (i < len) {
        //@ assert 0 <= i < len;
        if (x[i] != y[i] && x[i] != -1 && y[i] != -1) {
            //@ assert !valid_pair(x[i], y[i]);
            return false;
        }
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert \forall integer j; 0 <= j < len ==> valid_pair(x[j], y[j]);
    return true;
}

/* ========== Synthesized function: Swimming Competition Data Processor ========== */

/*@
    predicate valid_competition_data(StrokeTag tag, int *v, int *x, int *y, size_t len) =
        (tag == Butterfly ==> (valid_vec(v, 3) && matches_condition(v))) &&
        (tag == Butterfly ==> all_pairs_valid(x, y, len));
*/

bool process_competition_data(Swimming swimmer, int *v, int *x, int *y, size_t len) {
    bool fly_result = fly(swimmer);
    //@ assert fly_result == true <==> legal_fly(swimmer);
    
    bool vec_result = func_vec(v);
    //@ assert vec_result == true <==> matches_condition(v);
    
    bool pair_result = func_pairs(x, y, len);
    //@ assert pair_result == true <==> all_pairs_valid(x, y, len);
    
    //@ assert (fly_result && vec_result && pair_result) <==> (legal_fly(swimmer) && matches_condition(v) && all_pairs_valid(x, y, len));
    
    return fly_result && vec_result && pair_result;
}

int main() {
    return 0;
}
