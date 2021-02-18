#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

static void charAtATime(char *str);

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // long text by child
        charAtATime("output AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB from child\n");
    }
    else
    {
        // long text by parent
        charAtATime("output AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB from parent\n");
    }
}

static void charAtATime(char *str)
{
    char *ptr;
    int c;
    setbuf(stdout, NULL);

    // do one character at a time to see race condition
    // this is due to Round Robin Scheduling
    // letting child and parent compete for the calling process
    for (ptr = str; (c = *ptr++) != 0;)
    {
        putc(c, stdout);
    }
}
