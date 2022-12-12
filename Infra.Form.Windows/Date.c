#include "Date.h"




ClassNew(Date)




Bool Date_Init(Object this)
{
    Date* m = CastPointer(this);



    Object global = Infra_Form_Global();



    Object constants = Global_Constants(global);



    m->Constants = constants;



    return true;
}




Bool Date_Final(Object this)
{
    return true;
}




Int Date_GetYear(Object this)
{
    Date* m = CastPointer(this);


    return m->Year;
}



Bool Date_SetYear(Object this, Int value)
{
    Date* m = CastPointer(this);


    m->Year = value;


    return true;
}




Int Date_GetMonth(Object this)
{
    Date* m = CastPointer(this);


    return m->Month;
}



Bool Date_SetMonth(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int monthCount = Constants_MonthCountInYear(m->Constants);



    Bool b = (value < monthCount);



    if (!b)
    {
        return false;
    }



    m->Month = value;


    return true;
}




Int Date_GetDay(Object this)
{
    Date* m = CastPointer(this);


    return m->Day;
}



Bool Date_SetDay(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int month = m->Month;



    Int year = m->Year;



    Bool leapYear = Time_LeapYear(year);




    Int dayCount = Time_DayCountInMonth(month, leapYear);

    


    Bool b = (value < dayCount);



    if (!b)
    {
        return false;
    }



    m->Day = value;


    return true;
}




Int Date_GetHour(Object this)
{
    Date* m = CastPointer(this);


    return m->Hour;
}




Bool Date_SetHour(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int hourCount = Constants_HourCountInDay(m->Constants);



    Bool b = (value < hourCount);



    if (!b)
    {
        return false;
    }



    m->Hour = value;


    return true;
}




Int Date_GetMinute(Object this)
{
    Date* m = CastPointer(this);


    return m->Minute;
}




Bool Date_SetMinute(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int minuteCount = Constants_MinuteCountInHour(m->Constants);



    Bool b = (value < minuteCount);



    if (!b)
    {
        return false;
    }



    m->Minute = value;


    return true;
}





Int Date_GetSecond(Object this)
{
    Date* m = CastPointer(this);


    return m->Second;
}




Bool Date_SetSecond(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int secondCount = Constants_SecondCountInMinute(m->Constants);



    Bool b = (value < secondCount);



    if (!b)
    {
        return false;
    }



    m->Second = value;


    return true;
}





Int Date_GetMillisecond(Object this)
{
    Date* m = CastPointer(this);


    return m->Millisecond;
}




Bool Date_SetMillisecond(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int millisecondCount = Constants_MillisecondCountInSecond(m->Constants);



    Bool b = (value < millisecondCount);



    if (!b)
    {
        return false;
    }



    m->Millisecond = value;


    return true;
}




Bool Date_Time(Object this, Object time)
{
    Date* m = CastPointer(this);



    Int year = m->Year;

    Int month = m->Month;

    Int day = m->Day;

    Int hour = m->Hour;

    Int minute = m->Minute;

    Int second = m->Second;

    Int millisecond = m->Millisecond;



    Int tickCount = Time_TickCount(year, month, day, hour, minute, second, millisecond);



    Time_SetTick(time, tickCount);



    return true;
}