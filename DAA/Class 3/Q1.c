#include<stdio.h>

int sum1, difference1, product1, quotient1, remainder1;
int flag=0;

void arith(int num1, int num2) {
    sum1 = num1 + num2;
    difference1 = num1 - num2;
    product1 = num1 * num2;

    if (num2==0)
    {
        flag=1;
        printf("The denominator for division is a negative number\n");
    }
    else{
        quotient1 = num1 / num2;
        remainder1 = num1 % num2;
    }
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    arith(num1, num2);

    printf("Sum: %d\n", sum1);
    printf("Difference: %d\n", difference1);
    printf("Product: %d\n", product1);

    if (flag!=1){
    printf("Quotient: %d\n", quotient1);
    printf("Remainder: %d\n", remainder1);
    }

    return 0;
}