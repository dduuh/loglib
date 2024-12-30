#ifndef LOGLIB_H
#define LOGLIB_H

#include <stdio.h>
#include <time.h>

FILE* filelog;
time_t curr_time;
struct tm* localtim;
int hours, minutes, seconds; // Today
int year, month, day; // Year

void log_init(const char* filename);
void log_info(const char* message);
void log_warning(const char* message);
void log_error(const char* message);
void log_close(void);

void
log_init(const char* filename)
{
	filelog = fopen(filename, "a");
	if (filelog == NULL) {
		fprintf(stderr, "Error appending into %s!", filename);
		return;
	}
}

void
log_info(const char* message)
{
	time(&curr_time);
	localtim = localtime(&curr_time);

	hours = localtim->tm_hour;
	minutes = localtim->tm_min;
	seconds = localtim->tm_sec;

	year = localtim->tm_year + 1900;
	month = localtim->tm_mon + 1;
	day = localtim->tm_mday;

	fprintf(stdout, "%d:%d:%d %d:%d:%d \033[32mINFO\033[0m: %s\n", year, month, day, hours, minutes, seconds, message);
	fprintf(filelog, "%d:%d:%d %d:%d:%d INFO: %s\n", year, month, day, hours, minutes, seconds, message);
}

void
log_warning(const char* message)
{
	time(&curr_time);
	localtim = localtime(&curr_time);

	hours = localtim->tm_hour;
	minutes = localtim->tm_min;
	seconds = localtim->tm_sec;

	year = localtim->tm_year + 1900;
	month = localtim->tm_mon + 1;
	day = localtim->tm_mday;

	fprintf(stdout, "%d:%d:%d %d:%d:%d \033[33mWARNING\033[0m: %s\n", year, month, day, hours, minutes, seconds, message);
	fprintf(filelog, "%d:%d:%d %d:%d:%d WARNING: %s\n", year, month, day, hours, minutes, seconds, message);
}

void
log_error(const char* message)
{
	time(&curr_time);
	localtim = localtime(&curr_time);

	hours = localtim->tm_hour;
	minutes = localtim->tm_min;
	seconds = localtim->tm_sec;

	year = localtim->tm_year + 1900;
	month = localtim->tm_mon + 1;
	day = localtim->tm_mday;

	fprintf(stdout, "%d:%d:%d %d:%d:%d \033[31mERROR\033[0m: %s\n", year, month, day, hours, minutes, seconds, message);
	fprintf(filelog, "%d:%d:%d %d:%d:%d ERROR: %s\n", year, month, day, hours, minutes, seconds, message);
}

inline void
log_close(void)
{
	fclose(filelog);
}

#endif