#include "minunit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int suma(int a,int b)
{
    return a+b;
}

int maximo(int a,int b)
{
    if(a>b){ return a;}
    else{return b;}
}


MU_TEST(test_pruebamia)
{
	mu_check(7 == maximo(3, 7));
	mu_assert(-7 == maximo(-7, -14), "Pruebo maximo negativo");
	mu_assert_int_eq(5, maximo(0, 5));
	mu_assert_double_eq(1.245, 1.2);
}
MU_TEST(test_suma)
{
	mu_check(10 == suma(3, 7));
	mu_assert(-21 == suma(-7, -14), "Pruebo suma negativo");
	mu_assert_int_eq(5, suma(0, 5));
}

MU_TEST(test_check)
{
	mu_check(5 == 7);
}
MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_check);
	MU_RUN_TEST(test_pruebamia);
	MU_RUN_TEST(test_suma);
}




 int countOccurrences2(FILE *fptr, const char *word)
{
    char elfinal[BUFFER_SIZE];
    strcpy(elfinal,"MU_TEST_SUITE(test_suite) {");

    char str[BUFFER_SIZE];
    char *pos;

    int index, count;

    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;
        if(strstr(str, word) != NULL) {
    //printf("%s",str);
    strcat(elfinal,str);
   // printf("%s",elfinal);
    }

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }
fputs(elfinal,fptr);
    return count;
    }


int main()
{

FILE *fptr;
fptr = fopen("main.c", "r+");
int res=countOccurrences2(fptr,"MU_TEST(")-1;


printf("%d WORDS",res);

	//MU_RUN_SUITE(test_suite);
	//MU_REPORT();
	//return minunit_status;

}

