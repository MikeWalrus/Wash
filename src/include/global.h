// Copyright (C) 2021 Liao Junxuan
// 
// This file is part of Wash.
// 
// Wash is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Wash is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Wash.  If not, see <http://www.gnu.org/licenses/>.


#ifndef WASH_GLOBAL_H
#define WASH_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INIT_BUFFER_SIZE 256 /*including '\0'*/
#define INIT_ARGV_MAX_SIZE 2 /*including NULL*/

extern int errno;

typedef struct BuiltInUtils
{
    char * name;
    int (* func)(char *[]);
} BuiltInUtil;

#endif //WASH_GLOBAL_H
