#include <stdint.h>

typedef struct {
    uint32_t number_of_pages;
    uint32_t words_per_page;
} Book;

/*@
    requires ((*book).number_of_pages >= 0 &&
        (*book).words_per_page >= 0);
    requires book->number_of_pages + new_pages <= 0xffffffff;
    ensures book->number_of_pages == \old(book->number_of_pages) + new_pages;
    ensures ((*book).number_of_pages >= 0 &&
        (*book).words_per_page >= 0);
    assigns book->number_of_pages;
*/
void increase_pages(Book* book, uint32_t new_pages) {
    //@ assert book->number_of_pages + new_pages <= 0xffffffff;
    
    uint32_t old_pages = book->number_of_pages;
    book->number_of_pages = old_pages + new_pages;
    
    //@ assert book->number_of_pages == old_pages + new_pages;
}

int main() {
    return 0;
}
