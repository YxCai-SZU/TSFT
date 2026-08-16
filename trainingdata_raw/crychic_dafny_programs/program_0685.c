// Generated C + ACSL

typedef struct {
    int isShow;
    int isDelete;
    int id;
} Category;

typedef struct {
    int id;
} CategoryValue;

typedef struct {
    int Some;
    CategoryValue value;
} OptionalCategory;

typedef struct {
    int isShow;
    int isDelete;
    OptionalCategory courseCategory;
} Course;

typedef struct {
    int isShow;
    int isDelete;
    int Some;
    struct {
        int id;
    } value;
} CourseOption;

typedef struct {
    int isShow;
    int isDelete;
    int id;
    CourseOption course;
    int course_exists;
    void* course_ptr;
} Chapter;

Category* categories;
int categories_len;
Course* courses;
int courses_len;
Chapter* chapters;
int chapters_len;
Chapter* chapters_global;

/*@
    requires \valid_read(categories + (0 .. categories_len-1));
    requires categories_len >= 0;
    requires \valid(result_len);
    assigns *result_len;
    ensures \result != \null;
    ensures *result_len >= 0;
*/
int* GetActiveCategories(int* result_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= categories_len;
  loop invariant result <= i;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant categories_len - i;
*/
  while ((i < categories_len))
    {
      if ((categories[i].isShow && !(categories[i].isDelete)))
      {
        result = (result + 1);
      }
      i = (i + 1);
    }
  *result_len = result;
  return &result;
}

/*@
    requires categoryId >= -1;
    requires \valid_read(courses + (0 .. courses_len-1));
    requires courses_len >= 0;
    requires \valid(result_len);
    assigns *result_len;
    ensures \result != \null;
    ensures *result_len >= 0;
*/
int* GetFilteredCourses(int categoryId, int* result_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= courses_len;
  loop invariant result <= i;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant courses_len - i;
*/
  while ((i < courses_len))
    {
      int courseMatches = (courses[i].isShow && !(courses[i].isDelete));
      if (categoryId >= 0)
      {
        courseMatches = ((courseMatches && courses[i].courseCategory.Some) && (courses[i].courseCategory.value.id == categoryId));
      }
      if (courseMatches)
      {
        result = (result + 1);
      }
      i = (i + 1);
    }
  *result_len = result;
  return &result;
}

/*@
    requires courseId >= 0;
    requires chapters_global != \null;
    requires chapters_len >= 0;
    requires \valid_read(chapters_global + (0 .. chapters_len-1));
    requires \valid(result_len);
    assigns *result_len;
    ensures *result_len >= 0;
*/
int* GetCourseChapters(int courseId, int* result_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= chapters_len;
  loop invariant result <= i;
  loop invariant result >= 0;
  loop assigns i, result;
  loop variant chapters_len - i;
*/
  while ((i < chapters_len))
    {
      if ((((chapters[i].isShow && !(chapters[i].isDelete)) && chapters[i].course.Some) && (chapters[i].course.value.id == courseId)))
      {
        result = (result + 1);
      }
      i = (i + 1);
    }
  *result_len = result;
  return &result;
}