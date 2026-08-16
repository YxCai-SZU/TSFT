// Generated C + ACSL

typedef struct {
  int isAutoCreated;
  int isPrimaryKey;
  int id;
} HomePage;

typedef struct {
  int isAutoCreated;
  int isPrimaryKey;
  int id;
} Testimonial;

/*@
    requires pages_len > 0;
    requires pages != \null;
    requires \valid_read(pages + (0 .. pages_len-1));
    requires \forall integer i; 0 <= i < pages_len ==> pages[i] != 0;
    requires clubs != \null;
    requires \valid_read(clubs + (0 .. clubs_len-1));
    requires \forall integer i; 0 <= i < clubs_len ==> clubs[i] != 0;
    assigns \nothing;
    ensures \result != 0;
    ensures \result > 0;
*/
int CreateHomePage(int* pages, int pages_len, int* clubs, int clubs_len)
{
  HomePage newPage;
  newPage.id = pages_len + 1;
  newPage.isAutoCreated = 1;
  newPage.isPrimaryKey = 1;
  return newPage.id;
}

/*@
    requires photo != \null;
    requires photo_len > 0;
    requires \valid_read(photo + (0 .. photo_len-1));
    requires quote != \null;
    requires quote_len > 0;
    requires \valid_read(quote + (0 .. quote_len-1));
    assigns \nothing;
    ensures \result > 0;
*/
int CreateTestimonial(char* photo, int photo_len, char* quote, int quote_len)
{
  Testimonial t;
  t.id = 1;
  t.isAutoCreated = 1;
  t.isPrimaryKey = 1;
  int testimonial = t.id;
  /*@ assert testimonial >= 0 && testimonial <= 2147483647; */
  return testimonial;
}

/*@
  predicate Valid(integer id) =
    id > 0;
*/