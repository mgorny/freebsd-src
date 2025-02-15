/*-
 * SPDX-License-Identifier: CC0-1.0
 *
 * Written in 2021 by Alfonso Sabato Siciliano.
 * To the extent possible under law, the author has dedicated all copyright
 * and related and neighboring rights to this software to the public domain
 * worldwide. This software is distributed without any warranty, see:
 *   <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#include <stdio.h>
#include <string.h>

#include <bsddialog.h>

int main()
{
	int input;
	struct bsddialog_conf conf;

	/* Configuration */
	bsddialog_initconf(&conf);
	conf.title = "msgbox";

	/* Run BSDDialog */
	if (bsddialog_init() == BSDDIALOG_ERROR) {
		printf("Error: %s\n", bsddialog_geterror());
		return -1;
	}
	input = bsddialog_msgbox(&conf, "Example", 7, 20);
	bsddialog_end();

	/* User Input */
	printf("User input: ");
	switch (input) {
	case BSDDIALOG_ERROR: printf("Error %s\n", bsddialog_geterror()); break;
	case BSDDIALOG_YESOK: printf("OK\n");  break;
	case BSDDIALOG_ESC:   printf("ESC\n"); break;
	}

	return input;
}
