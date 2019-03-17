#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	DIR				*dp;
	struct dirent	*dirp;

	if (argc != 2) {
		perror("usage: ls directory_name");
		abort();
	}

	if ((dp = opendir(argv[1])) == NULL) {
		char buf[32];
		sprintf(buf, "can't open %s", argv[1]);
		perror(buf);
		abort();
	}

	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}