#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long cred;
    do
    {
        cred = get_long_long("numero do cartão: ");
    }
    while(cred < 1);
    int digit;
    int digit_1;
    int digit_2;
    int digit1;
    int digit1_1;
    int digit1_2;
    int sum = 0;
    int sum_1 = 0;
    int sum_total;
    int sum_lasdigits;
    int first2digits;
    int firstdigits;

    long long credit1 = cred / 10;
    while (credit1 > 0)
    {
        digit= credit1 % 10;
        credit1 /= 100;
        digit = digit * 2;
        if (digit > 9)
        {
            digit_1 = digit % 10;
            digit /= 10;
            digit_2 = digit % 10;
            digit = digit_1 + digit_2;
        }
        sum = sum + digit;
    }
    long long credit2 = cred;
    while (credit2 > 0)
    {
        digit1 = credit2 % 10;
        credit2 /= 100;
        if (digit1 > 9)
        {
            digit1_1 = digit1 % 10;
            digit1 /= 10;
            digit1_2 = digit1 % 10;
            digit1 = digit1_1 + digit1_2;
        }
        sum_1 = sum_1 + digit1;
    }
    sum_total = sum + sum_1;
    sum_lasdigits = sum_total % 10;
    long long creddigit = cred;
    int digit_length = 0;
    while (creddigit != 0)
    {
        creddigit /= 10;
        digit_length++;
    }
     first2digits = cred / pow(10, digit_length - 2);
     firstdigits = cred / pow(10, digit_length - 1);
     if (sum_lasdigits == 0 && digit_length == 15 && (first2digits == 34 || first2digits == 37)) // AMEX
     {
         printf("AMEX\n");
     }
     else if (sum_lasdigits == 0 && digit_length == 16 && (first2digits == 51 || first2digits == 52 || first2digits == 53 || first2digits == 54 || first2digits == 55)) // MASTERCARD
     {
         printf("MASTERCARD\n");
     }
     else if (sum_lasdigits == 0 && (digit_length == 13 || digit_length == 16) && firstdigits == 4) // VISA
     {
         printf("VISA\n");
     }
     else
     {
         printf("INVALID\n");
     }
}