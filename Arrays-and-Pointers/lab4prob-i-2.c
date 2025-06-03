#include <stdio.h>

int ends_with(const char *string, const char *ending) {
    int string_length = 0;
    int ending_length = 0;

    while (string[string_length] != '\0') {
        string_length++;
    }
    while (ending[ending_length] != '\0') {
        ending_length++;
    }
    if (string_length < ending_length) {
        return 0;
    }
    for (int i = 1; i <= ending_length; i++) {
        if (string[string_length - i] != ending[ending_length - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    const char *strings_for_test[] = {"abcd", "efgh", "kl", "abcxyz"};
    const char *endings_for_test[] = {"cd", "fg", "ijkl", "xyz"};
    for (int i = 0; i < 4; i++) {
        int result = ends_with(strings_for_test[i], endings_for_test[i]);
        printf("ends_with(\"%s\", \"%s\") : %d\n", strings_for_test[i], endings_for_test[i], result);
    }
}