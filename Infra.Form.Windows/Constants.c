#include "Constants.h"




ClassNew(Constants)





Bool Constants_Init(Object this)
{
    Constants* m = CastPointer(this);



    m->MonthCountInYear = 12;



    m->HourCountInDay = 24;



    m->MinuteCountInHour = 60;



    m->SecondCountInMinute = 60;



    m->MillisecondCountInSecond = 1000;



    m->MillisecondCountInMinute = m->SecondCountInMinute * m->MillisecondCountInSecond;



    m->MillisecondCountInHour = m->MinuteCountInHour * m->MillisecondCountInMinute;



    m->MillisecondCountInDay = m->HourCountInDay * m->MillisecondCountInHour;




    Constants_InitDayCountInMonthArray(m);



    Constants_InitDayCountUpToMonthArray(m);
    



    m->DayCountInYear = Constants_DayCountInOneYear(m);



    m->FourHundredYearsDayCount = Time_DayCountInYears(400, m->DayCountInYear);



    m->OneHundredYearsDayCount = Time_DayCountInYears(100, m->DayCountInYear);



    m->FourYearsDayCount = Time_DayCountInYears(4, m->DayCountInYear);




    return true;
}




Bool Constants_Final(Object this)
{
    Constants* m = CastPointer(this);



    Delete(CastInt(m->DayCountInMonthArray));



    Delete(CastInt(m->DayCountUpToMonthArray));
    


    return true;
}




Bool Constants_InitDayCountInMonthArray(Constants* this)
{
    Int monthCount = this->MonthCountInYear;



    Int size = monthCount * sizeof(Int);



    Int* o = CastPointer(New(size));



    this->DayCountInMonthArray = o;




    Constants_AddDayCountInMonth(this, 31);


    Constants_AddDayCountInMonth(this, 28);


    Constants_AddDayCountInMonth(this, 31);


    Constants_AddDayCountInMonth(this, 30);


    Constants_AddDayCountInMonth(this, 31);
    
    
    Constants_AddDayCountInMonth(this, 30);


    Constants_AddDayCountInMonth(this, 31);
    
    
    Constants_AddDayCountInMonth(this, 31);
    
    
    Constants_AddDayCountInMonth(this, 30);

    
    Constants_AddDayCountInMonth(this, 31);
    

    Constants_AddDayCountInMonth(this, 30);


    Constants_AddDayCountInMonth(this, 31);


    return true;
}




Bool Constants_InitDayCountUpToMonthArray(Constants* this)
{
    Int monthCount = this->MonthCountInYear;



    Int size = monthCount * sizeof(Int);



    Int* o = CastPointer(New(size));



    this->DayCountUpToMonthArray = o;



    Int k = 0;



    Int count = monthCount;



    Int i = 0;


    while (i < count)
    {
        Int month = i;



        Int t = this->DayCountInMonthArray[month];



        k = k + t;



        this->DayCountUpToMonthArray[month] = k;



        i = i + 1;
    }



    return true;
}




Bool Constants_AddDayCountInMonth(Constants* this, Int dayCount)
{
    Int index = this->ArrayIndex;



    this->DayCountInMonthArray[index] = dayCount;



    index = index + 1;



    this->ArrayIndex = index;



    return true;
}




Int Constants_MonthCountInYear(Object this)
{
    Constants* m = CastPointer(this);


    return m->MonthCountInYear;
}



Int Constants_DayCountInMonth(Object this, Int month)
{
    Constants* m = CastPointer(this);



    Int monthCount = m->MonthCountInYear;


    Bool b;

    b = (month < monthCount);


    if (!b)
    {
        return 0;
    }



    Int t = m->DayCountInMonthArray[month];


    Int ret = t;


    return ret;
}




Int Constants_HourCountInDay(Object this)
{
    Constants* m = CastPointer(this);


    return m->HourCountInDay;
}




Int Constants_MinuteCountInHour(Object this)
{
    Constants* m = CastPointer(this);


    return m->MinuteCountInHour;
}




Int Constants_SecondCountInMinute(Object this)
{
    Constants* m = CastPointer(this);


    return m->SecondCountInMinute;
}



Int Constants_MillisecondCountInSecond(Object this)
{
    Constants* m = CastPointer(this);


    return m->MillisecondCountInSecond;
}




Int Constants_MillisecondCountInMinute(Object this)
{
    Constants* m = CastPointer(this);


    return m->MillisecondCountInMinute;
}



Int Constants_MillisecondCountInHour(Object this)
{
    Constants* m = CastPointer(this);


    return m->MillisecondCountInHour;
}



Int Constants_MillisecondCountInDay(Object this)
{
    Constants* m = CastPointer(this);


    return m->MillisecondCountInDay;
}




Int Constants_DayCountUpToMonth(Object this, Int month)
{
    Constants* m = CastPointer(this);



    Int monthCount = m->MonthCountInYear;



    Bool b = (month < monthCount);


    if (!b)
    {
        return 0;
    }



    if (month == 0)
    {
        return 0;
    }



    Int k = month - 1;



    Int t = m->DayCountUpToMonthArray[k];



    Int ret = t;


    return ret;
}





Int Constants_DayCountInOneYear(Constants* this)
{
    Int monthCount = this->MonthCountInYear;



    Int month = monthCount - 1;



    Int t = this->DayCountUpToMonthArray[month];



    Int ret = t;


    return t;
}





Int Constants_DayCountInYear(Object this)
{
    Constants* m = CastPointer(this);



    return m->DayCountInYear;
}




Int Constants_FourHundredYearsDayCount(Object this)
{
    Constants* m = CastPointer(this);



    return m->FourHundredYearsDayCount;
}




Int Constants_OneHundredYearsDayCount(Object this)
{
    Constants* m = CastPointer(this);



    return m->OneHundredYearsDayCount;
}




Int Constants_FourYearsDayCount(Object this)
{
    Constants* m = CastPointer(this);



    return m->FourYearsDayCount;
}