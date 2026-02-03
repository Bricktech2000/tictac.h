#include <stdio.h>
#include <time.h>

#define TICTAC_SCALE 1000000
#define TICTAC_FORMAT "%8.6lld\t"
#define TICTAC_STREAM stderr

// #define TICTAC_SCALE 1.0
// #define TICTAC_FORMAT "%f,"
// #define TICTAC_STREAM stdout

#define TIC(LABEL)                                                             \
  ; /* for labels */                                                           \
  clock_t _start_##LABEL = clock();                                            \
  static clock_t _total_##LABEL = 0
#define TAC(LABEL)                                                             \
  _total_##LABEL += (_start_##LABEL = clock() - _start_##LABEL),               \
      fprintf(TICTAC_STREAM, TICTAC_FORMAT TICTAC_FORMAT "%s\n",               \
              (long long)_start_##LABEL * TICTAC_SCALE / CLOCKS_PER_SEC,       \
              (long long)_total_##LABEL * TICTAC_SCALE / CLOCKS_PER_SEC,       \
              #LABEL),                                                         \
      _start_##LABEL = clock() /* exclude call to `fprintf` */
#define TICTAC(LABEL)                                                          \
  /* ISO/IEC 9899:TC3, $7.23.1 requires `clock_t` to be an arithmetic type */  \
  for (clock_t _start_##LABEL = clock(), _tictac = 1; _tictac; _tictac = 0)    \
    for (int _tictac = 0; _tictac < 2; _tictac++)                              \
      if (_tictac) {                                                           \
        static clock_t _total_##LABEL = 0;                                     \
        TAC(LABEL);                                                            \
      } else
