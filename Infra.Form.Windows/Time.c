#include "Time.h"



InfraClassNew(Time)




Bool Time_Init(Object this)
{
    return true;
}



Bool Time_Final(Object this)
{
    return true;
}




Int Time_GetTick(Object this)
{
    Time* m = CastPointer(this);


    return m->Tick;
}




Bool Time_SetTick(Object this, Int value)
{
    Time* m = CastPointer(this);


    m->Tick = value;


    return true;
}



Bool Time_AddTime(Object this, Object time)
{
    Time* m = CastPointer(this);


    Time* k = CastPointer(time);



    Int h = m->Tick;


    Int j = k->Tick;


    h = h + j;


    m->Tick = h;


    return true;
}




Bool Time_SubTime(Object this, Object time)
{
    Time* m = CastPointer(this);


    Time* k = CastPointer(time);



    Int h = m->Tick;


    Int j = k->Tick;



    Int d = 0;


    Bool b = (h < j);


    if (!b)
    {
        d = h - j;
    }


    h = d;
    


    m->Tick = h;


    return true;
}





Bool Time_Current(Object this)
{
    SYSTEMTIME u = { 0 };



    Windows_GetSystemTime(&u);






    Int year = u.wYear;

    year = year - 1;



    Int month = u.wMonth;

    month = month - 1;



    Int day = u.wDay;

    day = day - 1;



    Int hour = u.wHour;

    Int minute = u.wMinute;

    Int second = u.wSecond;

    Int millisecond = u.wMilliseconds;



    Int tickCount = Time_TickCount(year, month, day, hour, minute, second, millisecond);





    Time_SetTick(this, tickCount);



    return true;
}





Bool Time_Date(Object this, Object date)
{
    Time* m = CastPointer(this);



    Int tickCount = m->Tick;





    Int year = 0;


    Int month = 0;


    Int day = 0;


    Int hour = 0;


    Int min = 0;


    Int sec = 0;


    Int millisec = 0;




    Time_ToDate(tickCount, &year, &month, &day, &hour, &min, &sec, &millisec);




    Date_SetYear(date, year);


    Date_SetMonth(date, month);


    Date_SetDay(date, day);


    Date_SetHour(date, hour);


    Date_SetMin(date, min);


    Date_SetSec(date, sec);


    Date_SetMillisec(date, millisec);



    return true;
}





Int Time_TickCount(Int year, Int month, Int day, Int hour, Int min, Int sec, Int millisec)
{
    Int dayCount = Time_DayCountFromOrigin(year, month, day);





    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);




    Int millisecondCountInDay = Constants_MillisecondCountInDay(constants);



    Int millisecondCountInHour = Constants_MillisecondCountInHour(constants);



    Int millisecondCountInMinute = Constants_MillisecondCountInMinute(constants);



    Int millisecondCountInSecond = Constants_MillisecondCountInSecond(constants);


    




    Int k = 0;


    k = k + dayCount * millisecondCountInDay;


    k = k + hour * millisecondCountInHour;


    k = k + min * millisecondCountInMinute;


    k = k + sec * millisecondCountInSecond;


    k = k + millisec;



    Int tickCount = k;





    Int ret = tickCount;


    return ret;
}




Int Time_DayCountFromOrigin(Int year, Int month, Int day)
{   
    Int dayCountUpToYear = Time_DayCountUpToYear(year);



    Bool leapYear = Time_LeapYear(year);



    Int dayCountUpToMonth = Time_DayCountUpToMonth(month, leapYear);




    Int k = dayCountUpToYear + dayCountUpToMonth + day;



    Int ret = k;


    return ret;
}




Int Time_DayCountUpToYear(Int year)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);




    Int dayCountInYear = Constants_DayCountInYear(constants);



    Int leapYearCount = Time_LeapYearCountUpToYear(year);




    Int k = year * dayCountInYear;



    k = k + leapYearCount;



    Int ret = k;


    return ret;
}





Int Time_DayCountInMonth(Int month, Bool leapYear)
{
    Object global = Infra_Form_Global();



    Object constants = Global_Constants(global);



    Int dayCount = Constants_DayCountInMonth(constants, month);



    if (month == 1 && leapYear)
    {
        dayCount = dayCount + 1;
    }



    Int ret = dayCount;


    return ret;
}





Int Time_DayCountUpToMonth(Int month, Bool leapYear)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);




    Int dayCount = Constants_DayCountUpToMonth(constants, month);




    if (1 < month && leapYear)
    {
        dayCount = dayCount + 1;
    }



    Int ret = dayCount;


    return ret;
}





Int Time_LeapYearCountUpToYear(Int year)
{
    Int t = year / 4 - year / 100 + year / 400;


    Int ret = t;


    return ret;
}




Bool Time_LeapYear(Int year)
{
    Int k = year + 1;


    return (k % 4 == 0) && ( (k % 100 != 0) || (k % 400 == 0) );
}




