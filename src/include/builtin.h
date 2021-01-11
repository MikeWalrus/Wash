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



#ifndef WASH_BUILTIN_H
#define WASH_BUILTIN_H


int executeBuiltIns(char ** argv);

int builtin_exit(char * argv[]);

int builtin_cd(char * argv[]);

#endif //WASH_BUILTIN_H
