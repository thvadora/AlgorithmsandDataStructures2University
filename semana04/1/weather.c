#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "weather.h"

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

int min_temp_hist(tclimate(array)){
	int min_temp = array[0][january][0][temp_m];
	for (unsigned int year = 0; year < YEARS; year++){
		for (t_month month = january; month <= december; month++){
			for (unsigned int day = 0; day < DAYS; day++){
				min_temp = min(min_temp,array[year][month][day][temp_m]);
			}
		}
	}
return min_temp;
}

void the_maximum(tclimate(array),int output[YEARS]){
	int maxx = 0;
	for (unsigned int year = 0; year < YEARS; year++){
		maxx = array[year][january][0][temp_M];
		for (t_month month = january; month <= december; month++){
			for (unsigned int day = 0; day < DAYS; day++){
				maxx = max(maxx,array[year][month][day][temp_M]);
			}
		}
		output[year] = maxx;
	}
}

void precip_hist(tclimate(array),t_month output[YEARS]){
	int sum = 0,sum_max = 0;
	t_month candidate = january;
	for (unsigned int year = 0; year < YEARS; year++){
		for (t_month month = january; month <= december; month++){
			for (unsigned int day = 0; day < DAYS; day++){
				sum = sum + array[year][month][day][precip];
			}
			if(sum_max <= sum){
				candidate = month;
				sum_max = sum;
			}
			sum = 0;
		}
		output[year] = candidate;
		sum_max = 0; 
	}
}

