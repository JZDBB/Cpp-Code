#ifndef date_hpp
#define date_hpp


class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;
public:
	Date();
    Date(int year, int month, int day);
	static Date read();
    int getYear()const { return year; }
    int getMonth() const { return month; }
    int getDay()const { return day; }
    int getMaxDay()const;
    bool isLeapYear()const{
        return (year%4==0&&year%100!=0)||year % 400==0;
    }
    void show()const;

	bool operator < (const Date &date) const {
		return totalDays < date.totalDays;;
	}

	int operator - (const Date &date) const {
		return totalDays - date.totalDays;
	}
};


#endif /* date_hpp */
