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
* @param nrows The total number of rows,rows has sorted by a
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


int 
find_right(const Row *rows, int nrows, int max)
{
    int end = nrows;
    int start = 0;
    int mid = nrows / 2;
    
    if (rows[end-1].a <= max ) {
        printf("find right: %d\n", end - 1);
        return end - 1;
    }
    while (1) {
        if (rows[mid].a <= max) {
            start = mid;
            mid = start + (end - mid) / 2;
        } else {
            end = mid;
            mid = start + (end - mid) / 2;
        }
        printf("finding right, start is %d, mid is %d, end is %d\n", start, mid, end);
        if (rows[mid].a <= max && rows[mid+1].a > max) {
            break;
        }
        if (mid == 0 && rows[mid].a == max ) {
            break;
        }
        if (mid < 0 || start == end) {
            mid = -1;
            break;
        }
    }
    printf("find right: %d\n", mid);
    return mid;
}

int
find_left(const Row *rows, int nrows, int max)
{
    int end = nrows;
    int start = 0;
    int mid = nrows / 2;
    
    int n=0;
    while (1) {
        printf("finding left,max is %d, start is %d, mid is %d, end is %d,mid's value is %d,mid-1's value is %d\n", max, start, mid, end,rows[mid].a,rows[mid-1].a);
        if (mid == 0 && rows[mid].a == max ) {
            break;
        }
        if (rows[mid].a >= max && rows[mid - 1].a < max) {
            break;
        }
        if (rows[mid].a == max) {
            end = mid;
            mid = start + (end - start) / 2;
        } else if (rows[mid].a > max) {
            start = mid;
            mid = start + (end - start) / 2;
        } else if (rows[mid].a < max) {
            start = mid;
        } 
        mid = start + (end - start) / 2;
        n++;
        if (n > 4) {
            break;
        }
        if (mid < 0 || start == end) {
            mid = -1;
            break;
        }
    }
    printf("find left: %d\n", mid);
    return mid;
}


void 
print_row(const Row *rows, int nrows, int max)
{
    int i = 0;
    int flag = 0;
    int start = -1;
    int end = -1;
    
    end = find_right(rows, nrows, max);
    if (end == -1) {
        return;
    } else if (end == 0) {
        start = end;
        printf("start is %d, end is %d\n", start, end);
    } else {
        start = find_left(rows, end, max);
        if (start == -1) {
            printf("program error");
        } else {
           printf("start is %d, end is %d\n", start, end);
        }
    }

    for (i = start; i <= end; i++) {
        flag = rows[i].a == 10 || rows[i].a == 200 || rows[i].a == 3000;
        flag = flag && rows[i].b >= 10 && rows[i].b < 500000;
        if (flag) {
            printf("%d,%d\n", rows[i].a, rows[i].b);
        }
    }
}

void 
task2(const Row *rows, int nrows)
{
    int end = -1;
    int start = -1;
    printf("total rows is %d\n", nrows);
    print_row(rows, nrows, 10);
    print_row(rows, nrows, 200);
    print_row(rows, nrows, 3000);
}



int main()
{
    Row test_rows[] = {
        { 10, 31 },
        //{ 10, 720000000 },
        { 200, 22 },
        { 200, 33 },
        { 200, 42 },
        { 200, 37 },
        { 1500, 12 },
        { 1500, 34 },
        { 1500, 12 },
        { 1500, 24 },
        { 1500, 54 },
        { 1500, 74 },
        //{ 3000, 5 },
        { 3000, 40 },
    };
    task2(test_rows, sizeof(test_rows)/sizeof(Row));
    return 0;
}

