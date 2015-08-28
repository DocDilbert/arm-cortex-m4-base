/// \file syscalls.c
///
/// File which contains all necessary stdlib system calls.
///
/// \author Christian Groeling <ch.groeling@gmail.com>

/// \brief System call which called by the exit() function. 
/// \retval arg [in] The argument which the user supplied to the exit() call.
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>

void _exit(int arg)
{
    while (1)
    {
    }
}

int _kill(pid_t pid, int sig)
{
    return (-1);
}

pid_t _getpid(void)
{
    return 0;
}

int _close(int fildes)
{
    return -1;
}

off_t _lseek(int fildes, off_t offset, int whence)
{
    return ((off_t) -1);
}

ssize_t _read(int fildes, void *buf, size_t nbyte)
{
    return ((ssize_t) -1);
}

ssize_t _write(int fildes, const void *buf, size_t nbyte)
{
    return ((ssize_t) -1);
}

int _fstat(int fildes, struct stat *buf)
{
    return (-1);
}

int _isatty(int fildes)
{
    return (0);
}
