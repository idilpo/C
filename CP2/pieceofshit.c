#include <stdio.h>
#include <stdlib.h>

void function1(int a);
void function2(int b);
void function3(int c);

int main(void)
{
    void (*f[3])(int) = {function1, function2, function3};

    printf("%s", "Enter a number between 0 and 2, 3 to end");
    size_t choice;
    scanf("%zu", &choice);

    while (choice >=0 && choice < 3)
    {
        (*f[choice])(choice);
        printf("%s", "Enter a number between 0 and 2, 3 to end");
        scanf("%zu", &choice);
    }
    puts("Program execution completed.");
}
void function1(int a)
{printf("You entered %d so function 1 was called\n\n",a);}
void function2(int b)
{printf("You entered %d so function 2 was called\n\n",b);}
void function3(int c)
{printf("You entered %d so function 3 was called\n\n",c);}