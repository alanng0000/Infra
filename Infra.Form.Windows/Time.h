#pragma once





#include "WindowsLocal.h"



#include "Local.h"





typedef struct
{
    Int Tick;

} Time;






Int Time_DayCountFromOrigin(Int year, Int month, Int day);




Int Time_LeapYearCountUpToYear(Int year);




Int Time_DayCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain);






Int Time_YearCountFromDayCount(Int dayCount, Int* dayRemain);




Int Time_MonthCountFromDayCount(Int dayCount, Int* dayRemain);




Int Time_HourCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain);




Int Time_MinuteCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain);




Int Time_SecondCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain);
