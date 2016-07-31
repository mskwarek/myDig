/* config.h.  Generated by configure.  */
/* #undef _SOCKADDR_LEN */
#define HAVE_FCNTL_H 1
#define HAVE_PATHS_H 1
/* #undef HAVE_SYS_TIMERS_H */
/* #undef SYS_CDEFS_H */
/* #undef _POSIX_PTHREAD_SEMANTICS */
/* #undef POSIX_GETPWUID_R */
/* #undef POSIX_GETPWNAM_R */
/* #undef POSIX_GETGRGID_R */
/* #undef POSIX_GETGRNAM_R */

#define NEED_SETGROUPENT 1
/* #undef NEED_GETGROUPLIST */

/* define if prototype for getgrnam_r() is required */
/* #undef NEED_GETGRNAM_R */
/* #undef NEED_GETGRGID_R */
/* #undef NEED_GETGRENT_R */
#define NEED_SETGRENT_R 1
#define NEED_ENDGRENT_R 1

#define NEED_INNETGR_R 1
/* #undef NEED_SETNETGRENT_R */
#define NEED_ENDNETGRENT_R 1

/* #undef NEED_GETPWNAM_R */
/* #undef NEED_GETPWUID_R */
#define NEED_SETPWENT_R 1
#define NEED_SETPASSENT_R 1
#define NEED_SETPWENT_R 1
/* #undef NEED_GETPWENT_R */
#define NEED_ENDPWENT_R 1

#define NEED_SETPASSENT 1

/* #undef HAS_PW_CLASS */

/* Shut up warnings about sputaux in stdio.h on BSD/OS pre-4.1 */
/* #undef SHUTUP_SPUTAUX */
#ifdef SHUTUP_SPUTAUX
struct __sFILE;
extern __inline int __sputaux(int _c, struct __sFILE *_p);
#endif
/* #undef BROKEN_IN6ADDR_INIT_MACROS */
/* #undef HAVE_STRLCAT */
