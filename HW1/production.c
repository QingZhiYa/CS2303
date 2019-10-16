/*
 * production.c
 *
 *  Created on: Nov 3, 2018
 *      Author: student
 *      @author Yaru Gong
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>

/** Your production code goes in this function.
 *
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return true if Program was able to print a calendar.
 *         false if User entered bad input.
 */

bool production(int argc, char* argv[])
{

	//make the print easier
	static const char *printMonth[] = {
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"};
	static const char *printDay[] = {"  1", "  2", "  3", "  4", "  5", "  6", "  7", "  8",
			"  9", " 10", " 11", " 12", " 13", " 14", " 15", " 16", " 17", " 18", " 19", " 20",
			" 21", " 22", " 23", " 24", " 25", " 26", " 27", " 28", " 29", " 30", " 31"};
	bool results = false;
	bool done = false;
	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");
	if(argc < 2){
		//when there is no year number on the command line, ask the user
		puts("Enter a year");
		scanf("%d",&year);
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
		results = true;
	}else{
		//when there is a year number on the command line
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	if(!done){
		//print month name
		//print the days of the week text
		//print the weeks
		for(int month = 0; month < 12; month++){
			printf("%s", printMonth[month]);
			puts("\nSun  Mon  Tue  Wed  Thu  Fri  Sat");
			//when the first day of the month is not Sunday, consider about indentation
			if(calculate_day_of_week(1, month, year) != 0){
				printf("   ");
				int indent = 1;
				while(calculate_day_of_week(1, month, year) != indent++){
					printf("     ");
				}
			}
			//print each day
			for(int day = 1; day <= calculate_days_in_month(year,month); day++){
				if(calculate_day_of_week(day, month, year) == 0){
					printf("%s", printDay[day-1]);
				}else if(calculate_day_of_week(day, month, year) <= 5){
					printf("  %s", printDay[day-1]);
				}else{
					printf("  %s\n", printDay[day-1]);
				}
			}
			//make it formatted
			if(calculate_day_of_week(calculate_days_in_month(year,month),month,year) != 6)
				printf("\n");
		}

	}

	if(!done){
		results=true;
	}
	return results;
}

/** Test if a given year is a leap year or not.
 * @param year The year we are testing
 * @return 1 if it is a valid leap year.
 *         0 if a valid year, but not a leap year.
 *        -1 if not a valid year (i.e. before the calendar rule changed in 1752).
 */
int is_leap_year(int year){
	bool done = false;
	//when the year number is less than 1752
	if(year < 1752)
		return -1;
	else if(year % 400 == 0 ||
			(year % 4 == 0 && year % 100 != 0)){
		return 1;
	}
	else{
		return 0;
	}
}

/** Calculates how many days are in a given month for a given year.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return Return an integer for the number of days in the month. Return -1 for
 * 		   any invalid input (including if the year was < 1752).
 */
int calculate_days_in_month(int year, int month){
	static const int dayTab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	bool done = false;
	int isLeap = is_leap_year(year);
	//invalid input
	if(isLeap == -1 || month < 0 || month > 11){
		return -1;
	}else{
		return dayTab[isLeap][month];
	}
}

/** Determines what day of the week a particular date falls on.
 * @param day Day of the month, counting from 1.
 * @param month Range 0 through 11, where January = 0.
 * @param year The year.
 * @return -1 for invalid input (e.g., year < 1752, month out of range,
 *            day < 1 or > appropriate for that month & year
 *         0 through 6, where Sunday = 0.
 *
 */
int calculate_day_of_week(int day, //first day of month is 1
		int month, //uses 0 for January
		int year){
	bool done = false;
	//invalid input gets a -1 answer
	if(year < 1752 || month > 11 || month < 0 ||
			day > calculate_days_in_month(year, month)){
		return -1;
	}else{
		if(month == 0 || month == 1){
			year -= 1;
		}
		int y = year % 100;
		int c = year / 100 % 100;
		int m = month > 1? month - 1 : month + 11;
		int w = (int)(day + floor(2.6 * m - 0.2) + y + floor(y / 4) + floor(c / 4) - 2 * c) % 7;
		//when the answer is negative, make it positive
		if(w >= 0)
			return w;
		else
			return w+7;
	}
}
