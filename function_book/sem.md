## semaphore

semaphore는 



이번 프로젝트에서 허용된 semaphore 제어용 함수는 아래와 같다.

```c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
// link with -pthread

sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
int sem_close(sem_t *sem);
int sem_post(sem_t *sem);
int sem_wait(sem_t *sem);
int sem_unlink(const char *name);
```

## sem_open

```c
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
// link with -pthread

sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
```

## sem_close

```c
#include <semaphore.h>
// link with -pthread

int sem_close(sem_t *sem);
```


## sem_post

```c
#include <semaphore.h>
// link with -pthread

int sem_post(sem_t *sem);
```

## sem_wait

```c
#include <semaphore.h>

int sem_wait(sem_t *sem);
```

## sem_unlink

```c
#include <semaphore.h>

int sem_unlink(const char *name);
```