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

	
	// struct dirent
	// {
	// #ifndef __USE_FILE_OFFSET64
	//	__ino_t d_ino;
	//	__off_t d_off;
	// #else
	//	__ino64_t d_ino;
	//	__off64_t d_off;
	// #endif
	//	unsigned short int d_reclen;
	//	unsigned char d_type;
	//	char d_name[256];		/* We must not include limits.h! */
	// };
	

	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\td_ino=%d d_off=%d d_reclen=%d d_type=%d\n", 
			   dirp->d_name, dirp->d_ino, dirp->d_off, dirp->d_reclen, dirp->d_type);
	}

	closedir(dp);
	exit(0);
}