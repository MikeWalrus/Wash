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
#include <string.h>

#define BUILTIN_TOTAL_COUNT 2

/**
 * Execute the built-in utilities.
 * @param argv Arguments of the command ending with NULL.
 * @return 0 on successful calls, 1 if no match is found.
 */
int executeBuiltIns(char ** argv)
{
    BuiltInUtil builtInArray[] = {{"exit", builtin_exit},{"cd", builtin_cd}};
    for(int i = 0; i < BUILTIN_TOTAL_COUNT; i++)
    {
        if(!strcmp(argv[0], builtInArray[i].name))
        {
            (*builtInArray[i].func)(argv);
            return 0;
        }
    }
    return 1;
}
/**
 * Exit the shell.
 * @param argv arguments of the command ending with NULL
 * @return
 */
int builtin_exit(char * argv[])
{
    exit(0);
    return 1;
}

int builtin_cd(char * argv[])
{
    chdir(argv[1]);
    return 0;
}