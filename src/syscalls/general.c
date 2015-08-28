/// \file general.c
///
/// File which contains some general system calls which are used by newlibc and stdlibc++
///
/// \author Christian Groeling <ch.groeling@gmail.com>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>

/// The newlibc and stdlibc++ do need some basic functions which the user must supply.
/// Without these functions there are undefined symbols after linking. Most of
/// the listed functions make no sense in an embedded bare metal application, but
/// must be defined nonetheless.
///
/// \defgroup SystemCalls System calls



/// \brief Terminate process.
///
/// \param status User supplied argument to exit() call.
///
/// \return This function does not return.
/// \ingroup SystemCalls
void _exit(int status)
{
    while (1)
    {
    }
}

/// \brief Send a signal to a process or a group of processes.
///
/// \param pid Process id
/// \param sig The signal to be send.
///
/// \returns Upon successful completion, 0 is returned. Otherwise, −1 is returned and errno is set to indicate
///          the error.
/// \ingroup SystemCalls
int _kill(pid_t pid, int sig)
{
    return (-1); // Always return an error since we do not have any processes.
}

/// \brief The getpid() function returns the process ID of the calling process.
///
/// \returns The process id of the calling process
/// \ingroup SystemCalls
pid_t _getpid(void)
{
    return 0; // always return 0
}

#ifdef _UNUSED_
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

#endif
