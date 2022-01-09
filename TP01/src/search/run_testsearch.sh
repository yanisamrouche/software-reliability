gcc -Wall -c ./src/search.c
gcc -Wall -I$HOME/local/CUnit/include -o testSearch ./test/testSearch.c search.o -L$HOME/local/CUnit/lib -lcunit -o testSearch