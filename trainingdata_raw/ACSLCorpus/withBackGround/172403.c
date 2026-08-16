#include <stdbool.h>

enum BookTag { Novel, Textbook, Magazine };

struct Book {
    enum BookTag tag;
    union {
        struct { unsigned int pages; } novel;
        struct { unsigned int chapters; } textbook;
        struct { unsigned int issues; } magazine;
    };
};

/*@
    predicate is_thick(struct Book e) =
        e.tag == Novel && e.novel.pages > 500;

    predicate is_academic(struct Book e) =
        e.tag == Textbook;

    predicate is_journalist(struct Book e) =
        e.tag == Magazine;

    logic integer get_info(struct Book e) =
        e.tag == Novel ? e.novel.pages :
        e.tag == Textbook ? e.textbook.chapters :
        e.magazine.issues;

    lemma check_chapters:
        \forall struct Book e; 
        e.tag == Textbook ==> e.textbook.chapters > 10 ==> \true;
*/

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int read_book(void) {
    struct Book novel;
    //@ ghost enum BookTag novel_tag;
    //@ ghost unsigned int novel_pages;
    
    novel.tag = Novel;
    novel.novel.pages = 700;
    //@ ghost novel_tag = novel.tag;
    //@ ghost novel_pages = novel.novel.pages;
    
    //@ assert is_thick(novel);
    return 0;
}

/*@
    assigns \nothing;
    ensures \result == 0;
*/
int write_article(void) {
    struct Book magazine;
    //@ ghost enum BookTag magazine_tag;
    //@ ghost unsigned int magazine_issues;
    
    magazine.tag = Magazine;
    magazine.magazine.issues = 12;
    //@ ghost magazine_tag = magazine.tag;
    //@ ghost magazine_issues = magazine.magazine.issues;
    
    //@ assert is_journalist(magazine);
    return 0;
}