Bool Time_ToDate(Int tickCount, Int* year, Int* month, Int* day, Int* hour, Int* minute, Int* second, Int* millisecond)
{
    Int millisecondCount = tickCount;



    Int millisecondCountRemain = 0;



    Int totalDayCount = Time_DayCountFromMillisecondCount(millisecondCount, &millisecondCountRemain);







    Int dayCount = 0;
    


    Int dayCountRemain = 0;





    dayCount = totalDayCount;



    dayCountRemain = 0;



    Int yearCount = 0;



    yearCount = Time_YearCountFromDayCount(dayCount, &dayCountRemain);







    dayCount = dayCountRemain;



    dayCountRemain = 0;






    Int monthCount = 0;



    monthCount = Time_MonthCountFromDayCount(dayCount, &dayCountRemain);







    dayCount = dayCountRemain;



    dayCountRemain = 0;







    millisecondCount = millisecondCountRemain;



    millisecondCountRemain = 0;



    Int hourCount = 0;
    
    
    
    hourCount = Time_HourCountFromMillisecondCount(millisecondCount, &millisecondCountRemain);





    millisecondCount = millisecondCountRemain;



    millisecondCountRemain = 0;



    Int minuteCount = 0;



    minuteCount = Time_MinuteCountFromMillisecondCount(millisecondCount, &millisecondCountRemain);





    millisecondCount = millisecondCountRemain;



    millisecondCountRemain = 0;



    Int secondCount = 0;



    secondCount = Time_SecondCountFromMillisecondCount(millisecondCount, &millisecondCountRemain);




    millisecondCount = millisecondCountRemain;



    millisecondCountRemain = 0;





    *year = yearCount;


    *month = monthCount;


    *day = dayCount;


    *hour = hourCount;


    *minute = minuteCount;


    *second = secondCount;


    *millisecond = millisecondCount;



    return true;
}





Int Time_YearCountFromDayCount(Int dayCount, Int* dayCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);




    Int remain = dayCount;




    Int fourHundredYearsDayCount = Constants_FourHundredYearsDayCount(constants);




    Int fourHundredYearsCount = remain / fourHundredYearsDayCount;




    remain = remain % fourHundredYearsDayCount;




    Int oneHundredYearsDayCount = Constants_OneHundredYearsDayCount(constants);




    Int oneHundredYearsCount = remain / oneHundredYearsDayCount;




    remain = remain % oneHundredYearsDayCount;




    Int fourYearsDayCount = Constants_FourYearsDayCount(constants);




    Int fourYearsCount = remain / fourYearsDayCount;




    remain = remain % fourYearsDayCount;




    Int oneYearsDayCount = Constants_DayCountInYear(constants);




    Int oneYearsCount = remain / oneYearsDayCount;




    remain = remain % oneYearsDayCount;





    Int yearCount = fourHundredYearsCount * 400 + oneHundredYearsCount * 100 + fourYearsCount * 4 + oneYearsCount * 1;




    *dayCountRemain = remain;




    Int ret = yearCount;


    return ret;
}




Int Time_MonthCountFromDayCount(Int dayCount, Int* dayCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);




    Int monthCount = Constants_MonthCountInYear(constants);



    
    Int month = 0;



    Int dayCountUpToMonth = 0;




    Int count = monthCount;



    Bool b = false;



    Int i = 0;



    while ((!b) && (i < count))
    {
        Int index = count - 1 - i;



        dayCountUpToMonth = Constants_DayCountUpToMonth(constants, index);



        Bool ba = (dayCount < dayCountUpToMonth);


        if (!ba)
        {
            month = index;


            b = true;
        }
        



        i = i + 1;
    }



    Int remain = dayCount - dayCountUpToMonth;



    *dayCountRemain = remain;




    Int k = month;



    Int ret = k;


    return ret;
}






Int Time_DayCountInYears(Int yearCount, Int dayCountInYear)
{
    Int k = yearCount * dayCountInYear + yearCount / 4 - yearCount / 100 + yearCount / 400;



    Int ret = k;


    return ret;
}





Int Time_DayCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);



    Int millisecondCountInDay = Constants_MillisecondCountInDay(constants);




    Int dayCount = millisecondCount / millisecondCountInDay;



    Int remain = millisecondCount % millisecondCountInDay;



    *millisecondCountRemain = remain;




    Int ret = dayCount;



    return ret;
}




Int Time_HourCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);



    Int millisecondCountInHour = Constants_MillisecondCountInHour(constants);




    Int hourCount = millisecondCount / millisecondCountInHour;



    Int remain = millisecondCount % millisecondCountInHour;



    *millisecondCountRemain = remain;




    Int ret = hourCount;



    return ret;
}





Int Time_MinuteCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);



    Int millisecondCountInMinute = Constants_MillisecondCountInMinute(constants);




    Int minuteCount = millisecondCount / millisecondCountInMinute;



    Int remain = millisecondCount % millisecondCountInMinute;



    *millisecondCountRemain = remain;




    Int ret = minuteCount;



    return ret;
}




Int Time_SecondCountFromMillisecondCount(Int millisecondCount, Int* millisecondCountRemain)
{
    Object global = Infra_Form_Global();




    Object constants = Global_Constants(global);



    Int millisecondCountInSecond = Constants_MillisecondCountInSecond(constants);




    Int secondCount = millisecondCount / millisecondCountInSecond;



    Int remain = millisecondCount % millisecondCountInSecond;



    *millisecondCountRemain = remain;




    Int ret = secondCount;



    return ret;
}