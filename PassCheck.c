#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define min_len 8
#define max_len 64
#define exellent_len 12

const char* assess_password_strength(const char* password) {
    int has_uppercase = 0, has_lowercase = 0, has_number = 0, has_special_char = 0;
    int special_char_count = 0;
    int special_char_seen[256] = {0};

    size_t length = strlen(password);

    if (length < min_len) return "Use 8 characters or more!";
    if (length > max_len) return "Password exceeds maximum length of 64 characters.";

    for (size_t i = 0; i < length; i++) {
        char ch = password[i];
        if (isupper(ch)) has_uppercase = 1;
        else if (islower(ch)) has_lowercase = 1;
        else if (isdigit(ch)) has_number = 1;
        else if (strchr("!@#$%^&*(),.?\":{}|<>", ch)) {
            if (!special_char_seen[(unsigned char)ch]) {
                special_char_seen[(unsigned char)ch] = 1;
                special_char_count++;
            }
            has_special_char = 1;
        } else return "Password is invalid!"; 
    }

    if (has_special_char && special_char_count > 2) 
        return (length >= exellent_len) ? "Password is excellent." : "Password is strong.";
    
    if (has_uppercase && has_lowercase && has_number && has_special_char) 
        return (length >= exellent_len) ? "Password is excellent." : "Password is strong.";

    if ((has_uppercase || has_lowercase) && has_number) return "Password is poor.";
    if (has_number || has_lowercase || has_uppercase) return "Password is weak.";

    return "Password is invalid.";
}

int main() {
    char password[max_len + 1];

    printf("Enter your password: ");
    if (fgets(password, sizeof(password), stdin)) {
        size_t len = strlen(password);
        if (len > 0 && password[len - 1] == '\n') password[len - 1] = '\0';
        printf("%s\n", assess_password_strength(password));
    }

    return 0;
}
