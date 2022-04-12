#include<iostream>

class DateInterval{
public:
	DateInterval(int y,int m,int d):yr(y),mt(m),dy(d){}
	DateInterval(int m,int d):yr(0),mt(m),dy(d){}
	DateInterval(int d):yr(0),mt(0),dy(d){}
	DateInterval():yr(0),mt(0),dy(0){}
	
	const int& get_year() const{
		return yr;
	}
	const int& get_month() const{
		return mt;
	}
	const int& get_day() const{
		return dy;
	}
	
private:
	int yr,mt,dy;
};

class Date {
public:
	
	Date(int y,int m,int d):yr(y),mt(m),dy(d){}
		
    Date& operator++( ){      //下一天
    	if(is_leap_year()&&mt==2&&dy>=28){
    		if(dy==28){
    			dy++;
			}
    		else if(dy==29){
    			mt++;
    			dy=1;
			}
		}
		else if(dy==mon[mt]){
			if(mt==12){
				yr++;
				mt=dy=1;
			}
			else{
				mt++;
				dy=1;
			}
		}
		else{
			dy++;
		}
		return *this;
	}
	Date  operator++( int ){  //下一天 
		Date Temp(*this);
		
		if(is_leap_year()&&mt==2&&dy>=28){
    		if(dy==28){
    			dy++;
			}
    		else if(dy==29){
    			mt++;
    			dy=1;
			}
		}
		else if(dy==mon[mt]){
			if(mt==12){
				yr++;
				mt=dy=1;
			}
			else{
				mt++;
				dy=1;
			}
		}
		else{
			dy++;
		}
		
		return Temp;
	}

    Date& operator--( ){       //前一天
    	if(dy==1){
    		if(is_leap_year()&&mt==3){
    			mt--;
    			dy=29;
			}
			else if(mt==1){
				yr--;
				mt=12;
				dy=mon[12];
			}
			else{
				mt--;
				dy=mon[mt];
			}
		}
		else{
			dy--;
		}
		return *this;
	}
    Date   operator--( int ){   //前一天 
		Date Temp(*this);
		
		if(dy==1){
    		if(is_leap_year()&&mt==3){
    			mt--;
    			dy=29;
			}
			else if(mt==1){
				yr--;
				mt=12;
				dy=mon[12];
			}
			else{
				mt--;
				dy=mon[mt];
			}
		}
		else{
			dy--;
		}
		
		return Temp;
	}

    DateInterval  operator-(const Date& d2) const{ //返回时间间隔
    	const Date* d0=this;
    	const Date* d1=&d2;
    
		if(yr<d2.yr||(yr==d2.yr&&mt<d2.mt)||(yr==d2.yr&&mt==d2.mt&&dy<d2.dy)){
			d0=&d2;
			d1=this;
		}
		else{
			d0=this;
			d1=&d2;
		}
		int rety=d0->yr-d1->yr;
		int retm,retd;
		
		if(d0->mt>=d1->mt){
			retm=d0->mt-d1->mt;
		}
		else{
			rety--;
			retm=12-d1->mt+d0->mt;
		}
		
		if(d0->dy>=d1->dy){
			retd=d0->dy-d1->dy;
		}
		else{
			retm--;
			retd=mon[d1->mt]-d1->dy+d0->dy;
		}
		
		return DateInterval(rety,retm,retd);
	}
    
    bool isNationalDay( ) const{  //判断是否是国庆日
		if(mt==10&&dy==1) return true;
		else return false;
	}
	
    Date& operator+=(const DateInterval& di){
    	dy+=di.get_day();
    	
    	if(is_leap_year()&&mt==2&&dy>=29){
    		if(dy==30){
    			mt++;
    			dy=1;
			}
		}
    	else if(dy>mon[mt]){
    		mt++;
    		dy=1;
		}
		if(mt==13){
			yr++;
			mt=1;
		}
		
		mt+=di.get_month();
		if(mt>12){
			yr++;
			mt%=12;
		}
		
		return *this;
	}
    
    void display( ) const{
		std::cout<<yr<<' '<<mt<<' '<<dy<<std::endl;
	}
	
	const int& get_year() const{
		return yr;
	}
	const int& get_month() const{
		return mt;
	}
	const int& get_day() const{
		return dy;
	}       

private:
	bool is_leap_year(){
		if((yr%4==0&&yr%100!=0)||(yr%400==0)) return true;
		return false;
	}

public:
	static const int mon[13];
	
private:
	int yr,mt,dy;
};

Date operator+(const Date& dt, const DateInterval& di){
	Date d(dt);
	d+=di;
	return d;
}

Date operator+(const DateInterval& di, const Date& dt){
	Date d(dt);
	d+=di;
	return d;
}

std::ostream& operator<<(std::ostream& out, const Date& dt){
	out<<dt.get_year()<<' '<<dt.get_month()<<' '<<dt.get_day()<<std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const DateInterval& di){
	out<<di.get_year()<<' '<<di.get_month()<<' '<<di.get_day()<<std::endl;
	return out;
}

const int Date::mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main( )

{

    Date d1(2020,1,31);
    Date d2(2020,10,1);

    d1.display( ); //预期输出 2020-01-31

    d2.display( ); //预期输出 2020-10-01
   
    std::cout<<d2-d1<<std::endl;      //预期输出2个月1天

    (d1--).display( );               //预期输出2020-01-30

    std::cout<<(++d2)-d1<<std::endl; //预期输出2个月3天        
     
}
