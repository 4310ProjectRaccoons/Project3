/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Stop executing for some time");
    parser().registerPositional("SECONDS", "Stop executing for the given number of seconds");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    int* status = 0;

    // Wait now

    if (waitpid(atoi(arguments().get("SECONDS")), status, 0) != atoi(arguments().get("SECONDS")))

    {

        ERROR("failed to wait: " << strerror(errno));

        return IOError;

    }

    // Done
    return Success;
}
