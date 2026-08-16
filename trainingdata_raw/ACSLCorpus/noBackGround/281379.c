struct Magazine {
    unsigned int pages;
    unsigned int issues;
};

struct Book {
    unsigned int pages;
    unsigned int chapters;
};

/*@
    requires ((mag->issues) <= 100);
    assigns mag->issues;
    ensures ((mag->pages) == (\old(mag->pages)) && (mag->issues) == 0);
*/
void distribute_magazine(struct Magazine* mag) {
    //@ assert ((mag->pages) * 100) == mag->pages * 100;
    mag->issues = 0;
}

/*@
    assigns book->chapters;
    ensures ((book->pages) == (\old(book->pages)) && (book->chapters) == (\old(book->chapters)) / 2);
*/
void flip_chapters(struct Book* book) {
    book->chapters = book->chapters / 2;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
