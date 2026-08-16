// Generated C + ACSL

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  int degree;
  int fieldStudy;
  int school;
} Relationships;

/*@
  predicate ValidDate(Date d) =
    d.year >= 1900 && 1 <= d.month && d.month <= 12 && 1 <= d.day && d.day <= 31;
*/

/*@
  predicate DateLessOrEqual(Date d1, Date d2) =
    d1.year < d2.year ||
    (d1.year == d2.year && d1.month < d2.month) ||
    (d1.year == d2.year && d1.month == d2.month && d1.day <= d2.day);
*/

/*@
    requires degree != 0;
    requires fieldStudy != 0;
    requires school != 0;
    requires \valid(r);
    assigns r->degree, r->fieldStudy, r->school;
*/
void SetRelationships(Relationships *r, int degree, int fieldStudy, int school)
{
  r->degree = degree;
  r->fieldStudy = fieldStudy;
  r->school = school;
}