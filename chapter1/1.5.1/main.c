#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 4096

int main()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n) {
			perror("write");
			abort();
		}
	}

	if (n < 0) {
		perror("read");
		abort();
	}

	exit(0);
}