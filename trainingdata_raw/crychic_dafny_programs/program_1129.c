// Generated C + ACSL

#define FILMS_LENGTH 12

/*@
    assigns \nothing;
*/
void PrintFilms(int* films, int films_len);

/*@
    assigns \nothing;
*/
void FilmDatabase(void)
{
  int films[FILMS_LENGTH];
  int i = 0;
/*@
  loop invariant 0 <= i <= FILMS_LENGTH;
  loop assigns i, films[0 .. FILMS_LENGTH-1];
  loop variant FILMS_LENGTH - i;
*/
  while ((i < FILMS_LENGTH))
    {
      /* unsupported stmt: films[i] := new Film("", ""); */
      i = (i + 1);
    }
  /* unsupported stmt: films[0] := new Film("Тренер Картер", "Фильм про нищебродскую баскетбольную команду,которая почти стала лучшей в стране, после прихода в нее нового тренера,проделавшего с командой большую работу"); */
  /* unsupported stmt: films[1] := new Film("Гарри Поттер и Тайная комната", "Второй фильм про Гарри .Да присутствует феникс, василиск, меч Грифиндора и молодой Том Редл"); */
  /* unsupported stmt: films[2] := new Film("Перси Джексон и Похититель молний", "Не только в школе волшебства и чародейства 'Хогвартс' происходят загадочные истрашные события. Перси Джексон - американский школьник (и по совместительству сын Посейдона) ,едва не становится жертвой учительницы математики ( оказавшейся злой фурией)"); */
  /* unsupported stmt: films[3] := new Film("Игра Эндера", "Фильм, рассказывающий об удивительном мальчике по имени Эндер. Он живет в такое время ,когда весь мир готовится к повторному нашествию их врагов.И Эндер единственный , кто может их остановить, пусть ему всего 12"); */
  /* unsupported stmt: films[4] := new Film("Мстители", "Мстители впервые собираются для угрозы , которую нельзя убрать по одиночке - вторжение на Землю во главе с Локи (скандинавский бог, а также брат Тора). В этом фильме показывается сбор мстителей и их становление как лучшей команды на Земле"); */
  /* unsupported stmt: films[5] := new Film("Человек-паук", "В главной роли лучший из паучков - Тоби Магуайр!! Рассказывается о получении Питером способностей и становлением его как героя"); */
  /* unsupported stmt: films[6] := new Film("Капитан Америка", "Фильм о первом супергерое Америки. Вы увидите путь от дрыща до супергероя"); */
  /* unsupported stmt: films[7] := new Film("Назад в будущее 1-3", "Трилогия расскажет вам про Дока и Марти и их приключения по таймлайне"); */
  /* unsupported stmt: films[8] := new Film("5", "Фильм про 5 подвигов Тесея"); */
  /* unsupported stmt: films[9] := new Film("Monday,Tuesday,Wednesday", "Фильм про дни недели"); */
  /* unsupported stmt: films[10] := new Film("30", "Документальный фильм про Стефана Карри"); */
  /* unsupported stmt: films[11] := new Film("Майкл Джордан,Коби Брайнт,Леброн Джеймс,Стефан Карри", "Документальный фильм про лучших баскетболистов в истории"); */
  PrintFilms(films, FILMS_LENGTH);;
}

/*@
    requires films != \null;
    requires films_len > 0;
    requires \valid_read(films + (0 .. films_len-1));
    assigns \nothing;
*/
void PrintFilms(int* films, int films_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= films_len;
  loop assigns i;
  loop variant films_len - i;
*/
  while ((i < films_len))
    {
      /* unsupported stmt: print "Фильм: ", films[i].name, " Описание: ", films[i].description, "\n"; */
      i = (i + 1);
    }
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  FilmDatabase();;
}