#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
	if ((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)) return true;
	return false;
}


int R(int y, int m) {
	return y % m;
}


int get_days(int year, int month, int day) {
	int result_days = day;

	// No break to let it cascade down
	switch (month - 1) {
		case 12:
			result_days += 31;
		case 11:
			result_days += 30;
		case 10:
			result_days += 31;
		case 9:
			result_days += 30;
		case 8:
			result_days += 31;
		case 7:
			result_days += 31;
		case 6:
			result_days += 30;
		case 5:
			result_days += 31;
		case 4:
			result_days += 30;
		case 3:
			result_days += 31;
		case 2:
			if (is_leap_year(year)) result_days += 29;
			else result_days += 28;
		case 1:
			result_days += 31;
	}
	return result_days;
}


char* get_day_of_week(int jan_1, int days) {
	int day = (days + jan_1 - 1) % 7;
	char* week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return week[day];
}


char* get_ordinal_postfix(int day) {
    int index = day%10;
    int i = (index < 4) ? index : 4;
    char* ordinal[5] = {"th", "st", "nd", "rd", "th"};
    return ordinal[index];
}


int main() {
	// printf("Input Fromat: Y M D\n");
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);
	int jan_1 = R(1+5 * R(year - 1, 4) + 4 * R(year - 1, 100) + 6 * R(year - 1, 400), 7);
	int days = get_days(year, month, day);
	// int day_of_week = get_day_of_week(jan_1, days);
// 	int day_of_week = (days + jan_1 - 1) % 7;
	printf("%s, %d%s day of the year\n", get_day_of_week(jan_1, days), days, get_ordinal_postfix(days));

	return 0;
}
