#include <stdio.h>
#include <string.h>

int operations(int ni, int ni1, int *res) {
    if (ni1 + ni >= 65 && ni1 + ni <= 122) {
        *res = ni1 + ni;
        return 1;
    }
    if (ni1 - ni >= 65 && ni1 - ni <= 122) {
        *res = ni1 - ni;
        return 1;
    }
    if ((ni1 * 2) - ni >= 65 && (ni1 * 2) - ni <= 122) {
        *res = (ni1 * 2) - ni;
        return 1;
    }
    if (((ni1 - 3) * 2) + ni >= 65 && ((ni1 - 3) * 2) + ni <= 122) {
        *res = ((ni1 - 3) * 2) + ni;
        return 1;
    }
    return 0;
}

void decipher(int arr[], int i, char *result, int *index) {
    if (i == 0) return; 

    int res;
    if (operations(arr[i], arr[i - 1], &res)) {
        result[*index] = (char)res;
        (*index)++;
        arr[i - 1] = res;
    }

    decipher(arr, i - 1, result, index);
}

int main() {
    int arr[] = {94, 222, 221, 186, 181, 208, 207, 110, 187, 185, 17, 212, 115, 215, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    char result[n];
    int index = 0;

    decipher(arr, n - 1, result, &index);
    
    result[index] = '\0';

    for (int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c\n", result[i]);
    }

    return 0;
}
