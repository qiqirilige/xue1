// 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class CQiqirilige
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int millisecond;
	int check();
public:
	CQiqirilige();
	CQiqirilige(int y, int m, int d, int h, int j, int s, int k);
	int setQiqirilige(int y, int m, int d, int h, int j, int s, int k);
	int printfQiqirilige();
	void addOneday();
	void addOnemillisecond();
	int getYear();
	int getMonth();
	int getDay();
	int getHour();
	int getMinute();
	int getSecond();
	int getMillisecond;
};
CQiqirilige::CQiqirilige()
{
	year = 2019;
	month = 4;
	day = 25;
	hour = 10;
	minute = 30;
	second = 10;
	millisecond = 900;
}
CQiqirilige::CQiqirilige(int y, int m, int d, int h, int j, int s, int k)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = j;
	second = s;
	millisecond = k;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
	}
	if (check() == 1 || check() == -1)
	{
		minute = 1;
		second = 1;
		cout << "设置了错误时间，分秒已置1" << endl;
	}
}
int CQiqirilige::setQiqirilige(int y, int m, int d, int h, int j, int s, int k)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = j;
	second = s;
	millisecond = k;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1" << endl;
		return -1;
	}
	if (check() == 1 || check() == -1)
	{
		minute = 1;
		second = 1;
		cout << "设置了错误时间，分秒已置1" << endl;
	}
	return 0;
}
int CQiqirilige::printfQiqirilige()
{
	cout << year << "年" << month << "月" << day << "日" << hour << "时" << minute << "分" << second << "秒" << millisecond << "毫秒" << endl;
	return 1;
}
int CQiqirilige::check()
{
	int flatYearDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
int CQiqirilige::getYear()
{
	return year;
}
int CQiqirilige::getMonth()
{
	return month;
}
int CQiqirilige::getDay()
{
	return day;
}
int CQiqirilige::getHour()
{
	return hour;
}
int CQiqirilige::getMinute()
{
	return minute;
}
int CQiqirilige::getSecond()
{
	return second;
}
void CQiqirilige::addOneday()
{
	int flatYearDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}

	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
			
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}

int main()
{
	CQiqirilige od;
	od.setQiqirilige(2000, 4, 17, 15, 30, 10, 900);
	od.printfQiqirilige();
	return 0;
}