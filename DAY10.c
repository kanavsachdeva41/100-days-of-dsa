/* Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards */

#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];

    printf("Enter string: ");
    scanf("%s", s);

    int l=0;
    int r = strlen(s)-1;
    int ispalin=1;

    while(l<r)
    {
        if (s[l]!=s[r])
        {
            ispalin=0;
            break;
        }
        l++;
        r--;
    }

    if (ispalin==1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}