#include "Date.h"




InfraClassNew(Date)




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




Int Date_GetMin(Object this)
{
    Date* m = CastPointer(this);


    return m->Min;
}




Bool Date_SetMin(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int minCount = Constants_MinuteCountInHour(m->Constants);



    Bool b = (value < minCount);



    if (!b)
    {
        return false;
    }



    m->Min = value;


    return true;
}





Int Date_GetSec(Object this)
{
    Date* m = CastPointer(this);


    return m->Sec;
}




Bool Date_SetSec(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int secCount = Constants_SecondCountInMinute(m->Constants);



    Bool b = (value < secCount);



    if (!b)
    {
        return false;
    }



    m->Sec = value;


    return true;
}





Int Date_GetMillisec(Object this)
{
    Date* m = CastPointer(this);


    return m->Millisec;
}




Bool Date_SetMillisec(Object this, Int value)
{
    Date* m = CastPointer(this);



    Int millisecCount = Constants_MillisecondCountInSecond(m->Constants);



    Bool b = (value < millisecCount);



    if (!b)
    {
        return false;
    }



    m->Millisec = value;


    return true;
}




Bool Date_Time(Object this, Object time)
{
    Date* m = CastPointer(this);



    Int year = m->Year;

    Int month = m->Month;

    Int day = m->Day;

    Int hour = m->Hour;

    Int min = m->Min;

    Int sec = m->Sec;

    Int millisec = m->Millisec;



    Int tickCount = Time_TickCount(year, month, day, hour, minute, sec, millisec);



    Time_SetTick(time, tickCount);



    return true;
}