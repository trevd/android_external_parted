#ifndef _CONFIG_H_
#define _CONFIG_H_

/* hand-crafted config.h for Android builds */

#define HAVE_TIME_H
#define HAVE_SYS_STAT_H
#define HAVE_GETTIMEOFDAY
#define HAVE_STDARG_H
#define __timespec_defined
#define HAVE_ERRNO_H
#define HAVE_STRING_H
#define HAVE_LIMITS_H
#define HAVE_GETOPT_H
#define HAVE_FCNTL_H
#define HAVE_STDIO_H
#define HAVE_STDLIB_H
#define HAVE_CTYPE_H
#define HAVE_LOCALE_H
#define HAVE_FCNTL_H
#define HAVE_WCHAR_H
#define HAVE_DECL_STRERROR_R 1
#define HAVE_DECL___FPENDING 0

#define SIZEOF_OFF_T 4


#define S_IREAD     S_IRUSR
#define S_IWRITE    S_IWUSR
#define S_IEXEC     S_IXUSR

#ifdef HAVE_LITTLE_ENDIAN
#define WORDS_LITTLEENDIAN 1
#else
#define WORDS_BIGENDIAN 1
#endif

#include <stdio.h>
#include <malloc.h>

#define _GL_UNUSED      __attribute__((__unused__))
#define _GL_ATTRIBUTE_CONST __attribute__((__const__))
#define _GL_ATTRIBUTE_PURE  __attribute__((__pure__))
#define restrict __restrict
#define _Noreturn       __attribute__((__noreturn__))
#define PACKAGE_URL "http://www.gnu.org/software/parted/"
#define PACKAGE_STRING "GNU parted 3.1"
#define PACKAGE_NAME "GNU parted"
#define PACKAGE_BUGREPORT "bug-parted@gnu.org"
#define PACKAGE "parted"
#define VERSION "3.1-android"

#define PENDING_OUTPUT_N_BYTES fp->_p - fp->_bf._base


static inline int posix_memalign(void **memptr, size_t alignment, size_t size)
{
    *memptr = memalign(alignment, size);
    return *memptr == NULL;
}
#define llseek lseek64
#define getwd(buf) getcwd(buf, PATH_MAX)

/* scsi.h junk */
#define INQUIRY                 0x12
#define SCSI_IOCTL_GET_IDLUN    0x5382

#endif // _CONFIG_H_
