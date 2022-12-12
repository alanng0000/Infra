#pragma once




#include "Local.h"





typedef struct
{
    Int MonthCountInYear;


    Int HourCountInDay;


    Int MinuteCountInHour;


    Int SecondCountInMinute;


    Int MillisecondCountInSecond;


    Int MillisecondCountInMinute;


    Int MillisecondCountInHour;


    Int MillisecondCountInDay;



    Int* DayCountInMonthArray;



    Int* DayCountUpToMonthArray;



    Int ArrayIndex;



    Int DayCountInYear;



    Int FourHundredYearsDayCount;



    Int OneHundredYearsDayCount;



    Int FourYearsDayCount;



} Constants;





Bool Constants_InitDayCountInMonthArray(Constants* this);



Bool Constants_AddDayCountInMonth(Constants* this, Int dayCount);




Bool Constants_InitDayCountUpToMonthArray(Constants* this);





Int Constants_DayCountInOneYear(Constants* this);