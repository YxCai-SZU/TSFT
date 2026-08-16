#include <stdbool.h>

/*@ predicate is_even_spec(integer n) = (n % 2) == 0; */

/*@ logic integer func_spec(integer r) = 3 * r * r; */

/*@ lemma func_bounds: 
      \forall integer r; 1 <= r <= 100 ==> func_spec(r) <= 3 * 100 * 100; */

/*@ requires \true;
    assigns \nothing;
    ensures \result == (n % 2 == 0);
*/
bool is_even(unsigned int n) {
    //@ assert n % 2 == 0 || n % 2 == 1;
    return n % 2 == 0;
}

/*@ requires 1 <= r <= 100;
    assigns \nothing;
    ensures \result == 3 * r * r;
    ensures \result <= 3 * 100 * 100;
*/
int func(int r) {
    //@ assert func_spec(r) <= 3 * 100 * 100;
    return 3 * r * r;
}

struct Book {
    unsigned int pages;
    unsigned int chapters;
};

/*@ logic integer words(struct Book book) = book.pages * 250; */

/*@ predicate flip_chapters_post(struct Book old_book, struct Book new_book) = 
      new_book.pages == old_book.pages && 
      new_book.chapters == old_book.chapters / 2; */

/*@ requires \true;
    assigns \nothing;
    ensures flip_chapters_post(book, \result);
*/
struct Book flip_chapters(struct Book book) {
    struct Book ret;
    ret.pages = book.pages;
    ret.chapters = book.chapters / 2;
    //@ assert flip_chapters_post(book, ret);
    return ret;
}
