/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2021 Alfonso Sabato Siciliano
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _LIBBSDDIALOG_THEME_H_
#define _LIBBSDDIALOG_THEME_H_

enum bsddialog_color {
	BSDDIALOG_BLACK = 0,
	BSDDIALOG_RED,
	BSDDIALOG_GREEN,
	BSDDIALOG_YELLOW,
	BSDDIALOG_BLUE,
	BSDDIALOG_MAGENTA,
	BSDDIALOG_CYAN,
	BSDDIALOG_WHITE,
};

/* f_ for focus/selected/active/current element */
struct bsddialog_theme {
	struct {
		int color;
	} terminal;

	struct {
		int color;
		unsigned int h;
		unsigned int w;
	} shadow;

	struct {
		int  color;
		bool delimtitle;
		int  titlecolor;
		int  lineraisecolor;
		int  linelowercolor;
		int  bottomtitlecolor;
	} widget;

	struct {
		unsigned int hmargin;
	} text;

	struct {
		int arrowcolor;
		int f_namecolor;
		int namecolor;
		int f_desccolor;
		int desccolor;
		int namesepcolor;
		int descsepcolor;
	} menu;

	struct {
		int f_fieldcolor;
		int fieldcolor;
		int readonlycolor;
	} form;

	struct {
		int f_color;
		int color;
	} bar;

	struct {
		unsigned int space;
		int leftch;
		int rightch;
		int delimcolor;
		int f_delimcolor;
		int color;
		int f_color;
		int shortcutcolor;
		int f_shortcutcolor;
	} button;
};

enum bsddialog_default_theme {
	BSDDIALOG_THEME_BLACKWHITE,
	BSDDIALOG_THEME_BSDDIALOG,
	BSDDIALOG_THEME_DEFAULT,
	BSDDIALOG_THEME_DIALOG,
};

int
bsddialog_color(enum bsddialog_color background,
    enum bsddialog_color foreground);
struct bsddialog_theme bsddialog_get_theme(void);
void bsddialog_set_theme(struct bsddialog_theme theme);
int bsddialog_set_default_theme(enum bsddialog_default_theme theme);

#endif
