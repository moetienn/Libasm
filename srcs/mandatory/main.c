#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Declare the Assembly function
extern size_t ft_strlen(const char *str);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main() {

    // Test ft_strlen

    printf("-------- FT_STRLEN TEST --------\n\n");

    size_t length = ft_strlen("Hello, Assembly!");
    printf("Length of '%s': %zu\n", "Hello, Assembly!", length);
    size_t length2 = strlen("Hello, Assembly!");
    printf("Length of '%s' using strlen: %zu\n", "Hello, Assembly!", length2);
    // Test ft_strlen with empty string
    size_t length3 = ft_strlen("");
    printf("Length of empty string: %zu\n", length3);
    size_t length4 = strlen("");
    printf("Length of empty string using strlen: %zu\n", length4);
    // Test ft_strlen with a long string
    const char *long_str = "This is a long string to test the ft_strlen function.";
    size_t length7 = ft_strlen(long_str);
    printf("Length of long string: %zu\n", length7);
    size_t length8 = strlen(long_str);
    printf("Length of long string using strlen: %zu\n", length8);
    // Test ft_strlen with a string containing special characters
    const char *special_str = "Hello, @#$%^&*()!-_+={}[]|:;\"'<>,.?/~`";
    size_t length9 = ft_strlen(special_str);
    printf("Length of string with special characters: %zu\n", length9);
    size_t length10 = strlen(special_str);
    printf("Length of string with special characters using strlen: %zu\n", length10);

    // Test ft_strlen with NULL pointer

    // ------ SegFault is the string is NULL ------

    // printf("Testing strlen with NULL pointer...\n");
    // const char *null_str = NULL;
    // size_t length6 = strlen(null_str);
    // printf("Length of NULL pointer using strlen: %zu\n", length6);
    // size_t length5 = ft_strlen(null_str);
    // printf("Length of NULL pointer: %zu\n", length5);

    // Test ft_write

    printf("\n-------- FT_WRITE TEST --------\n\n");

    const char *message = "Hello from Assembly!\n";
    ssize_t bytes_written = ft_write(1, message, 21);
    if (bytes_written == -1) {
        perror("ft_write");
    } else {
        printf("Bytes written: %zd\n", bytes_written);
    }
    
    // Test ft_write with NULL pointer
    const char *message2 = NULL;
    printf("Testing write with NULL pointer...\n");
    ssize_t bytes_written_test = write(1, message2, 10);
    if (bytes_written_test == -1) {
        perror("write with NULL pointer");
    } else {
        printf("Bytes written: %zd\n", bytes_written_test);
    }

    ssize_t bytes_written2 = ft_write(1, message2, 10);
    if (bytes_written2 == -1) {
        perror("ft_write with NULL pointer");
    } else {
        printf("Bytes written: %zd\n", bytes_written2);
    }

    return 0;
}

#include <stdio.h>

// Declare the Assembly function
