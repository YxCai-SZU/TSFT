#include <stdint.h>
#include <stdbool.h>

enum Tag { Math, Sci, Lang };

struct Exam {
    enum Tag tag;
    unsigned int done;
    unsigned int time;
};

/*@
    predicate is_Lang(struct Exam e) = e.tag == Lang;

    predicate passed(struct Exam e) =
        is_Lang(e) && e.time <= 180;

    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer r_squared(integer r) = r * r;

    logic integer final_result(integer r) = 3 * r * r;

    lemma r_squared_bound: \forall integer r; valid_range(r) ==> r_squared(r) <= 10000;
    lemma intermediate_bound: \forall integer r; valid_range(r) ==> 3 * r_squared(r) <= 30000;
    lemma final_bound: \forall integer r; valid_range(r) ==> final_result(r) <= 30000;
*/

int32_t func(uint32_t r) {
    int32_t result;
    uint32_t r_squared;

    //@ assert valid_range(r);
    
    //@ assert r_squared(r) <= 10000;
    r_squared = r * r;
    
    //@ assert 3 * r_squared(r) <= 30000;
    result = 3 * (int32_t)r_squared;
    
    //@ assert final_result(r) <= 30000;
    return result;
}

bool check(struct Exam e) {
    bool result = false;

    //@ assert e.tag != Math;
    //@ assert e.tag != Sci;

    if (e.time > 180) {
        //@ assert !passed(e);
        result = false;
    } else {
        //@ assert passed(e);
        result = true;
    }

    return result;
}

int32_t process_exam_and_score(struct Exam e, uint32_t r) {
    int32_t score = func(r);
    bool exam_passed = check(e);
    
    //@ assert final_result(r) <= 30000;
    //@ assert (exam_passed == 1) <==> passed(e);
    
    int32_t result;
    
    if (exam_passed) {
        //@ assert passed(e);
        result = score;
    } else {
        result = -1;
    }
    
    //@ assert (result == -1) ==> !passed(e);
    //@ assert (result >= 0) ==> (passed(e) && final_result(r) <= 30000);
    
    return result;
}
