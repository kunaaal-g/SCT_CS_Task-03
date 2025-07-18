#include <stdio.h>
#include <string.h>
#include <ctype.h>
int checkStrength(char password[]) 
{
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }
    int score = hasUpper + hasLower + hasDigit + hasSpecial;
    if (len >= 8 && score == 4)
        return 3; 
    else if (len >= 6 && score >= 2)
        return 2; 
    else
        return 1; 
}
int main() 
{
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int result = checkStrength(password);
    printf("\nPassword Analysis:\n");
    switch (result) 
    {
        case 3:
            printf("Strength: STRONG ✅\n");
            break;
        case 2:
            printf("Strength: MODERATE ⚠️\n");
            break;
        case 1:
        default:
            printf("Strength: WEAK ❌\n");
            break;
    }
    return 0;
}