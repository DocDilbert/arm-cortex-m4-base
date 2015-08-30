/// \file general.c
///
/// File which contains some general system calls which are used by newlibc and stdlibc++
///
/// \author Christian Groeling <ch.groeling@gmail.com>
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include "mcu.h"

// A pointer to a list of environment variables and their values.
// For a minimal environment, this empty list is adequate:
char *__env[1] = { 0 }; ///< A pointer to a list of environment variables and their values.
char **environ = __env; ///< A pointer to a list of environment variables and their values.

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
    return 1; // always return 1
}

/// Close a file
/// \ingroup SystemCalls
int _close(int fildes)
{
    return -1;
}

/// Set position in a file.
/// \ingroup SystemCalls
off_t _lseek(int fildes, off_t offset, int whence)
{
    return 0;
}

/// Read from a file
/// \ingroup SystemCalls
ssize_t _read(int fildes, void *buf, size_t nbyte)
{
    return ((ssize_t) -1);
}

/// Status of an open file. For consistency with other minimal implementations in these examples,
/// all files are regarded as character special devices.
///
/// \ingroup SystemCalls
int _fstat(int fildes, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

/// Status of a file (by name)
///
/// \ingroup SystemCalls
int _stat(const char *filepath, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

/// Timing information for current process
///
/// \ingroup SystemCalls
clock_t _times(struct tms *buf)
{
    return -1;
}

/// Remove a file's directory entry
///
/// \ingroup SystemCalls
int _unlink(char *name)
{
    errno = ENOENT;
    return -1;
}

/// Establish a new name for an existing file
///
/// \ingroup SystemCalls
int _link(const char *old, const char *new)
{
    errno = EMLINK;
    return -1;
}

/// Wait for a child process
///
/// \ingroup SystemCalls
int _wait(int *status)
{
    errno = ECHILD;
    return -1;
}

/// Query whether output stream is a terminal
///
/// \ingroup SystemCalls
int _isatty(int fildes)
{
    switch (fildes)
    {
        case STDOUT_FILENO:
        case STDERR_FILENO:
        case STDIN_FILENO:
            return 1;
        default:
            //errno = ENOTTY;
            errno = EBADF;
            return 0;
    }

}
/// Write a character to a file.
///
/// `libc' subroutines will use this system routine for output to all files, including stdout
/// Returns -1 on error or number of bytes sent.
///
/// \ingroup SystemCalls
ssize_t _write(int filedes, const void *buf, size_t nbytes)
{
    int n;
    for (n = 0; n < nbytes; n++)
    {
        ITM_SendChar(((char*) buf)[n]);
    }
    return nbytes;
}

