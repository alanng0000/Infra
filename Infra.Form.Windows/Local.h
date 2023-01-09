#pragma once



#include "Public.h"







Bool Time_LeapYear(Int year);




Int Time_DayCountUpToYear(Int year);




Int Time_DayCountInMonth(Int month, Bool leapYear);




Int Time_DayCountUpToMonth(Int month, Bool leapYear);




Int Time_DayCountInYears(Int yearCount, Int dayCountInYear);





Int Time_TickCount(Int year, Int month, Int day, Int hour, Int minute, Int second, Int millisecond);





Bool Time_ToDate(Int tickCount, Int* year, Int* month, Int* day, Int* hour, Int* min, Int* sec, Int* millisec);






Object Draw_New();




Bool Draw_Delete(Object o);




Bool Draw_Init(Object this);




Bool Draw_Final(Object this);





Int Draw_GetHandle(Object this);




Bool Draw_SetHandle(Object this, Int value);







Object Constants_New();




Bool Constants_Delete(Object o);




Bool Constants_Init(Object this);



Bool Constants_Final(Object this);




Int Constants_MonthCountInYear(Object this);



Int Constants_DayCountInMonth(Object this, Int month);



Int Constants_HourCountInDay(Object this);



Int Constants_MinuteCountInHour(Object this);



Int Constants_SecondCountInMinute(Object this);



Int Constants_MillisecondCountInSecond(Object this);



Int Constants_MillisecondCountInMinute(Object this);



Int Constants_MillisecondCountInHour(Object this);



Int Constants_MillisecondCountInDay(Object this);




Int Constants_DayCountUpToMonth(Object this, Int month);




Int Constants_DayCountInYear(Object this);





Int Constants_FourHundredYearsDayCount(Object this);



Int Constants_OneHundredYearsDayCount(Object this);



Int Constants_FourYearsDayCount(Object this);






Object Global_Constants(Object this);





Object Infra_Form_Global();