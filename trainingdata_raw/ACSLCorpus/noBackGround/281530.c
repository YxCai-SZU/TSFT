#include <stdbool.h>

struct Book {
    unsigned int pages;
    unsigned int chapters;
};

/*@ requires \valid(book);
    assigns \nothing;
    ensures \result.pages == book->chapters;
    ensures \result.chapters == book->pages;
    ensures ((\result.pages) + (\result.chapters)) == 
            ((book->pages) + (book->chapters));
*/
struct Book cut_up(const struct Book* book) {
    struct Book new_book;
    //@ ghost unsigned int old_pages = book->pages;
    //@ ghost unsigned int old_chapters = book->chapters;
    
    new_book.pages = book->chapters;
    new_book.chapters = book->pages;
    
    //@ assert new_book.pages == old_chapters;
    //@ assert new_book.chapters == old_pages;
    //@ assert ((new_book.pages) + (new_book.chapters)) == ((old_pages) + (old_chapters));
    
    return new_book;
}

int main() {
    struct Book b;
    struct Book new_b;
    
    b.pages = 100;
    b.chapters = 10;
    
    //@ assert ((b.pages) + (b.chapters)) == 110;
    
    new_b = cut_up(&b);
    
    //@ assert new_b.pages == 10;
    //@ assert new_b.chapters == 100;
    //@ assert ((new_b.pages) + (new_b.chapters)) == ((b.pages) + (b.chapters));
    
    return 0;
}
