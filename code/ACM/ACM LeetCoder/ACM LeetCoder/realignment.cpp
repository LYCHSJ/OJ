#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

/*time_t convert_string_to_time_t(std::string & time_string)
{
	struct tm tm1;
	time_t time1;
	sscanf(time_string.c_str(), "%d/%d/%d %d:%d:%d",
		&(tm1.tm_year),
		&(tm1.tm_mon),
		&(tm1.tm_mday),
		&(tm1.tm_hour),
		&(tm1.tm_min),
		&(tm1.tm_sec));
	tm1.tm_year -= 1900;
	tm1.tm_mon--;
	tm1.tm_isdst = -1;
	time1 = mktime(&tm1);

	return time1;
}*/
using namespace std;
time_t convert_string_to_time_t(std::string & time_string)
{
	struct tm tm1;  
    time_t time1;  
    int i = sscanf_s(time_string.c_str(), "%d:%d:%d" ,
               
                &(tm1.tm_hour),  
                &(tm1.tm_min),  
                &(tm1.tm_sec),  
                &(tm1.tm_wday),  
                &(tm1.tm_yday));  
    tm1.tm_year = 2000;   
    tm1.tm_mon = 12;   
    tm1.tm_mday = 1;
    tm1.tm_year -= 1900;  
    tm1.tm_mon --;  
    tm1.tm_isdst=-1;  
    time1 = mktime(&tm1);  
	return time1;
}

int main(int argc, char *argv[])
{
	std::string date_string1("18:08:01");
	time_t tmp_time1;
	tmp_time1 = convert_string_to_time_t(date_string1);

	std::string date_string2("19:00:00");
	time_t tmp_time2;
	tmp_time2 = convert_string_to_time_t(date_string2);
	if (tmp_time1 < tmp_time2) {
		printf("¿ÉÓÃ£¬1¡¶2");
	}
	printf("The pause used %f seconds.\n", difftime(tmp_time2, tmp_time1));
}
