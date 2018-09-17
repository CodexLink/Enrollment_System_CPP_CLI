#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
    while (1)
    {
        long long int test;
        scanf("%lld", &test);
        printf("%lli\n", test);
        printf("%lld\n\n", test);
        printf("Size of Int %i", sizeof(long long int));
        getch();
    }
}
