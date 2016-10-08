#include	"unpipc.h"

void
my_lock(int fd)
{
	struct flock	lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;				/* write lock entire file */

	Fcntl(fd, F_SETLKW, &lock); /* we specify a command of F_SETLKW when obtaining the lock, because if the lock is not available, we want to block until it is available */
}

void
my_unlock(int fd)
{
	struct flock	lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;				/* unlock entire file */

	Fcntl(fd, F_SETLK, &lock);
}
