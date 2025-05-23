#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// Declare the Assembly function
extern size_t ft_strlen(const char *str);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strcpy(char *dest, const char *src);
extern char *ft_strdup(const char *s1);
extern ssize_t ft_read(int fd, void *buf, size_t count);

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

	printf("\n");

	// Test FT_STRCPY

	printf("-------- FT_STRCPY TEST --------\n\n");

	const char *src = "Hello, Assembly!";

	char dest[strlen(src) + 1]; // +1 for null terminator
	write(1, "native strcpy: ", 16);
	strcpy(dest, src);
	printf("%s\n", dest);
	char dest2[strlen(src) + 1]; // +1 for null terminator
	write(1, "ft_strcpy: ", 11);
	ft_strcpy(dest2, src);
	printf("%s\n", dest2);
	printf("\n");

	// Test ft_strcpy dest buffer too small DOESN'T COMPILE

	// write(1, "native strcpy: ", 16);
	// char small_dest[5];
	// strcpy(small_dest, src);
	// printf("%s\n", small_dest);
	// write(1, "ft_strcpy: ", 11);
	// char small_dest2[5];
	// ft_strcpy(small_dest2, src);
	// printf("%s\n", small_dest2);
	// printf("\n");

	// Test ft_strcpy with empty string
	const char *empty_src = "";
	char empty_dest[1]; // +1 for null terminator
	write(1, "native strcpy: ", 16);
	strcpy(empty_dest, empty_src);
	printf("%s\n", empty_dest);
	char empty_dest2[1]; // +1 for null terminator
	write(1, "ft_strcpy: ", 11);
	ft_strcpy(empty_dest2, empty_src);
	printf("%s\n", empty_dest2);
	printf("\n");

	// Test ft_strcpy with NULL pointer
	// ------ SegFault if the string is NULL ------
	// printf("\n");
	// char *null_src = NULL;
	// char *null_dest = NULL;
	// write(1, "native strcpy: ", 16);
	// strcpy(null_dest, null_src);
	// printf("%s\n", null_dest);
	// char *null_dest2 = NULL;
	// write(1, "ft_strcpy: ", 11);
	// ft_strcpy(null_dest2, null_src);
	// printf("%s\n", null_dest2);

	// Test ft_strcpy with different lengths
	const char *long_src = "This is a long string to test the ft_strcpy function.";
	char long_dest[strlen(long_src) + 1]; // +1 for null terminator
	write(1, "native strcpy: ", 16);
	strcpy(long_dest, long_src);
	printf("%s\n", long_dest);
	char long_dest2[strlen(long_src) + 1]; // +1 for null terminator
	write(1, "ft_strcpy: ", 11);
	ft_strcpy(long_dest2, long_src);
	printf("%s\n", long_dest2);
	printf("\n");

	// Test ft_strcpy with special characters
	const char *special_src = "Hello, @#$%^&*()!-_+={}[]|:;\"'<>,.?/~`";
	char special_dest[strlen(special_src) + 1]; // +1 for null terminator
	write(1, "native strcpy: ", 16);
	strcpy(special_dest, special_src);
	printf("%s\n", special_dest);
	char special_dest2[strlen(special_src) + 1]; // +1 for null terminator
	write(1, "ft_strcpy: ", 11);
	ft_strcpy(special_dest2, special_src);
	printf("%s\n", special_dest2);
	printf("\n");

	printf("-------- TEST FT_STRDUP --------\n\n");
	// Test ft_strdup
	const char *str = "Hello, Assembly!";
	char *dup_str = strdup(str);
	write(1, "native strdup: ", 16);
	printf("%s\n", dup_str);
	char *dup_str2 = ft_strdup(str);
	write(1, "ft_strdup: ", 11);
	printf("%s\n", dup_str2);
	free(dup_str);
	free(dup_str2);
	printf("\n");

	// Test ft_strdup with empty string
	const char *empty_str = "";
	char *dup_empty_str = strdup(empty_str);
	write(1, "native strdup: ", 16);
	printf("%s\n", dup_empty_str);
	char *dup_empty_str2 = ft_strdup(empty_str);
	write(1, "ft_strdup: ", 11);
	printf("%s\n", dup_empty_str2);
	free(dup_empty_str);
	free(dup_empty_str2);
	printf("\n");

	// Test ft_strdup with NULL pointer
	// ------ SegFault if the string is NULL ------
	// const char *null_str = NULL;
	// char *dup_null_str = strdup(null_str);
	// write(1, "native strdup: ", 16);
	// if (dup_null_str == NULL) {
	// 	perror("strdup");
	// } else {
	// 	printf("%s\n", dup_null_str);
	// }
	// char *dup_null_str2 = ft_strdup(null_str);
	// write(1, "ft_strdup: ", 11);
	// if (dup_null_str2 == NULL) {
	// 	perror("ft_strdup");
	// } else {
	// 	printf("%s\n", dup_null_str2);
	// }
	// printf("\n");

	// Test ft_strdup with different lengths
	const char *long_str2 = "This is a long string to test the ft_strdup function.";
	char *dup_long_str = strdup(long_str2);
	write(1, "native strdup: ", 16);
	printf("%s\n", dup_long_str);
	char *dup_long_str2 = ft_strdup(long_str2);
	write(1, "ft_strdup: ", 11);
	printf("%s\n", dup_long_str2);
	free(dup_long_str);
	free(dup_long_str2);
	printf("\n");

	// Test ft_strdup with special characters
	const char *special_str2 = "Hello, @#$%^&*()!-_+={}[]|:;\"'<>,.?/~`";
	char *dup_special_str = strdup(special_str2);
	write(1, "native strdup: ", 16);
	printf("%s\n", dup_special_str);
	char *dup_special_str2 = ft_strdup(special_str2);
	write(1, "ft_strdup: ", 11);
	printf("%s\n", dup_special_str2);
	free(dup_special_str);
	free(dup_special_str2);
	printf("\n");

	printf("-------- FT_READ TEST --------\n\n");

	// Test ft_read
	printf("-- read from stdin --\n\n");
	char buffer[100];
	write(1, "native read: ", 14);
	ssize_t bytes_read_native = read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read_native == -1) {
		perror("read");
	} else {
		buffer[bytes_read_native] = '\0';
		write(1, "Bytes read: ", 12);
		write(1, buffer, bytes_read_native);
	}

	write(1, "\nft_read: ", 10);
	ssize_t bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1) {
		perror("ft_read");
	} else {
		buffer[bytes_read] = '\0';
		write(1, "Bytes read: ", 12);
		ft_write(1, buffer, bytes_read);
	}
	printf("\n");

	// Test ft_read with invalid file descriptor
	printf("-- read with invalid file descriptor --\n\n");
	ssize_t bytes_read_invalid_fd = ft_read(-1, buffer, sizeof(buffer) - 1);
	write(1, "native read :", 14);
	if (bytes_read_invalid_fd == -1)
		perror("");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, buffer, bytes_read_invalid_fd);
	}
	
	ssize_t bytes_read_invalid_fd2 = ft_read(-1, buffer, sizeof(buffer) - 1);
	write(1, "ft_read: ", 10);
	if (bytes_read_invalid_fd2 == -1)
		perror("");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, buffer, bytes_read_invalid_fd2);
	}
	printf("\n");

	// Test ft_read with large file descriptor
	printf("-- read with large file descriptor --\n\n");
	write(1, "native read: ", 14);
	ssize_t bytes_read_large_fd = ft_read(9999, buffer, sizeof(buffer) - 1);
	if (bytes_read_large_fd == -1)
		perror("");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, buffer, bytes_read_large_fd);
	}
	write(1, "ft_read: ", 10);
	ssize_t bytes_read_large_fd2 = ft_read(9999, buffer, sizeof(buffer) - 1);
	if (bytes_read_large_fd2 == -1)
		perror("");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, buffer, bytes_read_large_fd2);
	}
	printf("\n");

	// Test ft_read with zero bytes to read
	printf("-- read with zero bytes to read --\n\n");
	write(1, "native read: ", 14);
	ssize_t bytes_read_zero = ft_read(0, buffer, 0);
	if (bytes_read_zero == -1)
		perror("");
	else
	{
		write(1, "\nBytes read: ", 13);
		write(1, buffer, bytes_read_zero);
	}
	write(1, "\nft_read: ", 11);
	ssize_t bytes_read_zero2 = ft_read(0, buffer, 0);
	if (bytes_read_zero2 == -1)
		perror("");
	else
	{
		write(1, "\nBytes read: ", 13);
		write(1, buffer, bytes_read_zero2);
	}
	printf("\n");

	// Test ft_read with NULL pointer
	printf("\n-- read with NULL pointer --\n\n");
	char *null_buffer = NULL;
	write(1, "native read: ", 14);
	ssize_t bytes_read_null = read(0, null_buffer, sizeof(buffer) - 1);
	if (bytes_read_null == -1)
		perror("Error ");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, null_buffer, bytes_read_null);
	}

	write(1, "\nft_read: ", 10);
	ssize_t bytes_read_null2 = ft_read(0, null_buffer, sizeof(buffer) - 1);
	if (bytes_read_null2 == -1)
		perror("Error ");
	else
	{
		write(1, "Bytes read: ", 12);
		write(1, null_buffer, bytes_read_null2);
	}

	// Test ft_read with a file
	printf("\n-- read from a file that doesnt exist --\n\n");
	write(1, "native read: ", 14);
	int fd = open("teste.txt", O_RDONLY);
	if (fd == -1) {
		perror("open");
	}
	ssize_t bytes_read_file = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read_file == -1) {
		perror("read");
		close(fd);
	}
	buffer[bytes_read_file] = '\0';
	write(1, buffer, bytes_read_file);
	close(fd);

	write(1, "\nft_read: ", 10);
	int fd2 = open("teste.txt", O_RDONLY);
	if (fd2 == -1) {
		perror("open");
	}
	ssize_t bytes_read_file2 = ft_read(fd2, buffer, sizeof(buffer) - 1);
	if (bytes_read_file2 == -1) {
		perror("ft_read");
		close(fd2);
	}
	buffer[bytes_read_file2] = '\0';
	write(1, buffer, bytes_read_file2);
	close(fd2);
	printf("\n");

	// Test ft_read with a file that exist
	printf("\n-- read from a file that exist --\n\n");
	write(1, "native read: ", 14);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		perror("open");
	}
	ssize_t bytes_read_file3 = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read_file3 == -1) {
		perror("read");
		close(fd);
	}
	buffer[bytes_read_file3] = '\0';
	write(1, buffer, bytes_read_file3);
	close(fd);
	write(1, "\nft_read: ", 10);
	fd2 = open("test.txt", O_RDONLY);
	if (fd2 == -1) {
		perror("open");
	}
	ssize_t bytes_read_file4 = ft_read(fd2, buffer, sizeof(buffer) - 1);
	if (bytes_read_file4 == -1) {
		perror("ft_read");
		close(fd2);
	}
	buffer[bytes_read_file4] = '\0';
	write(1, buffer, bytes_read_file4);
	close(fd2);
	printf("\n");

	return 0;
}

