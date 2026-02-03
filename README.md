# tictac.h

_Tiny portable single-header timing library_

`tictac.h` is a tiny single-header library that provides convenience macros for timing program fragments.

Annotate a statement with `TICTAC(label)` or surround a declaration or sequence of statements with `TIC(label);` and `TAC(label);` to output current and total elapsed CPU time.

```c
#include "tictac.h"

void work(void);

int main(void) {
  // start a timer labeled `main`
  TIC(main);

  // time a block then output
  TICTAC(loop)
  for (int i = 0; i < 8; i++)
    work();

  // output time since `TIC(main);`
  TAC(main);
  work();

  // time a block then output
  TICTAC(sub) {
    int i = 3;
    do
      // time an iteration then output
      TICTAC(iter) work();
    while (i--);
  }

  // output time since `TAC(main);`
  TAC(main);
}
```

```tsv
 1516047	 1516047	loop
 1516128	 1516128	main
  189462	  189462	iter
  188722	  378184	iter
  188504	  566688	iter
  188599	  755287	iter
  755405	  755405	sub
  944795	 2460923	main
```
