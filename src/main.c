// nocommand: a tool to find out what happens when you execl nothing
// Copyright (C) 2016 Evan Klitzke <evan@eklitzke.org>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int ret = execl("you-fucking-hacker-news-neolibs", "We", "Out", "Here", NULL);
  int errno_copy = errno;
  assert(ret == -1);
  printf("errno = %d\n", errno_copy);
  errno = errno_copy;  // ??
  perror("execl()");
  return 0;
}
