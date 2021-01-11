/**
 * Copyright (C) 2021 Liao Junxuan
 * 
 * This file is part of Wash.
 * 
 * Wash is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Wash is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Wash.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "global.h"
#include "builtin.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
#define INIT_BUFFER_SIZE 256 /*including '\0'*/
#define INIT_ARGV_MAX_SIZE 2 /*including NULL*/


char * getInput(char * buffer, int initMaxSize);

int printPrompt(void);

char ** parseCmd(char * command);

int executeCmd(char ** argv);



int main(void)
{
    char * buffer;
    while(1)
    {
        printPrompt();
        buffer = (char *) malloc(INIT_BUFFER_SIZE);
        buffer = getInput(buffer, INIT_BUFFER_SIZE);
        char ** argv;
        argv = parseCmd(buffer);
        executeCmd(argv);
        free(buffer);
        free(argv);
    }

    return 0;
}




/*
 * Get input from stdin.
 * Return a pointer to the string.
 */
char* getInput(char * buffer, int initMaxSize)
{
    int maxSize = initMaxSize;
    int currentSize = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) // terminates at EOF or '\n'
    {
        if (currentSize >= maxSize)
        {
            maxSize += initMaxSize; // expand the buffer
            buffer = (char *) realloc(buffer, maxSize);
            if (errno == ENOMEM)
                perror("Error:");
        }
        buffer[currentSize] = ch;
        currentSize++;
    }
    if (currentSize >= maxSize)
    {
        maxSize += 2; // expand the buffer
        buffer = (char *) realloc(buffer, maxSize);
        if (errno == ENOMEM)
            perror("Error:");
    }
    buffer[currentSize] = ' ';
    currentSize++;
    buffer[currentSize] = '\0';
    return buffer;
}


/*
 * Print the command prompt.
 */
int printPrompt(void)
{
    printf("$ ");
    return 0;
}


/*
 * Parse the string given.
 * Return an array of strings, ending with null.
 */
char ** parseCmd(char * command)
{
    int currentSize = 0;
    int maxSize = INIT_ARGV_MAX_SIZE;
    char ** arguments = (char **) malloc(INIT_ARGV_MAX_SIZE * (sizeof(char **)));
    int index = 0;
    int head = 0;
    bool isToken = false;
    while(command[index] != '\0')
    {
        if(isspace(command[index]))
        {
            if(isToken == false)
            {
            }
            else
            {
                command[index] = '\0';
                isToken = false;
                if (currentSize >= maxSize)
                {
                    maxSize += INIT_ARGV_MAX_SIZE;
                    arguments = (char **) realloc(arguments, maxSize * (sizeof(char **)));
                }
                arguments[currentSize] = &command[head];
                printf("Token %d: %s\n", currentSize, arguments[currentSize]);
                currentSize++;
            }
        }
        else
        {
            if(isToken == false)
            {
                isToken = true;
                head = index;
            }
            else
            {
            }
        }
        index++;
    }
    if (currentSize >= maxSize)
    {
        maxSize++;
        arguments = (char **) realloc(arguments, maxSize * (sizeof(char **)));
    }
    arguments[currentSize] = NULL;
    return arguments;
}

/*
 * Execute the command given
 */
int executeCmd(char ** argv)
{
    int tmpErrno = errno; // Store original value of errno.
    pid_t pid;
    int status;
    // got 'exit' implemented first
    if (argv[0] == NULL)
        return 0;
    if (!executeBuiltIns(argv)) // Successfully called the built-in utilities
        return 0;
    pid = fork();
    if(pid == 0) // This is what the child process does.
    {
        if(execvp(argv[0], argv))
        {
            perror("wash"); // if the exec() functions return, it failed.
            exit(EXIT_FAILURE); // Have to manually exit this process since the exec() returns.
        }
    }
    else // This is what the parent process does.
    {
        wait(&status);
        errno = tmpErrno;
        // printf("wash: exit status: %d\n", status);
    }
    return 0;
}
#pragma clang diagnostic pop