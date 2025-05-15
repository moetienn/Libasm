#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Declare the Assembly function
extern size_t ft_strlen(const char *str);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);

int main() {

    // Test ft_strlen

    printf("-------- FT_STRLEN TEST --------\n\n");

    size_t length = ft_strlen("Hello, Assembly!");
    printf("Length of '%s': %zu\n", "Hello, Assembly!", length);
    size_t length2 = strlen("Hello, Assembly!");
    printf("Length of '%s' using strlen: %zu\n", "Hello, Assembly!", length2);

    printf("\n");
    // Test ft_strlen with empty string
    size_t length3 = ft_strlen("");
    printf("Length of empty string: %zu\n", length3);
    size_t length4 = strlen("");
    printf("Length of empty string using strlen: %zu\n", length4);

    printf("\n");
    // Test ft_strlen with a long string
    const char *long_str = "This is a long string to test the ft_strlen function.";
    size_t length7 = ft_strlen(long_str);
    printf("Length of long string: %zu\n", length7);
    size_t length8 = strlen(long_str);
    printf("Length of long string using strlen: %zu\n", length8);

    printf("\n");
    // Test ft_strlen with a string containing special characters
    const char *special_str = "Hello, @#$%^&*()!-_+={}[]|:;\"'<>,.?/~`";
    size_t length9 = ft_strlen(special_str);
    printf("Length of string with special characters: %zu\n", length9);
    size_t length10 = strlen(special_str);
    printf("Length of string with special characters using strlen: %zu\n", length10);

    // Test ft_strlen with NULL pointer

    // ------ SegFault if the string is NULL ------

    // printf("\n");
    // printf("Testing strlen with NULL pointer...\n");
    // const char *null_str = NULL;
    // size_t length6 = strlen(null_str);
    // printf("Length of NULL pointer using strlen: %zu\n", length6);
    // size_t length5 = ft_strlen(null_str);
    // printf("Length of NULL pointer: %zu\n", length5);

    // Test ft_write

    printf("\n-------- FT_WRITE TEST --------\n\n");

    write(1, "native write: ", 15);

    ssize_t bytes_written = write(1, "Hello from Assembly!\n", 21);
    if (bytes_written == -1) {
        perror("write");
    } else {
        printf("Bytes written: %zd\n", bytes_written);
    }

    write(1, "\nft_write: ", 11);
    const char *message = "Hello from Assembly!\n";
    ssize_t bytes_written2 = ft_write(1, message, 21);
    if (bytes_written2 == -1) {
        perror("ft_write");
    } else {
        printf("Bytes written: %zd\n", bytes_written2);
    }
    
    printf("\n");
    // Test ft_write with NULL pointer
    const char *message2 = NULL;
    printf("-- Testing write with NULL pointer --\n\n");
    ssize_t bytes_written_test = write(1, message2, 10);
    if (bytes_written_test == -1) {
        perror("write with NULL pointer");
    } else {
        printf("Bytes written: %zd\n", bytes_written_test);
    }

    ssize_t bytes_written_test2 = ft_write(1, message2, 10);
    if (bytes_written_test2 == -1) {
        perror("ft_write with NULL pointer");
    } else {
        printf("Bytes written: %zd\n", bytes_written_test2);
    }

    printf("\n");
    // Test ft_write with a long string
    printf("-- Testing ft_write with a long string --\n\n");

    write(1, "native write: ", 15);
    const char *long_message = "This is a long message to test the ft_write function.\n";

    ssize_t bytes_written3 = write(1, long_message, 55);
    if (bytes_written3 == -1) {
        perror("write");
    } else {
        printf("Bytes written: %zd\n", bytes_written3);
    }

    write(1, "\nft_write: ", 11);
    ssize_t bytes_written4 = ft_write(1, long_message, 55);
    if (bytes_written4 == -1) {
        perror("ft_write");
    } else {
        printf("Bytes written: %zd\n", bytes_written4);
    }

    printf("\n");
    printf("-- Testing ft_write with invalid file descriptor --\n\n");

    write(1, "native write: ", 15);
    ssize_t bytes_written_invalid_fd = write(-1, "Test", 4);
    if (bytes_written_invalid_fd == -1) {
        perror("write with invalid file descriptor");
    } else {
        printf("Bytes written: %zd\n", bytes_written_invalid_fd);
    }

    write(1, "ft_write: ", 11);
    ssize_t bytes_written_invalid_fd2 = ft_write(-1, "Test", 4);
    if (bytes_written_invalid_fd2 == -1) {
        perror("ft_write with invalid file descriptor");
    } else {
        printf("Bytes written: %zd\n", bytes_written_invalid_fd2);
    }

    printf("\n");
    printf("-- Testing ft_write with large fd --\n\n");

    write(1, "native write: ", 15);
    ssize_t bytes_written_large_fd = write(9999, "Test", 4);
    if (bytes_written_large_fd == -1) {
        perror("write with invalid fd");
    } else {
        printf("Bytes written: %zd\n", bytes_written_large_fd);
    }

    write(1, "ft_write: ", 11);
    ssize_t bytes_written_large_fd2 = ft_write(9999, "Test", 4);
    if (bytes_written_large_fd2 == -1) {
        perror("ft_write with invalid fd");
    } else {
        printf("Bytes written: %zd\n", bytes_written_large_fd2);
    }

    printf("\n");
    printf("-- Testing ft_write with zero bytes to write --\n\n");

    write(1, "native write: ", 15);
    ssize_t bytes_written_zero = write(1, "Test", 0);
    if (bytes_written_zero == -1) {
        perror("write with zero bytes to write");
    } else {
        printf("Bytes written: %zd\n", bytes_written_zero);
    }

    write(1, "ft_write: ", 11);
    ssize_t bytes_written_zero2 = ft_write(1, "Test", 0);
    if (bytes_written_zero2 == -1) {
        perror("ft_write with zero bytes to write");
    } else {
        printf("Bytes written: %zd\n", bytes_written_zero2);
    }

    printf("\n");

    printf("-------- FT STRCMP TEST --------\n\n");

    // Test ft_strcmp
    const char *str1 = "Hello, Assembly!";
    const char *str2 = "Hello, Assembly!";

    write(1, "native strcmp: ", 16);
    int result = strcmp(str1, str2);
    printf("%d\n", result);

    write(1, "ft_strcmp: ", 11);
    int result2 = ft_strcmp(str1, str2);
    printf("%d\n", result2);

    printf("\n");

    // Test ft_strcmp with different strings
    const char *str3 = "Hello, World!";
    const char *str4 = "Hello, Assembly!";
    write(1, "native strcmp: ", 16);
    int result3 = strcmp(str3, str4);
    printf("%d\n", result3);

    write(1, "ft_strcmp: ", 11);
    int result4 = ft_strcmp(str3, str4);
    printf("%d\n", result4);
    printf("\n");

    // Test ft_strcmp with empty strings
    const char *str5 = "";
    const char *str6 = "";
    write(1, "native strcmp: ", 16);
    int result5 = strcmp(str5, str6);
    printf("%d\n", result5);

    write(1, "ft_strcmp: ", 11);
    int result6 = ft_strcmp(str5, str6);
    printf("%d\n", result6);
    printf("\n");

    // Test ft_strcmp with NULL pointers
    // ------ SegFault if the string is NULL ------
    // printf("Testing strcmp with NULL pointers...\n");
    // const char *null_str1 = NULL;

    // const char *null_str2 = NULL;
    // write(1, "native strcmp: ", 16);
    // int result7 = strcmp(null_str1, null_str2);
    // printf("%d\n", result7);
    // write(1, "ft_strcmp: ", 11);
    // int result8 = ft_strcmp(null_str1, null_str2);
    // printf("%d\n", result8);
    // printf("\n");
    // Test ft_strcmp with different lengths
    const char *str7 = "Hello";
    const char *str8 = "Hello, Assembly!";
    write(1, "native strcmp: ", 16);
    int result9 = strcmp(str7, str8);
    printf("%d\n", result9);
    write(1, "ft_strcmp: ", 11);
    int result10 = ft_strcmp(str7, str8);
    printf("%d\n", result10);


    return 0;
}

