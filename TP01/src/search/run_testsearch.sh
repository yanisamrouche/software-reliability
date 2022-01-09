gcc -Wall -c search.c
gcc -Wall -I$HOME/local/CUnit/include -o testSearch testSearch.c search.o -L$HOME/local/CUnit/lib -lcunit -o testSearch