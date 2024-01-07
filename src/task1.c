#include <stdio.h>

typedef struct Row {
    int a;
    int b; 
} Row;

/*!
*Task1. *
* Findout all the rows that satisfy below conditions:
*
* ((b>=10 && b<500000) &&
* (a==10 || a==200 || a==3000))
*
* Print them to the terminal, one row per line, for example:
*
* 10,31
* 10,23
* 200,16
*
* @param nrows The total number of rows.
* @paramrows Therows,forexamplerows[0]isthefirstrow.
*/
                    
void
task1(const Row *rows, int nrows)
{
    int i = 0;
    int flag = 0;
    
    for (i = 0;  i < nrows;i++) {
        flag = rows[i].a == 10 || rows[i].a == 200 || rows[i].a == 3000;
        flag = flag && rows[i].b >= 10 && rows[i].b < 500000;
        if (flag) {
            printf("%d,%d\n", rows[i].a, rows[i].b);
        }
    }
}





int main()
{
    Row test_rows[] = {
        { 10, 31 },
        { 10, 720000000 },
        { 200, 22 },
        { 200, 33 },
        { 1500, 12 },
        { 1500, 34 },
        { 3000, 5 },
    };
    task1(test_rows, 7);
    return 0;
}

