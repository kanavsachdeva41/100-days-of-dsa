/* Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored */
#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    getchar();                 

    char code[n + 1];         

    printf("Enter string: ");
    fgets(code, sizeof(code), stdin);

    code[strcspn(code, "\n")] = '\0';

    int len = strlen(code);

    for (int i = 0; i < len / 2; i++) {
        char temp = code[i];
        code[i] = code[len - 1 - i];
        code[len - 1 - i] = temp;
    }

    printf("Mirror code: %s\n", code);
    return 0;
}
