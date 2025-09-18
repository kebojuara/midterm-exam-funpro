#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; 
        }
        
        left++;
        right--;
    }
    return 1;
}

int main() {
    char word[100000];

    printf("Enter a string: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0;

    if (palindrome(word)) {
        printf("It is a palindrome\n");
    } else {
        printf("It is not a palindrome\n");
    }

    return 0;
}