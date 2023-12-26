#include <iostream>
using namespace std;

// function prototypes

int startday_calc(int);
int nextstartday_calc(int, int);
bool isleap(int);
string numtostr(int);
void builddates(int, int);
void printyear(int);
void printmonth(int, int);
void printdates(int);
int startdayof(int, int);

// prototypes end

enum months
{
    JANUARY = 0,
    FEBRUARY = 1,
    MARCH = 2,
    APRIL = 3,
    MAY = 4,
    JUNE = 5,
    JULY = 6,
    AUGUST = 7,
    SEPTEMBER = 8,
    OCTOBER = 9,
    NOVEMBER = 10,
    DECEMBER = 11
};

string month[12] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};
string date[6][7];

int main()
{
    int year;
    cout << "Enter year\n";
    cin >> year;
    system("clear");
    printyear(year);
    return 0;
}

void printyear(int year)
{
    for (int month_counter = 0; month_counter < 12; month_counter++)
    {
        printmonth(month_counter, year);
    }
}

void printmonth(int month_index, int year)
{
    int startingday;
    if (month_index == APRIL || month_index == JUNE || month_index == SEPTEMBER || month_index == NOVEMBER)
    {
        startingday = startdayof(month_index, year);
        builddates(startingday, 30);
    }
    else if (month_index == FEBRUARY)
    {
        // February
        startingday = nextstartday_calc(startingday, 31);
        if (isleap(year))
        {
            builddates(startingday, 29);
        }
        else
        {
            builddates(startingday, 28);
        }
    }
    else
    {
        startingday = startdayof(month_index, year);
        builddates(startingday, 31);
    }
    printdates(month_index);
}

void builddates(int startday, int lastdate)
{
    int datecounter = 1;
    if (0 != startday)
    {
        for (int row = 0; row < 6; row++)
        {
            for (int col = 0; col < 7; col++)
            {
                if (datecounter > lastdate)
                {
                    date[row][col] = "    ";
                }
                else if (row == 0)
                {
                    if (col <= (startday - 2))
                    {
                        date[row][col] = "    ";
                    }
                    else
                    {
                        date[row][col] = "  " + numtostr(datecounter) + " ";
                        datecounter++;
                    }
                }
                else
                {
                    if (datecounter < 10) // Two spaces will be added if single digit. i.e., less than 10
                    {
                        date[row][col] = "  " + numtostr(datecounter) + " ";
                    }
                    else
                    {
                        date[row][col] = " " + numtostr(datecounter) + " ";
                    }
                    datecounter++;
                }
            }
        }
    }
    else // if 0 == startday
    {
        for (int row = 0; row < 6; row++)
        {
            for (int col = 0; col < 7; col++)
            {
                if (datecounter > lastdate)
                {
                    date[row][col] = "    ";
                }
                else if (row == 0)
                {
                    if (col <= 5)
                    {
                        date[row][col] = "    ";
                    }
                    else
                    {
                        date[row][col] = "  " + numtostr(datecounter) + " ";
                        datecounter++;
                    }
                }
                else
                {
                    if (datecounter < 10) // Two spaces will be added if single digit. i.e., less than 10
                    {
                        date[row][col] = "  " + numtostr(datecounter) + " ";
                    }
                    else
                    {
                        date[row][col] = " " + numtostr(datecounter) + " ";
                    }
                    datecounter++;
                }
            }
        }
    }
}

void printdates(int month_index)
{
    cout << "\n------------------------------------";
    cout << "\n|" << month[month_index];
    cout << "\n|sund|mond|tued|wedn|thur|frid|satd|\n";
    for (int row = 0; row < 6; row++)
    {
        cout << "|";
        for (int col = 0; col < 7; col++)
        {
            cout << date[row][col] << "|";
        }
        cout << "\n";
    }
}
// Calculating The Day To Start The Year
int startday_calc(int year)
{
    int yearcount, leapyears = 0, normalyears;
    int totaldays, startingday;

    for (yearcount = 0; yearcount < year; yearcount++)
    {
        if (isleap(yearcount))
        {
            leapyears++;
        }
    }

    normalyears = year - leapyears;
    totaldays = ((leapyears * 366) + (normalyears * 365));
    startingday = totaldays % 7;

    return startingday;
}

int nextstartday_calc(int current_startday, int current_lastdate)
{
    int nextstartday, extra;
    const int CONSTANT = 28;
    extra = current_lastdate - CONSTANT;
    if (current_startday <= (6 - extra))
    {
        nextstartday = current_startday + extra;
    }
    else
    {
        int value = (6 - current_startday);
        nextstartday = ((extra - value) - 1);
    }

    return nextstartday;
}

int startdayof(int month_index, int year)
{
    int startingday;
    startingday = startday_calc(year); // JANUARY
    if (month_index == JANUARY)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // FEBRUARY
    if (month_index == FEBRUARY)
        return startingday;

    if (isleap(year))
    {
        startingday = nextstartday_calc(startingday, 29); // MARCH
    }
    else
    {
        startingday = nextstartday_calc(startingday, 28); // MARCH
    }
    if (month_index == MARCH)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // APRIL
    if (month_index == APRIL)
        return startingday;

    startingday = nextstartday_calc(startingday, 30); // MAY
    if (month_index == MAY)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // JUNE
    if (month_index == JUNE)
        return startingday;

    startingday = nextstartday_calc(startingday, 30); // JULY
    if (month_index == JULY)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // AUGUST
    if (month_index == AUGUST)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // SEPTEMBER
    if (month_index == SEPTEMBER)
        return startingday;

    startingday = nextstartday_calc(startingday, 30); // OCTOBER
    if (month_index == OCTOBER)
        return startingday;

    startingday = nextstartday_calc(startingday, 31); // NOVEMBER
    if (month_index == NOVEMBER)
        return startingday;

    startingday = nextstartday_calc(startingday, 30); // DECEMBER
    if (month_index == DECEMBER)
        return startingday;

    return 999;
}

// Finds if a given year is a leap year or not.
bool isleap(int year)
{
    if (0 == (year % 100))
    {
        if (0 == (year % 400))
        {
            return true;
        }
    }
    else if (0 == (year % 4))
    {
        return true;
    }
    return false;
}

string numtostr(int num)
{
    string str;

    while (num > 0)
    {
        int digit = num % 10;

        // Convert digit to ASCII character
        char ch = static_cast<char>('0' + digit);

        // Prepend character to the string (front instead of back)
        str = ch + std::move(str);

        num /= 10;
    }
    return str;
}