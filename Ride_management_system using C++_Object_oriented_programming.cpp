#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;

class Name
{
private:
	char* fName{};//First Name
	char* lName{};//Last Name
public:
	Name();//Default Constructor
	Name(char*, char*);//Parametirized Constructer
	Name(const Name&);//Copy Constructor
	void setname(char*, char*);//Set Function of both names 
	void setfname(char*);//Set function of fname 
	void setlname(char*);//Set function og lname
	void getname();//get gunction for both names
	char* getf();//get function for fname
	char* getl();//get function for lname
	friend ostream& operator<<(ostream&, const Name&);//output operator for name class
	~Name();//Destructor
};

Name::Name()
{
	fName = NULL;
	lName = NULL;
}

Name::Name(char* fN, char* lN)
{
	fName = new char[strlen(fN) + 1];
	fName = fN;
	lName = new char[strlen(lN) + 1];
	lName = lN;
}

Name::Name(const Name& obj)
{
	if ((obj.fName != nullptr) && (obj.lName != nullptr))
	{
		fName = new char[strlen(obj.fName) + 1];
		fName = obj.fName;
		lName = new char[strlen(obj.lName) + 1];
		lName = obj.lName;
	}
}

void Name::setname(char* a, char* b)
{
	fName = new char[strlen(a) + 1];
	fName = a;
	lName = new char[strlen(b) + 1];
	lName = b;
}

void Name::setfname(char* a)
{
	fName = new char[strlen(a) + 1];
	fName = a;
}

void Name::setlname(char* b)
{
	lName = new char[strlen(b) + 1];
	lName = b;
}

void Name::getname()
{
	cout << fName << endl;
	cout << lName << endl;
}

char* Name::getf()
{
	return fName;
}

char* Name::getl()
{
	return lName;
}

ostream& operator<<(ostream& out, const Name& n)
{
	out << n.fName << " " << n.lName << endl;
	return out;
}

Name::~Name()
{
	delete fName;
	delete lName;
	fName = nullptr;
	lName = nullptr;
}


class Date
{
	int day;
	int month;
	int year;
	int* dob;
public:
	Date();//Constructor
	Date(int, int, int);//Parametirized Constructor
	void setDOB(int, int, int);//Set function for all values
	void setday(int);//set function for day
	void setmonth(int);//set function for month
	void setyear(int);//set function for year
	int getd();//getter for date
	int getm();//getter for month
	int gety();//getter for year
	int* getDOB();//getter for the whole date of birth
	friend ostream& operator<<(ostream&, const Date&);

};

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	dob = new int[3];
}

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::setDOB(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
	dob[0] = d;
	dob[1] = m;
	dob[2] = y;
}

void Date::setday(int d)
{
	day = d;
}

void Date::setmonth(int m)
{
	month = m;
}

void Date::setyear(int y)
{
	year = y;
}

int Date::getd()
{
	return day;
}

int Date::getm()
{
	return month;
}

int Date::gety()
{
	return year;
}

int* Date::getDOB()
{
	return dob;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << obj.day << "/" << obj.month << "/" << obj.year << endl;
	return out;
}


class mTime
{
	int hour;
	int min;
	int sec;
public:

	mTime();//Default constructer
	mTime(int, int, int);//Overloaded Constructor
	mTime(mTime&);//Copy Constructor
	void set_time(int, int, int);//Setter for time
	void set_h(int);//setter for hours
	void set_m(int);//setter for mins
	void set_s(int);//setter for secs
	void get_time();//getter for whole time
	int get_h();//getter for hours
	int get_m();//getter for mins
	int get_s();//getter for secs
	friend ostream& operator<< (ostream&, const mTime&);//output operator
};

mTime::mTime()
{
	hour = 0;
	min = 0;
	sec = 0;
}

mTime::mTime(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

mTime::mTime(mTime& obj)
{
	if (obj.hour > 0 && obj.min > 0 && obj.sec > 0)
	{
		hour = obj.hour;
		min = obj.min;
		sec = obj.sec;
	}
}

void mTime::set_time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void mTime::set_h(int h)
{
	hour = h;
}

void mTime::set_m(int m)
{
	min = m;
}

void mTime::set_s(int s)
{
	sec = s;
}

void mTime::get_time()
{
	cout << hour << " : " << min << " : " << sec;
}

int mTime::get_h()
{
	return hour;
}

int mTime::get_m()
{
	return min;
}

int mTime::get_s()
{
	return sec;
}

ostream& operator<< (ostream& out, const mTime& obj)
{
	out << obj.hour << " : " << obj.min << " : " << obj.sec;
	return out;
}

class Service
{
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;
	int cus_Id; // Customer Id who booked the ride
	int dvr_Id; // Driver Id
	int vhl_Id; // vehicle Id
public:

	Service();//Default Constructer
	Service(char*, char*, float, Date, mTime, bool, float, int, int, int);//Parameterized Constructor
	Service(const Service& s);//copy Constructor
	void set_source(char*);//source setter
	void set_destination(char*);//destination setter
	void set_distance(float);//distance setter
	void set_bookingDate(Date);//booking setter
	void set_bookingTime(mTime);//time setter
	void set_status(bool);//completed or not completed status check
	void set_fuelrate(float);//fuel setter
	void set_customerID(int);//Customer Id setter
	void set_driverID(int);//driver id setter
	void set_vehicleID(int);//vehicle id setter
	char* get_source();//source getter
	char* get_destination();// destination getter
	float get_distance();//distance getter
	Date get_bookingDate();//Booking date getter
	mTime get_bookingTime();//Booking time getter
	bool get_status();//Status getter
	float get_fuelrate();//Fuel getter
	int get_customerID();//Customer getter
	int get_driverID();//Driver getter
	int get_vehicleID();//Vehicle getter
	friend ostream& operator<<(ostream&, const Service&);//Output operator
	~Service();//Destructor
};

Service::Service() :bookingDate(), bookingTime()
{
	source = {};
	destination = {};
	distance = 0;
	status = 0;
	fuelrate = 0.0;
	cus_Id = 0;
	dvr_Id = 0;
	vhl_Id = 0;
}

Service::Service(char* sou, char* des, float dist, Date bookD, mTime bookT, bool stat, float fuel, int cusId, int dvrId, int vhlId) :bookingDate(bookD), bookingTime(bookT)
{
	source = new char[strlen(sou) + 1];
	source = sou;
	destination = new char[strlen(des) + 1];
	destination = des;
	distance = dist;
	status = stat;
	fuelrate = fuel;
	cus_Id = cusId;
	dvr_Id = dvrId;
	vhl_Id = vhlId;
}

Service::Service(const Service& obj)
{
	source = new char[strlen(obj.source) + 1];
	source = obj.source;
	destination = new char[strlen(obj.destination) + 1];
	destination = obj.destination;
	distance = obj.distance;
	bookingDate = obj.bookingDate;
	bookingTime = obj.bookingTime;
	status = obj.status;
	fuelrate = obj.fuelrate;
	cus_Id = obj.cus_Id;
	dvr_Id = obj.dvr_Id;
	vhl_Id = obj.vhl_Id;
}

void Service::set_source(char* sou)
{
	source = new char[strlen(sou) + 1];
	source = sou;
}

void Service::set_destination(char* des)
{
	destination = new char[strlen(des) + 1];
	destination = des;
}

void Service::set_distance(float dist)
{
	distance = dist;
}

void Service::set_bookingDate(Date bookD)
{
	bookingDate = bookD;
}

void Service::set_bookingTime(mTime bookT)
{
	bookingTime = bookT;
}

void Service::set_status(bool stat)
{
	status = stat;
}

void Service::set_fuelrate(float fuel)
{
	fuelrate = fuel;
}

void Service::set_customerID(int cusId)
{
	cus_Id = cusId;
}

void Service::set_driverID(int dvrId)
{
	dvr_Id = dvrId;
}

void Service::set_vehicleID(int vhlId)
{
	vhl_Id = vhlId;
}

char* Service::get_source()
{
	return source;
}

char* Service::get_destination()
{
	return destination;
}

float Service::get_distance()
{
	return distance;
}

Date  Service::get_bookingDate()
{
	return bookingDate;
}

mTime  Service::get_bookingTime()
{
	return bookingTime;
}

bool  Service::get_status()
{
	return status;
}

float  Service::get_fuelrate()
{
	return fuelrate;
}

int  Service::get_customerID()
{
	return cus_Id;
}

int  Service::get_driverID()
{
	return dvr_Id;
}

int  Service::get_vehicleID()
{
	return vhl_Id;
}

ostream& operator<<(ostream& out, const Service& obj)
{
	out << obj.source << endl;
	out << obj.destination << endl;
	out << obj.distance << endl;
	out << obj.bookingDate << endl;
	out << obj.bookingTime << endl;
	out << obj.status << endl;
	out << obj.fuelrate << endl;
	out << obj.cus_Id << endl;
	out << obj.dvr_Id << endl;
	out << obj.vhl_Id << endl;
	return out;
}

Service::~Service()
{
	delete[] source;
	source = nullptr;
	delete[] destination;
	destination = nullptr;
}

class Ride : public Service
{
	int noofPassengers; // false for pending, true if complete
	char* rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)
public:
	Ride();
	Ride(int, char*, float, float);
	Ride(const Ride&);
	void set_noofpassengers(int);
	void set_ridetype(char*);
	void set_driverranking(float);
	void set_vehicleranking(float);
	int get_noofpassengers();
	char* get_ridetype();
	float get_driverranking();
	float get_vehicleranking();
	friend ostream& operator<<(ostream&, const Ride&);
	~Ride();
};

Ride::Ride()
{
	noofPassengers = 0;
	rideType = {};
	DriverRanking = 0;
	VehicleRanking = 0;
}

Ride::Ride(int pass, char* ride, float dvranking, float vhlranking)
{
	noofPassengers = pass;
	rideType = new char[strlen(ride) + 1];
	rideType = ride;
	DriverRanking = dvranking;
	VehicleRanking = vhlranking;
}

Ride::Ride(const Ride& obj)
{
	noofPassengers = obj.noofPassengers;
	rideType = new char[strlen(obj.rideType) + 1];
	rideType = obj.rideType;
	DriverRanking = obj.DriverRanking;
	VehicleRanking = obj.VehicleRanking;
}

void Ride::set_noofpassengers(int pass)
{
	noofPassengers = pass;
}

void Ride::set_ridetype(char* ride)
{
	rideType = new char[strlen(ride) + 1];
	rideType = ride;
}

void Ride::set_driverranking(float dvranking)
{
	DriverRanking = dvranking;
}

void Ride::set_vehicleranking(float vhlranking)
{
	VehicleRanking = vhlranking;
}

int Ride::get_noofpassengers()
{
	return noofPassengers;
}

char* Ride::get_ridetype()
{
	return rideType;
}

float Ride::get_driverranking()
{
	return DriverRanking;
}

float Ride::get_vehicleranking()
{
	return VehicleRanking;
}

ostream& operator<<(ostream& out, const Ride& obj)
{
	out << obj.noofPassengers << endl;
	out << obj.rideType << endl;
	out << obj.DriverRanking << endl;
	out << obj.VehicleRanking << endl;
	return out;
}

Ride::~Ride()
{
	delete[] rideType;
	rideType = nullptr;
}

class Delivery : public Service
{
	float goodsWeight; // Weight of goods in Kg
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
public:
	Delivery();
	Delivery(float, char*);
	Delivery(const Delivery&);
	void set_goodsweight(float);
	void set_goodstype(char*);
	float get_goodsweight();
	char* get_goodstype();
	friend ostream& operator<<(ostream&, const Delivery&);
	~Delivery();
};

Delivery::Delivery()
{
	goodsWeight = 0;
	goodsType = {};
}

Delivery::Delivery(float getWgt, char* gettyp)
{
	goodsWeight = getWgt;
	goodsType = new char[strlen(gettyp) + 1];
	goodsType = gettyp;
}

Delivery::Delivery(const Delivery& obj)
{
	goodsWeight = obj.goodsWeight;
	goodsType = new char[strlen(obj.goodsType) + 1];
	goodsType = obj.goodsType;
}

void Delivery::set_goodsweight(float getWgt)
{
	goodsWeight = getWgt;
}

void Delivery::set_goodstype(char* gettyp)
{
	goodsType = new char[strlen(gettyp) + 1];
	goodsType = gettyp;
}

float Delivery::get_goodsweight()
{
	return goodsWeight;
}

char* Delivery::get_goodstype()
{
	return goodsType;
}

ostream& operator<<(ostream& out, const Delivery& obj)
{
	out << obj.goodsWeight << endl;
	out << obj.goodsType << endl;
	return out;
}

Delivery::~Delivery()
{
	delete[] goodsType;
	goodsType = nullptr;
}

class Person
{
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;//Number Of Id's
public:
	Person();
	Person(char*, char*, int, int, int, int, int);
	Person(const Person&);
	void set_name(char*, char*);
	void set_fname(char*);
	void set_lname(char*);
	void set_DOB(int, int, int);
	void set_age(int);
	void set_id(int);
	void get_name();
	char* get_fname();
	char* get_lname();
	int* get_DOB();
	int get_age();
	int get_id();
	friend ostream& operator <<(ostream&, const Person&);
};


Person::Person() :pName(), DOB()
{
	Age = 0;
	Nid = 0;
}

Person::Person(char* fname, char* lname, int day, int month, int year, int a, int i) :pName(fname, lname), DOB(day, month, year)
{
	Age = a;
	Nid = i;
}

Person::Person(const Person& obj)
{
	DOB = obj.DOB;
	Age = obj.Age;
	pName = obj.pName;
	Nid = obj.Nid;
}

void Person::set_name(char* fname, char* lname)
{
	pName.setname(fname, lname);//Function for setting the first name and last name in the name class
}

void Person::set_fname(char* fname)
{
	pName.setfname(fname);
}

void Person::set_lname(char* lname)
{
	pName.setlname(lname);
}

void Person::set_DOB(int d, int m, int y)
{
	DOB.setDOB(d, m, y);//Function for setting the date of birth in the Date Class
}

void Person::set_age(int a)
{
	Age = a;
}

void Person::set_id(int i)
{
	Nid = i;
}

void Person::get_name()
{
	pName.getname();
}

char* Person::get_fname()
{
	return pName.getf();
}

char* Person::get_lname()
{
	return pName.getl();
}

int* Person::get_DOB()
{
	return DOB.getDOB();
}

int Person::get_age()
{
	return Age;
}

int Person::get_id()
{
	return Nid;
}

ostream& operator <<(ostream& out, const Person& obj)
{
	out << obj.pName << endl;
	out << obj.DOB << endl;
	out << obj.Age << endl;
	out << obj.Nid;
	return out;
}

class Customer : public Person
{
private:
	int cId;
	// Unique and assigned first time when customer makes first service request
	Service** bookingHistory;
public:
	Customer();
	Customer(int, Service**);
	Customer(const Customer&);
	void set_customerID(int);
	void set_bookinghistory(Service**);
	int get_customerID();
	Service** get_bookinghistory();
	friend ostream& operator<< (ostream&, const Customer&);
	~Customer();
};

Customer::Customer() :bookingHistory()
{
	cId = 0;
}

Customer::Customer(int i, Service** bookhis)
{
	cId = i;
	bookingHistory = bookhis;
}

Customer::Customer(const Customer& obj)
{
	cId = obj.cId;
	bookingHistory = obj.bookingHistory;
}

void Customer::set_customerID(int i)
{
	cId = i;
}

void Customer::set_bookinghistory(Service** bookhis)
{
	bookingHistory = bookhis;
}

int Customer::get_customerID()
{
	return cId;
}

Service** Customer::get_bookinghistory()
{
	return bookingHistory;
}

ostream& operator<< (ostream& out, const Customer& obj)
{
	out << obj.cId << endl;
	out << obj.bookingHistory << endl;
	return out;
}

Customer::~Customer()
{
	for (int i = 0; i < 20; i++)
	{
		delete[] bookingHistory[i];
	}
	bookingHistory = nullptr;
}

class Driver : public Person
{
private:
	int dId;//Druver Id
	int* LicencesList;//List Liscences He Have
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if cancelled
	Service** serviceHistory;
public:

	Driver();
	Driver(int, int*, int, float, float, int, int, Service**);
	Driver(const Driver&);
	void set_driverId(int);
	void set_lisenceslist(int*);
	void set_noofliscences(int);
	void set_overallranking(float);
	void set_salary(float);
	void set_experience(int);
	void set_status(int);
	void set_servicehistory(Service**);
	int get_driverId();
	int* get_lisenceslist();
	int get_noofliscences();
	float get_overallranking();
	float get_salary();
	int get_experience();
	int get_status();
	Service** get_servicehistory();
	friend ostream& operator<<(ostream&, const Driver&);
	~Driver();
};

Driver::Driver() :serviceHistory()
{
	dId = 0;
	LicencesList = 0;
	noofLicences = 0;
	overallRanking = 0.0;
	salary = 0.0;
	experience = 0;
	status = 0;
}

Driver::Driver(int dvrID, int* lislst, int liscenses, float dvranking, float sal, int exp, int stat, Service** svrhistory)
{
	dId = dvrID;
	LicencesList = new int[liscenses];
	LicencesList = lislst;
	noofLicences = liscenses;
	overallRanking = dvranking;
	salary = sal;
	experience = exp;
	status = stat;
	serviceHistory = svrhistory;
}

Driver::Driver(const Driver& obj)
{
	dId = obj.dId;
	LicencesList = obj.LicencesList;
	noofLicences = obj.noofLicences;
	overallRanking = obj.overallRanking;
	salary = obj.salary;
	experience = obj.experience;
	status = obj.status;
	serviceHistory = obj.serviceHistory;
}

void Driver::set_driverId(int dvrID)
{
	dId = dvrID;
}

void Driver::set_lisenceslist(int* lislst)
{
	LicencesList = lislst;
}

void Driver::set_noofliscences(int liscenses)
{
	noofLicences = liscenses;
}

void Driver::set_overallranking(float dvranking)
{
	overallRanking = dvranking;
}

void Driver::set_salary(float sal)
{
	salary = sal;
}

void Driver::set_experience(int exp)
{
	experience = exp;
}

void Driver::set_status(int stat)
{
	status = stat;
}

void Driver::set_servicehistory(Service** svrhistory)
{
	serviceHistory = svrhistory;
}

int Driver::get_driverId()
{
	return dId;
}

int* Driver::get_lisenceslist()
{
	return LicencesList;
}

int Driver::get_noofliscences()
{
	return noofLicences;
}

float Driver::get_overallranking()
{
	return overallRanking;
}

float Driver::get_salary()
{
	return salary;
}

int Driver::get_experience()
{
	return experience;
}

int Driver::get_status()
{
	return status;
}

Service** Driver::get_servicehistory()
{
	return serviceHistory;
}

ostream& operator<<(ostream& out, const Driver& obj)
{
	out << obj.dId << endl;
	out << obj.LicencesList << endl;
	out << obj.noofLicences << endl;
	out << obj.overallRanking << endl;
	out << obj.salary << endl;
	out << obj.serviceHistory << endl;
	out << obj.status << endl;
	return out;
}

Driver::~Driver()
{
	delete[] LicencesList;
	LicencesList = nullptr;
	for (int i = 0; i < 20; i++)
	{
		delete[] serviceHistory[i];
	}
	serviceHistory = nullptr;
}

class Feature//Features Of Vehicle (Functions Related To It's Class)
{
	int fId;
	char* description;
	float cost;
public:
	Feature();
	Feature(int, char*, float);
	Feature(const Feature&);
	void set_featureID(int);
	void set_description(char*);
	void set_cost(float);
	int get_featureID();
	char* get_description();
	float get_cost();
	friend ostream& operator<<(ostream&, const Feature&);
	~Feature();
};

Feature::Feature()
{
	fId = 0;
	description = {};
	cost = 0;
}

Feature::Feature(int featureID, char* dsc, float mny)
{
	fId = featureID;
	description = new char[strlen(dsc) + 1];
	description = dsc;
	cost = mny;
}

Feature::Feature(const Feature& obj)
{
	fId = obj.fId;
	description = new char[strlen(obj.description) + 1];
	description = obj.description;
	cost = obj.cost;
}

void Feature::set_featureID(int featureID)
{
	fId = featureID;
}

void Feature::set_description(char* dsc)
{
	description = new char[strlen(dsc) + 1];
	description = dsc;
}

void Feature::set_cost(float mny)
{
	cost = mny;
}

int Feature::get_featureID()
{
	return fId;
}

char* Feature::get_description()
{
	return description;
}

float Feature::get_cost()
{
	return cost;
}

ostream& operator<<(ostream& out, const Feature& obj)
{
	out << obj.fId << endl;
	for (int i = 0; i < obj.description[i] != '\0'; i++)
	{
		out << obj.description[i];
	}
	out << endl;
	out << obj.cost << endl;
	return out;
}

Feature::~Feature()
{
	delete[] description;
	description = nullptr;
}

class Vehicle
{
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	char* fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
public:
	Vehicle();
	Vehicle(int, int, int, char*, bool, char*, float, Date, Feature*, Service**);
	Vehicle(const Vehicle&);
	void set_vehicleID(int);
	void set_registrationo(int);
	void set_averagemilage(int);
	void set_liscencetype(char*);
	void set_status(bool);
	void set_fueltype(char*);
	void set_overallranking(float);
	void set_manufacturingdate(Date);
	void set_featurelist(Feature*);
	void set_servicehistory(Service**);
	int get_vehicleID();
	int get_registrationo();
	float get_averagemilage();
	char* get_liscencetype();
	bool get_status();
	char* get_fueltype();
	float get_overallranking();
	Date get_manufacturingdate();
	Feature* get_featurelist();
	Service** get_servicehistory();
	friend ostream& operator<<(ostream&, const Vehicle&);
	~Vehicle();
};

Vehicle::Vehicle()
{
	vId = 0;
	registrationNo = 0;
	avgMileage = 0.0;
	LicenceType = 0;
	status = 0;
	fueltype = 0;
	overallRanking = 0.0;
	list = 0;
	serviceHistory = 0;
}

Vehicle::Vehicle(int vhlID, int reg_no, int mlg, char* lsnc, bool stat, char* fuel, float rank, Date mandate, Feature* featurelist, Service** svrchis)
{
	vId = vhlID;
	registrationNo = reg_no;
	avgMileage = mlg;
	LicenceType = lsnc;
	status = stat;
	fueltype = fuel;
	overallRanking = rank;
	manufacturingDate = mandate;
	list = featurelist;
	serviceHistory = svrchis;
}

Vehicle::Vehicle(const Vehicle& obj)
{
	vId = obj.vId;
	registrationNo = obj.registrationNo;
	avgMileage = obj.avgMileage;
	LicenceType = obj.LicenceType;
	status = obj.status;
	fueltype = obj.fueltype;
	overallRanking = obj.overallRanking;
	list = obj.list;
	serviceHistory = obj.serviceHistory;
	manufacturingDate = obj.manufacturingDate;
}

void Vehicle::set_vehicleID(int vhlID)
{
	vId = vhlID;
}

void Vehicle::set_registrationo(int reg_no)
{
	registrationNo = reg_no;
}

void Vehicle::set_averagemilage(int mlg)
{
	avgMileage = mlg;
}

void Vehicle::set_liscencetype(char* lsnc)
{
	LicenceType = lsnc;
}

void Vehicle::set_status(bool stat)
{
	status = stat;
}

void Vehicle::set_fueltype(char* fuel)
{
	fueltype = fuel;
}

void Vehicle::set_overallranking(float rank)
{
	overallRanking = rank;
}

void Vehicle::set_manufacturingdate(Date mandate)
{
	manufacturingDate = mandate;
}

void Vehicle::set_featurelist(Feature* featurelist)
{
	list = featurelist;
}

void Vehicle::set_servicehistory(Service** svrchis)
{
	serviceHistory = svrchis;
}

int Vehicle::get_vehicleID()
{
	return vId;
}

int Vehicle::get_registrationo()
{
	return registrationNo;
}

float Vehicle::get_averagemilage()
{
	return avgMileage;
}

char* Vehicle::get_liscencetype()
{
	return LicenceType;
}

bool Vehicle::get_status()
{
	return status;
}

char* Vehicle::get_fueltype()
{
	return fueltype;
}

float Vehicle::get_overallranking()
{
	return overallRanking;
}

Date Vehicle::get_manufacturingdate()
{
	return manufacturingDate;
}

Feature* Vehicle::get_featurelist()
{
	return list;
}

Service** Vehicle::get_servicehistory()
{
	return serviceHistory;
}

ostream& operator<<(ostream& out, const Vehicle& obj)
{
	out << obj.vId << endl;
	out << obj.registrationNo << endl;
	out << obj.avgMileage << endl;
	out << obj.LicenceType << endl;
	out << obj.overallRanking << endl;
	out << obj.fueltype << endl;
	out << obj.list << endl;
	out << obj.manufacturingDate << endl;
	out << obj.status << endl;
	out << obj.serviceHistory << endl;
	return out;
}

Vehicle::~Vehicle()
{
	delete[] LicenceType;
	LicenceType = nullptr;
	delete[] fueltype;
	fueltype = nullptr;
	delete[] list;
	list = nullptr;
	for (int i = 0; i < 20; i++)
	{
		delete[] serviceHistory[i];
	}
	serviceHistory = nullptr;
}

int i = 1, j = 1, k = 1;
// i Is For The Number Of Customers
// j Is For The Number Of Drivers
// k Is For The Number Of Vehicles
class TMS
{
private:
	Customer* c;
	Vehicle* v;
	Driver* d;
public:
	TMS();
	void new_customer();//a
	void new_driver();//b
	void remove_driver();//c
	void add_vehicle();//d
	void remove_vehicle();//e
	void list_of_customers();//f
	void list_of_drivers();//g
	void vehicles_complete_data();//h
	void service_history_vehicle();//i
	void customer_services();//j
	void driver_services();//k
	void driver_ranking();//l
	void multiple_lsc_drivers();//m
	void salary_updated();//n
	void service_request();//o
	void cancel_request();//p
	void complete_service();//q
	void same_vehicle();//r
	void same_day_delivery();//s
	void date_pending_delivery();//t
	void driver_pending_delivery();//u
	void cancelled_customer_services();//v
	~TMS();
};

TMS::TMS()
{
	c = new Customer[15];// Max Number Of Custromers Are 15
	d = new Driver[10];// Max Number Of Drivers Are 10
	v = new Vehicle[20];// Max Number Of Vehicles Are 20
}

void TMS::new_customer()
{
	char first_name[10];
	char last_name[10];
	int age, date, month, year, id;

	cout << endl;

	cout << "=============== New Customer ===============" << endl << endl;
	cout << "First Name:  ";
	cin.ignore();
	cin.getline(first_name, 10);
	cout << endl;
	cout << "Last Name:  ";
	cin.getline(last_name, 10);
	cout << endl;
	cout << "Age:  ";
	cin >> age;
	cout << endl;
	cout << "Date Of Birth(dd/mm//yyyy)";
	cout << endl;
	cout << endl;
	cout << "Enter Date:  ";
	cin >> date;
	cout << "Enter Month:  ";
	cin >> month;
	cout << "Enter Year:  ";
	cin >> year;

	c[i].set_age(age);
	c[i].set_fname(first_name);
	c[i].set_lname(last_name);
	c[i].set_DOB(date, month, year);
	srand((unsigned)time(NULL));
	id = rand();
	c[i].set_customerID(id);
	cout << endl;

	cout << "Customer Id Is:  " << c[i].get_customerID();
	cout << endl;

	ofstream out("Customer_List.txt", ios::app);

	out << i << endl;
	out << c[i].get_fname() << endl;
	out << c[i].get_lname() << endl;
	out << c[i].get_age() << endl;
	out << date << endl;
	out << month << endl;
	out << year << endl;
	cout << endl;
	out << c[i].get_customerID() << endl;
	out.close();
	i++;
}

void TMS::new_driver()
{
	char first_name[10];
	char second_name[10];
	int age, id, salary, experience, numberofliscences, date, month, year;
	float ranking = 3;
	int* liscences;



	cout << "===============  New Driver  ===============" << endl << endl;

	cout << "First Name:  ";
	cin.ignore();
	cin.getline(first_name, 10);
	cout << endl;
	cout << "Last Name:  ";
	cin.getline(second_name, 10);
	cout << endl;
	cout << "Age:  ";
	cin >> age;
	cout << endl;
	cout << "Date Of Birth(dd/mm/yyyy)";
	cout << endl << endl;
	cout << "Date:  ";
	cin >> date;
	cout << endl;
	cout << "Month:  ";
	cin >> month;
	cout << endl;
	cout << "Year:  ";
	cin >> year;
	cout << endl;
	cout << "Enter Salary:  ";
	cin >> salary;
	cout << endl;
	cout << "Enter Experience:  ";
	cin >> experience;
	cout << endl;
	cout << "Number Of Liscences:  ";
	cin >> numberofliscences;
	cout << endl;

	liscences = new int[numberofliscences];
	for (int f = 0; f < numberofliscences; f++)
	{
		cout << "Enter Liscence Number:  ";
		cin >> liscences[i];
		cout << endl;
	}

	d[j].set_age(age);
	d[j].set_fname(first_name);
	d[j].set_lname(second_name);
	d[j].set_noofliscences(numberofliscences);
	d[j].set_experience(experience);
	d[j].set_overallranking(ranking);
	d[j].set_salary(salary);
	d[j].set_lisenceslist(liscences);
	srand((unsigned)time(NULL));
	id = rand();
	d[j].set_driverId(id);

	cout << endl;
	cout << "Driver ID Is:  " << d[j].get_driverId();

	ofstream output("Driver_List.txt", ios::app);

	output << j << endl;
	output << d[j].get_fname() << endl;
	output << d[j].get_lname() << endl;
	output << d[j].get_age() << endl;
	output << date << endl;
	output << month << endl;
	output << year << endl;
	output << d[j].get_driverId() << endl;
	output << d[j].get_experience() << endl;
	output << d[j].get_overallranking() << endl;
	output << d[j].get_salary() << endl;
	output << d[j].get_noofliscences() << endl;

	int* list;
	list = d[j].get_lisenceslist();

	for (int y = 0; y < numberofliscences; y++)
	{
		output << list[i];
		output << endl;
	}
	output.close();
	j++;
}

void TMS::remove_driver()
{
	char firstname[10][10]; char lastname[10][10]; int age[10]; int id1[10]; int date[10]; int month[10];
	int year[10]; int salary[10]; int  experience[10]; int numberofliscence[10]; int liscence[10];
	float overallranking[10];
	int Identity;

	ifstream input("Driver_List.txt");
	for (int i = 0; i < 10; i++)
	{
		input >> j;
		input >> firstname[i];
		input >> lastname[i];
		input >> age[i];
		input >> date[i];
		input >> month[i];
		input >> year[i];
		input >> id1[i];
		input >> experience[i];
		input >> overallranking[i];
		input >> salary[i];
		input >> numberofliscence[i];

		for (int l = 0; l < numberofliscence[i]; l++)
		{
			input >> liscence[i];
		}
	}
	input.close();

	cout << endl;
	cout << "===============  REMOVE  DRIVER  ===============" << endl << endl;

	cout << "Enter Driver Id:  ";
	cin >> Identity;

	ofstream output("Driver_List.txt");

	for (int q = 0; q < 10; q++)
	{
		if (date[q] > 0 && id1[q] != Identity)
		{
			output << j << endl;
			output << firstname[q] << endl;
			output << lastname[q] << endl;
			output << age[q] << endl;
			output << date[q] << endl;
			output << month[q] << endl;
			output << year[q] << endl;
			output << id1[q] << endl;
			output << experience[q] << endl;
			output << overallranking[q] << endl;
			output << salary[q] << endl;
			output << numberofliscence[q] << endl;

			for (int o = 0; o < numberofliscence[q]; o++)
			{
				output << liscence[q] << endl;
			}
		}
	}
	output.close();
}

void TMS::add_vehicle()
{
	int num_of_feat, cost = 0, date, month, year, registration_number, identity;
	float mlg; char liscence_type[10]; char fuel_Type[10];
	float rank = 2; Date Man; Feature* Lst;

	cout << endl;
	cout << "===============  NEW VEHICLE  ===============" << endl << endl;

	cout << "Vehicle's Registration Number:  ";
	cin >> registration_number;
	cout << endl;
	cout << "Vehicle's Average Milage:  ";
	cin >> mlg;
	cout << endl;
	cout << "Vehicle's Fuel Type:  ";
	cin.ignore();
	cin.getline(fuel_Type, 10);
	cout << endl;
	cout << "Vehicle's Liscence Type:  ";
	cin.getline(liscence_type, 10);
	cout << endl;
	cout << "Vehicle's Manufacture Date:  " << endl;

	cout << endl;
	cout << "Vehicle's Date Of Manufacture:  ";
	cin >> date;
	cout << endl;
	cout << "Vehicle's Month Of Manufacture:  ";
	cin >> month;
	cout << endl;
	cout << "Vehicle's Year Of Manufacture:  ";
	cin >> year;
	cout << endl;

	cout << "How Many Features Of Vehicle Do You Want To Enter?  ";
	cin >> num_of_feat;
	cout << endl;
	Lst = new Feature[num_of_feat];

	for (int w = 0; w < num_of_feat; w++)
	{
		char dscrption[20][100];//20 are The Total Number Of Vehicles And 100 For the Description Of Your Vehicle
		cout << "Description Of Vehicle:  ";
		cin.ignore();
		cin.getline(dscrption[w], 100);//w is for the number of vehicles and 100 is same for the description
		cout << endl;
		cout << "Cost Of Vehicle:  ";
		cin >> cost;
		cout << endl;
		Lst[w].set_description(dscrption[w]);
		Lst[w].set_cost(cost);
		srand((unsigned)time(NULL));
		identity = rand();
		Lst[w].set_featureID(identity);
		cout << endl;
	}

	Man.setDOB(date, month, year);//It is going to the Date Class For Setting The maanufacturing Date Of Your Vehicle
	v[k].set_overallranking(rank);
	v[k].set_averagemilage(mlg);
	v[k].set_liscencetype(liscence_type);
	v[k].set_fueltype(fuel_Type);
	v[k].set_registrationo(registration_number);
	v[k].set_manufacturingdate(Man);
	v[k].set_featurelist(Lst);
	srand((unsigned)time(NULL));
	identity = rand();
	v[k].set_vehicleID(identity);
	cout << endl;

	cout << v[k].get_vehicleID();
	cout << endl;

	ofstream output("Vehicle_List.txt", ios::app);

	output << k << endl;
	output << v[k].get_averagemilage() << endl;;
	output << num_of_feat << endl;

	Feature* List_Of_Features = v[k].get_featurelist();
	for (int x = 0; x < num_of_feat; x++)
	{
		output << List_Of_Features[x];
	}
	cout << endl;

	output << v[k].get_fueltype() << endl;
	output << v[k].get_liscencetype() << endl;
	output << date << endl;
	output << month << endl;
	output << year << endl;
	output << v[k].get_overallranking() << endl;
	output << v[k].get_registrationo() << endl;
	output << v[k].get_vehicleID() << endl;

	output.close();

	k++;
}

void TMS::remove_vehicle()
{
	int remove_id;
	int num_of_feat[20], cost = 0, date[20], month[20], year[20], registration_number[20], identity[20];
	char list_of_features[20][10];
	float mlg[20]; char liscence_type[20][10]; char fuel_Type[20][10];
	float rank[20];
	char dstination[20][20][25];
	char feature_id[20][20][25];
	char cost_of_vhl[20][20][25];

	cout << endl << endl;

	cout << "===============  VEHICLE REMOVED  ===============" << endl << endl;
	cout << "Enter Vehicle ID:  ";
	cin >> remove_id;
	cout << endl;

	ifstream inputvehicle("Vehicle_List.txt");

	for (int e = 0; e < 20; e++)
	{
		inputvehicle >> k;
		inputvehicle >> mlg[e];
		inputvehicle >> num_of_feat[e];
		for (int i = 0; i < num_of_feat[e]; i++)
		{

			inputvehicle >> feature_id[e][i];
			inputvehicle.getline(dstination[e][i], 25);
			inputvehicle.getline(dstination[e][i], 25);
			inputvehicle >> cost_of_vhl[e][i];
		}
		inputvehicle >> fuel_Type[e];
		inputvehicle >> liscence_type[e];
		inputvehicle >> date[e];
		inputvehicle >> month[e];
		inputvehicle >> year[e];
		inputvehicle >> rank[e];
		inputvehicle >> registration_number[e];
		inputvehicle >> identity[e];
	}
	inputvehicle.close();

	ofstream outputvehicle("Vehicle_List.txt");
	for (int f = 0; f < 20; f++)
	{
		if (date[f] > 0 && remove_id != identity[f])
		{
			outputvehicle << k << endl;
			outputvehicle << mlg[f] << endl;
			outputvehicle << num_of_feat[f] << endl;
			for (int i = 0; i < num_of_feat[f]; i++)
			{
				outputvehicle << list_of_features[f];
			}
			outputvehicle << fuel_Type[f] << endl;
			outputvehicle << liscence_type[f] << endl;
			outputvehicle << date[f] << endl;
			outputvehicle << month[f] << endl;
			outputvehicle << year[f] << endl;
			outputvehicle << rank[f] << endl;
			outputvehicle << registration_number[f] << endl;
			outputvehicle << identity[f] << endl;
		}
	}
	outputvehicle.close();

}

void TMS::list_of_customers()
{
	char firstname[15][10];//15 Customers and 10 the Length of first Name
	char lastname[15][10];//15 Customers and 10 the Length of second Name
	int age[15], date[15], month[15], year[15], identity[15];

	ifstream input("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		input >> i;
		input >> firstname[k];
		input >> lastname[k];
		input >> age[k];
		input >> date[k];
		input >> month[k];
		input >> year[k];
		input >> identity[k];
	}
	input.close();

	cout << endl;
	cout << "===============  CUSTOMER'S DETAILS  ===============" << endl << endl;

	for (int f = 0; f < 15; f++)
	{
		if (identity[f] > 0)
		{
			cout << "Customer's First Name:  " << firstname[f] << endl;
			cout << "Customer's Last Name:  " << lastname[f] << endl;
			cout << "Customer's Date Of Birth:  " << date[f] << "/" << month[f] << "/" << year[f] << endl;
			cout << "Customer ID:  " << identity[f] << endl;
			cout << endl;
		}
	}
}


void TMS::list_of_drivers()
{
	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity[10], date[10], month[10], year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[r];
		}
	}
	input.close();

	cout << endl;
	cout << "===============  DRIVER'S DETAILS  ===============" << endl << endl;

	for (int x = 0; x < 10; x++)
	{
		if (age[x] > 0)
		{
			cout << "Driver's First Name:  " << firstname[x] << endl;
			cout << "Driver's Last Name:  " << lastname[x] << endl;
			cout << "Driver's Age:  " << age[x] << endl;
			cout << "Driver's Date Of Birth:  " << date[x] << "/" << month[x] << "/" << year[x] << endl;
			cout << "Driver's ID:  " << identity[x] << endl;
			cout << "Driver's Experience:  " << exp[x] << endl;
			cout << "Driver's Ranking:  " << ranking[x] << endl;
			cout << "Driver's Salary:  " << salary[x] << endl;
			cout << "Driver's Number Of Liscences:  " << numberofliscence[x] << endl;
			cout << "Liscence Numbers:  ";
			for (int y = 0; y < numberofliscence[x]; y++)
			{
				cout << liscense_number[y] << "     ";
			}
			cout << endl;
			cout << endl;
		}
	}
}

void TMS::vehicles_complete_data()
{
	int number_of_features[20];
	int cost[20][10];//20 are the number of vehicles and 10 is the cost of vehicle through features 
	char dscription[20][20][25];//20 are the number of vehicles , 20 are the lines of description and in each line it could be of 100 words
	int date[20], month[20], year[20];//20 for each of the vehicles manufacture date
	int identity[20];
	int feature_id[20][10];//10 is for different feature id's as inheriting from feature class
	int registration_number[20];
	float rank[20];
	char liscence_type[20][10];//20 for vehicles and 10 for the words in each line
	char fuel_type[20][10];//20 for vehicles and 10 for the words in each line
	float mlg[20];

	ifstream input("Vehicle_List.txt");

	for (int b = 0; b < 20; b++)
	{
		input >> k;
		input >> mlg[b];
		input >> number_of_features[b];
		for (int h = 0; h < number_of_features[b]; h++)
		{
			input >> feature_id[b][h];
			input.getline(dscription[b][h], 50);
			input.getline(dscription[b][h], 50);
			input >> cost[b][h];
		}

		input.getline(fuel_type[b], 10);
		input.getline(liscence_type[b], 10);
		input.getline(liscence_type[b], 10);
		input >> date[b];
		input >> month[b];
		input >> year[b];
		input >> rank[b];
		input >> registration_number[b];
		input >> identity[b];
	}
	input.close();

	cout << endl;
	cout << "===============  VEHICLE'S DETAILS  ===============" << endl << endl;

	for (int p = 0; p < 20; p++)
	{
		if (registration_number[p] > 0)
		{
			cout << "Vehicle's Registration Number:  " << registration_number[p] << endl;
			cout << "Vehicle's ID:  " << identity[p] << endl;
			cout << "Vehicle's Category:  " << liscence_type[p] << endl;
			cout << "Vehicle's Date Of Manufaturing:  " << date[p] << "/" << month[p] << "/" << year[p] << endl;
			cout << "Vehicle's Ranking:  " << rank[p] << endl;
			if (number_of_features[p] > 0)
			{
				for (int k = 0; k < number_of_features[p]; k++)
				{
					cout << "Vehicle's Feature Id:  " << feature_id[p][k] << endl;
					cout << "Description Of Vehicle:  " << dscription[p][k] << endl;
					cout << "Cost Of Vehicle:  " << cost[p][k] << endl;
				}
			}
			cout << endl;
		}
	}
}

void TMS::multiple_lsc_drivers()
{
	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity[10], date[10], month[10], year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[t];
		}
	}
	input.close();

	cout << endl;
	cout << "===============  DRIVERS WITH MULTIPLE LISCENCES  ===============" << endl << endl;

	for (int r = 0; r < 10; r++)
	{
		if (numberofliscence[r] >= 2)
		{
			cout << "Driver's First Name:  " << firstname[r] << endl;
			cout << "Driver's Last Name:  " << lastname[r] << endl;
			cout << "Driver's Age:  " << age[r] << endl;
			cout << "Driver's Date Of Birth:  " << date[r] << "/" << month[r] << "/" << year[r] << endl;
			cout << "Driver's ID:  " << identity[r] << endl;
			cout << "Driver's Experience:  " << exp[r] << endl;
			cout << "Driver's Ranking:  " << ranking[r] << endl;
			cout << "Driver's Salary:  " << salary[r] << endl;
			cout << "Driver's Number Of Liscences:  " << numberofliscence[r] << endl;
			cout << "Liscence Numbers:  ";
			for (int y = 0; y < numberofliscence[r]; y++)
			{
				cout << liscense_number[r] << "     ";
			}
			cout << endl;
			cout << endl;
		}
	}
}

void TMS::salary_updated()
{
	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity[10], date[10], month[10], year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[t];
		}
	}
	input.close();

	cout << endl;

	int salary_check = 0;
	cout << "============== UPDATED SALARY OF DRIVERS  ===============" << endl << endl;
	for (int p = 0; p < 10; p++)
	{
		if (ranking[p] > 4.5)
		{
			salary[p] = salary[p] + (salary[p] * (0.15));
			salary_check++;
		}
	}

	for (int x = 0; x < 10; x++)
	{
		if (date[x] > 0)
		{
			cout << "===============  SALARY IS UPDATED  ===============" << endl << endl;
			cout << "Driver's First Name:  " << firstname[x] << endl;
			cout << "Driver's Last Name:  " << lastname[x] << endl;
			cout << "Driver's Age:  " << age[x] << endl;
			cout << "Driver's Date Of Birth:  " << date[x] << "/" << month[x] << "/" << year[x] << endl;
			cout << "Driver's ID:  " << identity[x] << endl;
			cout << "Driver's Experience:  " << exp[x] << endl;
			cout << "Driver's Ranking:  " << ranking[x] << endl;
			cout << "Driver's Updated Salary:  " << salary[x] << endl;
			cout << "Driver's Number Of Liscences:  " << numberofliscence[x] << endl;
			cout << "Liscence Numbers:  ";
			for (int y = 0; y < numberofliscence[x]; y++)
			{
				cout << liscense_number[x] << "     ";
			}
			cout << endl;
		}
	}

	ofstream output("Driver_List.txt");
	for (int j = 0; j < 10; j++)
	{
		if (date[j] > 0)
		{
			output << j << endl;
			output << firstname[j] << endl;
			output << lastname[j] << endl;
			output << age[j] << endl;
			output << date[j] << endl;
			output << month[j] << endl;
			output << year[j] << endl;
			output << identity[j] << endl;
			output << exp[j] << endl;
			output << ranking[j] << endl;
			output << salary[j] << endl;
			output << numberofliscence[j] << endl;
			for (int r = 0; r < numberofliscence[j]; r++)
			{
				output << liscense_number[j] << endl;
			}
		}
	}
	output.close();
}

void TMS::driver_ranking()
{
	int status[20]; int count[10] = { 0 }; float updated_rank[10] = { 0 }; int vhl_date[20], vhl_month[20], vhl_year[20], vhl_hour[20], vhl_min[20], vhl_sec[20];
	int vhl_fuel_cost[20]; int distance_to_travel[20]; int psngr[20]; int identity[20];
	char src[20][20]; char dstination[20][20]; char ride_tp[20][20];//20 are the number of vehicles and 20 are the words in the destination

	int driver_id[20]; int vehicle_id[20]; int service_id[20]; float driver_rnk[20]; float vehicle_rnk[20];
	float fare_for_travel[20];//20 are the number of vehicles in the program

	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity1[10], date[10], month[10], year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	cout << endl;
	cout << "===============  BEST DRIVERS  ===============" << endl << endl;

	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity1[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[t];
		}
	}
	input.close();



	ifstream inputride("Ride_Services_List.txt");

	for (int q = 0; q < 20; q++)
	{
		inputride >> service_id[q];
		inputride >> identity[q];
		inputride >> psngr[q];
		inputride.getline(ride_tp[q], 20);
		inputride.getline(ride_tp[q], 20);
		inputride >> distance_to_travel[q];
		inputride.getline(src[q], 20);
		inputride.getline(src[q], 20);
		inputride.getline(dstination[q], 20);
		inputride >> vhl_fuel_cost[q];
		inputride >> driver_id[q];
		input >> driver_rnk[q];
		inputride >> vehicle_id[q];
		inputride >> vehicle_rnk[q];
		inputride >> vhl_date[q];
		inputride >> vhl_month[q];
		inputride >> vhl_year[q];
		inputride >> vhl_hour[q];
		inputride >> vhl_min[q];
		inputride >> vhl_sec[q];
		inputride >> status[q];
		input >> fare_for_travel[q];
	}
	inputride.close();


	for (int a = 0; a < 10; a++)//10 are the number of drivers
	{
		for (int b = 0; b < 20; b++)//20 is the number of vehicles and 10 differnent drivers have droven it 20 times
		{
			if (identity1[a] > 0 && identity1[a] == driver_id[b])
			{
				count[a]++;
				updated_rank[a] += driver_rnk[b];//updated rank=updatedrank+driver's previous rank
			}
		}
	}

	for (int c = 0; c < 10; c++)
	{
		if (count[c] > 0)
		{
			ranking[c] = updated_rank[c] / count[c];//Ranking is given on the basis of total ranking divided by total number of rides he have taken
		}
	}

	for (int f = 0; f < 10; f++)
	{
		if (ranking[f] > 4.5)
		{
			cout << "Driver's First Name:  " << firstname[f] << endl;
			cout << "Driver's Last Name:  " << lastname[f] << endl;
			cout << "Driver's Age:  " << age[f] << endl;
			cout << "Driver's Date Of Birth:  " << date[f] << "/" << month[f] << "/" << year[f] << endl;
			cout << "Driver's ID:  " << identity[f] << endl;
			cout << "Driver's Experience:  " << exp[f] << endl;
			cout << "Driver's Ranking:  " << ranking[f] << endl;
			cout << "Driver's Salary:  " << salary[f] << endl;
			cout << "Driver's Number Of Liscences:  " << numberofliscence[f] << endl;
			cout << "Liscence Numbers:  ";
			for (int y = 0; y < numberofliscence[f]; y++)
			{
				cout << liscense_number[f] << "     ";
			}
			cout << endl;
		}
	}

	ofstream output("Driver_List.txt");
	for (int j = 0; j < 10; j++)
	{
		if (date[j] > 0)
		{
			output << j << endl;
			output << firstname[j] << endl;
			output << lastname[j] << endl;
			output << age[j] << endl;
			output << date[j] << endl;
			output << month[j] << endl;
			output << year[j] << endl;
			output << identity[j] << endl;
			output << exp[j] << endl;
			output << ranking[j] << endl;
			output << salary[j] << endl;
			output << numberofliscence[j] << endl;
			for (int r = 0; r < numberofliscence[j]; r++)
			{
				output << liscense_number[j] << endl;
			}
		}
	}
	output.close();

}

void TMS::same_vehicle()
{
	int ride_check = 0;
	int status[20];
	int vhl_date[20], vhl_month[20], vhl_year[20], vhl_hour[20], vhl_min[20], vhl_sec[20];
	int vhl_fuel_cost[20]; int distance_to_travel[20]; int psngr[20]; int identity_of_passenger[20];
	char src[20][20]; char dstination[20][20]; char ride_tp[20][20];//20 are the number of vehicles and 20 are the words in the destination
	int driver_id[20]; int vehicle_id[20]; int service_id[20]; float driver_rnk[20]; float vehicle_rnk[20];
	float fare_for_travel[20];//20 are the number of vehicles in the program

	char firstname[15][10];//Total Number Of Customers Are 15 And Max Name Length Is 10
	char lastname[15][10];
	int age[15], identity[15], date[15], month[15], year[15];

	cout << endl;

	cout << "============== SAME VEHICLES  ===============" << endl << endl;

	ifstream input("Customer_List.txt");

	for (int t = 0; t < 15; t++)
	{
		input >> i;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
	}
	input.close();

	ifstream inputride("Ride_Services_List.txt");

	for (int q = 0; q < 20; q++)
	{
		inputride >> service_id[q];
		inputride >> identity_of_passenger[q];
		inputride >> psngr[q];
		inputride.getline(ride_tp[q], 20);
		inputride.getline(ride_tp[q], 20);
		inputride >> distance_to_travel[q];
		inputride.getline(src[q], 20);
		inputride.getline(src[q], 20);
		inputride.getline(dstination[q], 20);
		inputride >> vhl_fuel_cost[q];
		inputride >> driver_id[q];
		inputride >> driver_rnk[q];
		inputride >> vehicle_id[q];
		inputride >> vehicle_rnk[q];
		inputride >> vhl_date[q];
		inputride >> vhl_month[q];
		inputride >> vhl_year[q];
		inputride >> vhl_hour[q];
		inputride >> vhl_min[q];
		inputride >> vhl_sec[q];
		inputride >> status[q];
		inputride >> fare_for_travel[q];
	}
	inputride.close();

	for (int m = 0; m < 20; m++)//20 vehicles
	{
		for (int n = 0; n < 20; n++)//20 customers for 20 vehicles
		{

			if (identity[m] == identity_of_passenger[n] && vehicle_id[m] == vehicle_id[n] && (vhl_date[m] != vhl_date[n] || vhl_month[m] != vhl_month[n] || vhl_year[m] != vhl_year[n]))
			{
				cout << "Customer's First Name:  " << firstname[m] << endl;
				cout << "Customer's Last Name:  " << lastname[m] << endl;
				cout << "Customer's Age:  " << age[m] << endl;
				cout << "Date Of Birth:  " << date[m] << "/" << month[m] << "/" << year[m] << endl;
				cout << endl;
				cout << "Customer's ID:  " << identity[m] << endl;
				cout << endl;

				cout << "Vehicle's Service ID:  " << service_id[m] << endl;
				cout << "Customer's ID When Passenger:  " << identity_of_passenger[m] << endl;
				cout << "Number Of Passengers:  " << psngr[m] << endl;
				cout << "Ride Type:  " << ride_tp[m] << endl;//intercity or intracity
				cout << "Start Of Journey:  " << src[m] << endl;
				cout << "End Of Journey:  " << dstination[m] << endl;
				cout << "Distance Of Travel:  " << distance_to_travel[m] << endl;
				cout << "Date Of Booking:  " << vhl_date[m] << "/" << vhl_month[m] << "/" << vhl_year[m] << endl;
				cout << "Time Of Booking:  " << vhl_hour[m] << ":" << vhl_min[m] << ":" << vhl_sec[m] << endl;
				cout << "Fare For Travel:  " << fare_for_travel[m] << endl;
				cout << "Status Of Booking:  " << status[m] << endl;
				cout << "Rank Of Driver:  " << driver_rnk[m] << endl;
				cout << "Rank Of Vehicle:  " << vehicle_rnk[m] << endl;
				cout << endl << endl;

				cout << "Service ID: " << service_id[n] << endl;
				cout << "Customer ID: " << identity[n] << endl;
				cout << "No of Passengers: " << psngr[n] << endl;
				cout << "Ride Type: " << ride_tp[n] << endl;
				cout << "Source: " << src[n] << endl;
				cout << "Destination: " << dstination[n] << endl;
				cout << "Distance: " << distance_to_travel[n] << endl;
				cout << "Date of Booking: " << vhl_date[n] << " " << vhl_month[n] << " " << vhl_year[n] << endl;
				cout << "Time of Booking: " << vhl_hour[n] << " : " << vhl_min[n] << " : " << vhl_sec[n] << endl;
				cout << "Fare: " << fare_for_travel[n] << endl;
				cout << "Status of Booking: " << status[n] << endl;
				cout << "Driver Ranked: " << driver_rnk[n] << endl;
				cout << "Vehicle Ranked: " << vehicle_rnk[n] << endl;
				cout << endl << endl;
				ride_check++;
			}
		}
	}
	cout << ride_check << endl;
}

void TMS::same_day_delivery()
{
	int same_delivery_check = 0;
	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity[10], date[10], month[10], year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	int dri_date[10], dri_month[10], dri_year[10];
	int status[20]; int vhl_date[20], vhl_month[20], vhl_year[20], vhl_hour[20], vhl_min[20], vhl_sec[20];
	int vhl_fuel_cost[20]; int distance_to_travel[20]; int wgt[20]; int identity2[20];
	char src[20][20]; char dstination[20][20]; char goods_tp[20][20];//20 are the number of vehicles and 20 are the words in the destination

	int driver_id[20]; int vehicle_id[20]; int service_id[20];
	float fare_for_travel[20];//20 are the number of vehicles in the program

	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> dri_date[t];
		input >> dri_month[t];
		input >> dri_year[t];
		input >> identity[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[t];
		}
	}
	input.close();

	ifstream input_delivery("Delivery_Services_List.txt");
	for (int a = 0; a < 20; a++)
	{
		input_delivery >> service_id[a];
		input_delivery >> identity2[a];
		input_delivery >> wgt[a];
		input_delivery.getline(goods_tp[a], 20);
		input_delivery.getline(goods_tp[a], 20);
		input_delivery >> distance_to_travel[a];
		input_delivery.getline(src[a], 20);
		input_delivery.getline(src[a], 20);
		input_delivery.getline(dstination[a], 20);
		input_delivery >> vhl_fuel_cost[a];
		input_delivery >> driver_id[a];
		input_delivery >> vehicle_id[a];
		input_delivery >> vhl_date[a];
		input_delivery >> vhl_month[a];
		input_delivery >> vhl_year[a];
		input_delivery >> vhl_hour[a];
		input_delivery >> vhl_min[a];
		input_delivery >> vhl_sec[a];
		input_delivery >> status[a];
		input_delivery >> fare_for_travel[a];
	}
	input_delivery.close();

	ifstream input_complete("Completed_Service.txt");
	for (int i = 0; i < 20; i++)
	{
		input_complete >> date[i];
		input_complete >> month[i];
		input_complete >> year[i];
	}
	input_complete.close();

	cout << endl;

	cout << "===============  DELIVERY ON SAME DAY ===============" << endl << endl;

	for (int m = 0; m < 20; m++)
	{
		if (date[m] == vhl_date[m] && month[m] == vhl_month[m] && year[m] == vhl_year[m] && year[m] > 0)
		{
			for (int n = 0; n < 10; n++)
			{
				if (driver_id[m] == identity[n] && (driver_id[m] > 0) && (identity[m] > 0))
				{
					cout << "Driver's First Name: " << firstname[n] << endl;
					cout << "Driver's Last Name: " << lastname[n] << endl;
					cout << "Driver's Age: " << age[n] << endl;
					cout << "Driver's Date of Birth: " << date[n] << " " << month[n] << " " << year[n] << endl;
					cout << "Driver's ID: " << identity[n] << endl;
					cout << "Driver's Experience: " << exp[n] << endl;
					cout << "Driver's Overall Ranking: " << ranking[n] << endl;
					cout << "Salary: " << salary[n] << endl;
					cout << "Number of Liscences: " << numberofliscence[n] << endl;
					cout << "Liscences: ";
					for (int k = 0; k < numberofliscence[n]; k++)
					{
						cout << liscense_number[n] << "  ";
					}
					cout << endl << endl;
					same_delivery_check++;
				}
			}
			cout << "Service ID: " << service_id[m] << endl;
			cout << "Customer ID: " << identity2[m] << endl;
			cout << "Driver ID: " << driver_id[m] << endl;
			cout << "Goods Type: " << goods_tp[m] << endl;
			cout << "Goods Weight: " << wgt[m] << endl;
			cout << "Source: " << src[m] << endl;
			cout << "Destination: " << dstination[m] << endl;
			cout << "Distance: " << distance_to_travel[m] << endl;
			cout << "Date of Booking: " << vhl_date[m] << " " << vhl_month[m] << " " << vhl_year[m] << endl;
			cout << "Time of Booking: " << vhl_hour[m] << " : " << vhl_min[m] << " : " << vhl_sec[m] << endl;
			cout << "Status of Booking: " << status[m] << endl;
			cout << "Date of Delivery: " << date[m] << " " << month[m] << " " << year[m] << endl;
			cout << "Fare: " << fare_for_travel[m] << endl;
			cout << endl << endl;
			same_delivery_check++;
		}
	}

	if (same_delivery_check == 0)
	{
		cout << "There Are No Drivers Which Completed The Deliveries On The Same Day!!!" << endl;
	}
}

void TMS::date_pending_delivery()
{
	int check_date, check_month, check_year;
	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	cout << endl;

	cout << "=============== SERVICES PENDINGS ON A PARTICULAR DATE  ===============" << endl << endl;

	cout << "Enter Date For Checking The Pending Services" << endl;
	cout << endl;
	cout << "Enter Date:  ";
	cin >> check_date;
	cout << endl;
	cout << "Enter Month:  ";
	cin >> check_month;
	cout << endl;
	cout << "Enter Year:  ";
	cin >> check_year;
	cout << endl;

	int pending_check = 0;
	ifstream inputride("Ride_Services_List.txt");
	for (int q = 0; q < 20; q++)
	{
		inputride >> ride_service_id[q];
		inputride >> ride_passenger_id[q];
		inputride >> ride_psngr[q];
		inputride.getline(delivery_ride_tp[q], 20);
		inputride.getline(delivery_ride_tp[q], 20);
		inputride >> ride_distance[q];
		inputride.getline(ride_src[q], 20);
		inputride.getline(ride_src[q], 20);
		inputride.getline(ride_dstination[q], 20);
		inputride >> ride_fuel[q];
		inputride >> ride_dvr_id[q];
		inputride >> ride_dvr_rank[q];
		inputride >> ride_vhl_id[q];
		inputride >> ride_vehicle_rank[q];
		inputride >> ride_date[q];
		inputride >> ride_month[q];
		inputride >> ride_year[q];
		inputride >> ride_hour[q];
		inputride >> ride_min[q];
		inputride >> ride_sec[q];
		inputride >> ride_status[q];
		inputride >> ride_fare_for_travel[q];
	}
	inputride.close();

	cout << endl << endl << endl;

	for (int f = 0; f < 20; f++)
	{
		if (ride_date[f] == check_date && ride_month[f] == check_month && ride_year[f] == check_year && ride_status[f] == 0)
		{
			cout << "=============== RIDES PENDING  ===============" << endl << endl;
			cout << "Service ID:  " << ride_service_id[f] << endl;
			cout << "Driver ID:  " << ride_dvr_id[f] << endl;
			cout << "Date Of Booking:  " << ride_date[f] << "/" << ride_month[f] << "/" << ride_year[f] << endl;
			cout << "Time Of Booking:  " << ride_hour[f] << "/" << ride_min[f] << "/" << ride_sec[f] << endl;
			cout << "Ride Type:  " << delivery_ride_tp[f] << endl;
			cout << "Source Of Ride:  " << ride_src[f] << endl;
			cout << "Destination Of Ride:  " << ride_dstination[f] << endl;
			cout << "Distance Of Travel:  " << ride_distance[f] << endl;
			cout << "Fare For Travel:  " << ride_fare_for_travel[f] << endl;
			cout << "Status Of Booking:  " << ride_status[f] << endl;
			cout << "Driver Ranked:  " << ride_dvr_rank[f] << endl;
			cout << endl << endl;
			pending_check++;
		}
	}

	ifstream input_delivery("Delivery_Services_List.txt");

	for (int a = 0; a < 20; a++)
	{
		input_delivery >> delivery_service_id[a];
		input_delivery >> delivery_goods_id[a];
		input_delivery >> delivery_wgt[a];
		input_delivery.getline(delivery_goods_tp[a], 20);
		input_delivery.getline(delivery_goods_tp[a], 20);
		input_delivery >> delivery_distance[a];
		input_delivery.getline(delivery_src[a], 20);
		input_delivery.getline(delivery_src[a], 20);
		input_delivery.getline(delivery_dstination[a], 20);
		input_delivery >> delivery_fuel[a];
		input_delivery >> delivery_dvr_id[a];
		input_delivery >> delivery_vhl_id[a];
		input_delivery >> delivery_date[a];
		input_delivery >> delivery_month[a];
		input_delivery >> delivery_year[a];
		input_delivery >> delivery_hour[a];
		input_delivery >> delivery_min[a];
		input_delivery >> delivery_sec[a];
		input_delivery >> delivery_status[a];
		input_delivery >> delivery_fare_for_travel[a];
	}
	input_delivery.close();

	for (int f = 0; f < 20; f++)
	{
		if (delivery_date[f] == check_date && delivery_month[f] == check_month && delivery_year[f] == check_year)
		{
			cout << "===============  PENDING GOODS  ===============" << endl << endl;
			cout << "Service ID:  " << delivery_service_id[f] << endl;
			cout << "Driver ID:  " << delivery_dvr_id[f] << endl;
			cout << "Date Of Booking:  " << delivery_date[f] << "/" << delivery_month[f] << "/" << delivery_year[f] << endl;
			cout << "Time Of Booking:  " << delivery_hour[f] << ":" << delivery_min[f] << ":" << delivery_sec[f] << endl;
			cout << "Goods Type:  " << delivery_ride_tp[f] << endl;
			cout << "Source Of Delivery:  " << delivery_src[f] << endl;
			cout << "Destination Of Delivery:  " << delivery_dstination[f] << endl;
			cout << "Distance Of Travel:  " << delivery_distance[f] << endl;
			cout << "Fare For Travel:  " << delivery_fare_for_travel[f] << endl;
			cout << "Status Of Booking:  " << delivery_status[f] << endl;
			cout << endl << endl;
			pending_check++;
		}
	}

	if (pending_check == 0)
	{
		cout << "There Are No Deliveries Pending On The Entered Particular Date" << endl << endl;
	}
}

void TMS::driver_pending_delivery()
{
	int check_driver_id;
	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	cout << endl << endl;

	cout << "===============  SERVICES PENDING OF DRIVER  ===============" << endl << endl;

	cout << "Enter The Driver ID:  ";
	cin >> check_driver_id;
	cout << endl;

	int pending_check = 0;
	ifstream inputride("Ride_Services_List.txt");
	for (int q = 0; q < 20; q++)
	{
		inputride >> ride_service_id[q];
		inputride >> ride_passenger_id[q];
		inputride >> ride_psngr[q];
		inputride.getline(delivery_ride_tp[q], 20);
		inputride.getline(delivery_ride_tp[q], 20);
		inputride >> ride_distance[q];
		inputride.getline(ride_src[q], 20);
		inputride.getline(ride_src[q], 20);
		inputride.getline(ride_dstination[q], 20);
		inputride >> ride_fuel[q];
		inputride >> ride_dvr_id[q];
		inputride >> ride_dvr_rank[q];
		inputride >> ride_vhl_id[q];
		inputride >> ride_vehicle_rank[q];
		inputride >> ride_date[q];
		inputride >> ride_month[q];
		inputride >> ride_year[q];
		inputride >> ride_hour[q];
		inputride >> ride_min[q];
		inputride >> ride_sec[q];
		inputride >> ride_status[q];
		inputride >> ride_fare_for_travel[q];
	}
	inputride.close();

	cout << endl << endl << endl;
	for (int f = 0; f < 20; f++)
	{
		if ((check_driver_id == ride_dvr_id[f]) && (ride_status[f] == 0))
		{
			cout << "=============== RIDES PENDING  ===============" << endl << endl;
			cout << "Service ID:  " << ride_service_id[f] << endl;
			cout << "Driver ID:  " << ride_dvr_id[f] << endl;
			cout << "Date Of Booking:  " << ride_date[f] << "/" << ride_month[f] << "/" << ride_year[f] << endl;
			cout << "Time Of Booking:  " << ride_hour[f] << "/" << ride_min[f] << "/" << ride_sec[f] << endl;
			cout << "Ride Type:  " << delivery_ride_tp[f] << endl;
			cout << "Source Of Ride:  " << ride_src[f] << endl;
			cout << "Destination Of Ride:  " << ride_dstination[f] << endl;
			cout << "Distance Of Travel:  " << ride_distance[f] << endl;
			cout << "Fare For Travel:  " << ride_fare_for_travel[f] << endl;
			cout << "Status Of Booking:  " << ride_status[f] << endl;
			cout << "Driver Ranked:  " << ride_dvr_rank[f] << endl;
			cout << endl << endl;
			pending_check++;
		}
	}

	ifstream input_delivery("Delivery_Services_List.txt");

	for (int a = 0; a < 20; a++)
	{
		input_delivery >> delivery_service_id[a];
		input_delivery >> delivery_goods_id[a];
		input_delivery >> delivery_wgt[a];
		input_delivery.getline(delivery_goods_tp[a], 20);
		input_delivery.getline(delivery_goods_tp[a], 20);
		input_delivery >> delivery_distance[a];
		input_delivery.getline(delivery_src[a], 20);
		input_delivery.getline(delivery_src[a], 20);
		input_delivery.getline(delivery_dstination[a], 20);
		input_delivery >> delivery_fuel[a];
		input_delivery >> delivery_dvr_id[a];
		input_delivery >> delivery_vhl_id[a];
		input_delivery >> delivery_date[a];
		input_delivery >> delivery_month[a];
		input_delivery >> delivery_year[a];
		input_delivery >> delivery_hour[a];
		input_delivery >> delivery_min[a];
		input_delivery >> delivery_sec[a];
		input_delivery >> delivery_status[a];
		input_delivery >> delivery_fare_for_travel[a];
	}
	input_delivery.close();

	for (int f = 0; f < 20; f++)
	{
		if ((check_driver_id == delivery_dvr_id[f]) && (delivery_status[f] == 0))
		{
			cout << "===============  PENDING GOODS  ===============" << endl << endl;
			cout << "Service ID:  " << delivery_service_id[f] << endl;
			cout << "Driver ID:  " << delivery_dvr_id[f] << endl;
			cout << "Date Of Booking:  " << delivery_date[f] << "/" << delivery_month[f] << "/" << delivery_year[f] << endl;
			cout << "Time Of Booking:  " << delivery_hour[f] << ":" << delivery_min[f] << ":" << delivery_sec[f] << endl;
			cout << "Goods Type:  " << delivery_ride_tp[f] << endl;
			cout << "Source Of Delivery:  " << delivery_src[f] << endl;
			cout << "Destination Of Delivery:  " << delivery_dstination[f] << endl;
			cout << "Distance Of Travel:  " << delivery_distance[f] << endl;
			cout << "Fare For Travel:  " << delivery_fare_for_travel[f] << endl;
			cout << "Status Of Booking:  " << delivery_status[f] << endl;
			cout << endl << endl;
			pending_check++;
		}
	}

	if (pending_check == 0)
	{
		cout << "There Are No Deliveries Pending Of The Particular Driver" << endl << endl;
	}

}

void TMS::cancelled_customer_services()
{
	int check_cancel_requests = 0;
	int data;
	int check_customer_id;
	char firstname[15][10];//Total Number Of Customers Are 15 And Max Name Length Is 10
	char lastname[15][10];
	int age[15], identity[15], date[15], month[15], year[15];

	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	int check_id = 0;


	ifstream input("Customer_List.txt");

	for (int t = 0; t < 15; t++)
	{
		input >> i;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
	}
	input.close();

	cout << endl << endl;
	cout << "===============  CUSTOMER CANCELLED SERVICES  ===============" << endl << endl;


	cout << "Enter Customer ID For checking it's cancelled services:  ";
	cin >> check_customer_id;
	cout << endl;

	for (int y = 0; y < 15; y++)
	{
		if (check_customer_id == identity[y])
		{
			check_id++;
		}
	}

	cout << endl << endl;

	if (check_id != 0)
	{
		cout << "Enter 1 to get the cancelled Delivery Services:  " << endl;
		cout << "Enter 2 to get the cancelled Ride Services:  " << endl;

		cin >> data;

		if (data == 1)
		{
			ifstream input_delivery("Delivery_Services_List.txt");

			for (int a = 0; a < 20; a++)
			{
				input_delivery >> delivery_service_id[a];
				input_delivery >> delivery_goods_id[a];
				input_delivery >> delivery_wgt[a];
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery >> delivery_distance[a];
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_dstination[a], 20);
				input_delivery >> delivery_fuel[a];
				input_delivery >> delivery_dvr_id[a];
				input_delivery >> delivery_vhl_id[a];
				input_delivery >> delivery_date[a];
				input_delivery >> delivery_month[a];
				input_delivery >> delivery_year[a];
				input_delivery >> delivery_hour[a];
				input_delivery >> delivery_min[a];
				input_delivery >> delivery_sec[a];
				input_delivery >> delivery_status[a];
				input_delivery >> delivery_fare_for_travel[a];
			}
			input_delivery.close();

			cout << endl << endl;

			for (int a = 0; a < 15; a++)
			{
				if (identity[a] == check_customer_id)
				{
					cout << endl << endl;
					cout << "Customer's First Name:  " << firstname[a] << endl;
					cout << "Customer's Last Name:  " << lastname[a] << endl;
					cout << "Customer's Age:  " << age[a] << endl;
					cout << "Customer's Date Of Birth:  " << date[a] << "/" << month[a] << "/" << year[a] << endl;
					cout << "Customer's ID:  " << identity[a] << endl;

					if (identity[a] == check_customer_id && delivery_status[a] == 2)
					{
						cout << "Service ID:  " << delivery_service_id[a] << endl;
						cout << "Good's ID:" << delivery_goods_id[a] << endl;
						cout << "Date Of Booking:  " << delivery_date[a] << "/" << delivery_month[a] << "/" << delivery_year[a] << endl;
						cout << "Time Of Booking:  " << delivery_hour[a] << ":" << delivery_min[a] << ":" << delivery_sec[a] << endl;
						cout << "Good's Weight:  " << delivery_wgt[a] << endl;
						cout << "Good's Ride Type:  " << delivery_goods_tp[a] << endl;
						cout << "Source Of Delivery:  " << delivery_src[a] << endl;
						cout << "Destination Of Delivery:  " << delivery_dstination[a] << endl;
						cout << "Status Of Booking:  " << delivery_status[a] << endl;
						cout << "Fare For The Delovery:  " << delivery_fare_for_travel[a] << endl;
						cout << endl << endl;
						check_cancel_requests++;
					}
				}

			}
		}

		if (data == 2)
		{
			ifstream inputride("Ride_Services_List.txt");
			for (int q = 0; q < 20; q++)
			{
				inputride >> ride_service_id[q];
				inputride >> ride_passenger_id[q];
				inputride >> ride_psngr[q];
				inputride.getline(delivery_ride_tp[q], 20);
				inputride.getline(delivery_ride_tp[q], 20);
				inputride >> ride_distance[q];
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_dstination[q], 20);
				inputride >> ride_fuel[q];
				inputride >> ride_dvr_id[q];
				inputride >> ride_dvr_rank[q];
				inputride >> ride_vhl_id[q];
				inputride >> ride_vehicle_rank[q];
				inputride >> ride_date[q];
				inputride >> ride_month[q];
				inputride >> ride_year[q];
				inputride >> ride_hour[q];
				inputride >> ride_min[q];
				inputride >> ride_sec[q];
				inputride >> ride_status[q];
				inputride >> ride_fare_for_travel[q];
			}
			inputride.close();

			for (int a = 0; a < 15; a++)
			{
				if (check_customer_id == identity[a])
				{
					cout << endl << endl;
					cout << "Customer's First Name:  " << firstname[a] << endl;
					cout << "Customer's Last Name:  " << lastname[a] << endl;
					cout << "Customer's Age:  " << age[a] << endl;
					cout << "Customer's Date Of Birth:  " << date[a] << "/" << month[a] << "/" << year[a] << endl;
					cout << "Customer's ID:  " << identity[a] << endl;

					if (check_customer_id == identity[a] && ride_status[a] == 2)
					{
						cout << "Service ID:  " << ride_service_id[a] << endl;
						cout << "Passenger's ID:" << ride_passenger_id[a] << endl;
						cout << "Date Of Booking:  " << ride_date[a] << "/" << ride_month[a] << "/" << ride_year[a] << endl;
						cout << "Time Of Booking:  " << ride_hour[a] << ":" << ride_min[a] << ":" << ride_sec[a] << endl;
						cout << "Number Of Passengers:  " << ride_psngr[a] << endl;
						cout << "Ride Type:  " << delivery_ride_tp[a] << endl;
						cout << "Source Of Delivery:  " << ride_src[a] << endl;
						cout << "Destination Of Delivery:  " << ride_dstination[a] << endl;
						cout << "Status Of Booking:  " << ride_status[a] << endl;
						cout << "Fare For The Delivery:  " << ride_fare_for_travel[a] << endl;
						cout << "Rank of Driver:  " << ride_dvr_rank[a] << endl;
						cout << "Rank Of Vehicle:  " << ride_vehicle_rank[a] << endl;
						cout << endl << endl;
						check_cancel_requests++;
					}
				}

			}
		}
	}

	if (check_cancel_requests == 0)
	{
		cout << "Your Entered Customer Has Not Cancelled any Service" << endl;
	}
}

void TMS::customer_services()
{
	int check_cancel_requests = 0;
	int data;
	int check_customer_id;
	char firstname[15][10];//Total Number Of Customers Are 15 And Max Name Length Is 10
	char lastname[15][10];
	int age[15], identity[15], date[15], month[15], year[15];

	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	int check_id = 0;


	ifstream input("Customer_List.txt");

	for (int t = 0; t < 15; t++)
	{
		input >> i;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> date[t];
		input >> month[t];
		input >> year[t];
		input >> identity[t];
	}
	input.close();

	cout << "===============  SERVICE HISTORY OF CUSTOMERS  ===============" << endl << endl;

	cout << "Enter The Customer ID To Check The Services History: " << endl << endl;
	cin >> check_customer_id;
	cout << endl << endl;

	for (int y = 0; y < 15; y++)
	{
		if (check_customer_id == identity[y])
		{
			check_id++;
		}
	}

	cout << endl << endl;

	if (check_id != 0)
	{
		cout << "Enter 1 to get the Delivery Services History:  " << endl;
		cout << "Enter 2 to get the Ride Services History:  " << endl;

		cin >> data;

		if (data == 1)
		{
			ifstream input_delivery("Delivery_Services_List.txt");

			for (int a = 0; a < 20; a++)
			{
				input_delivery >> delivery_service_id[a];
				input_delivery >> delivery_goods_id[a];
				input_delivery >> delivery_wgt[a];
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery >> delivery_distance[a];
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_dstination[a], 20);
				input_delivery >> delivery_fuel[a];
				input_delivery >> delivery_dvr_id[a];
				input_delivery >> delivery_vhl_id[a];
				input_delivery >> delivery_date[a];
				input_delivery >> delivery_month[a];
				input_delivery >> delivery_year[a];
				input_delivery >> delivery_hour[a];
				input_delivery >> delivery_min[a];
				input_delivery >> delivery_sec[a];
				input_delivery >> delivery_status[a];
				input_delivery >> delivery_fare_for_travel[a];
			}
			input_delivery.close();

			cout << endl << endl;

			for (int a = 0; a < 15; a++)
			{
				if (identity[a] == check_customer_id)
				{
					cout << endl << endl;
					cout << "Customer's First Name:  " << firstname[a] << endl;
					cout << "Customer's Last Name:  " << lastname[a] << endl;
					cout << "Customer's Age:  " << age[a] << endl;
					cout << "Customer's Date Of Birth:  " << date[a] << "/" << month[a] << "/" << year[a] << endl;
					cout << "Customer's ID:  " << identity[a] << endl;

					if (identity[a] == check_customer_id)
					{
						cout << "Service ID:  " << delivery_service_id[a] << endl;
						cout << "Good's ID:" << delivery_goods_id[a] << endl;
						cout << "Date Of Booking:  " << delivery_date[a] << "/" << delivery_month[a] << "/" << delivery_year[a] << endl;
						cout << "Time Of Booking:  " << delivery_hour[a] << ":" << delivery_min[a] << ":" << delivery_sec[a] << endl;
						cout << "Good's Weight:  " << delivery_wgt[a] << endl;
						cout << "Good's Ride Type:  " << delivery_goods_tp[a] << endl;
						cout << "Source Of Delivery:  " << delivery_src[a] << endl;
						cout << "Destination Of Delivery:  " << delivery_dstination[a] << endl;
						cout << "Status Of Booking:  " << delivery_status[a] << endl;
						cout << "Fare For The Delovery:  " << delivery_fare_for_travel[a] << endl;
						cout << endl << endl;
						check_cancel_requests++;
					}
				}

			}
		}

		if (data == 2)
		{
			ifstream inputride("Ride_Services_List.txt");
			for (int q = 0; q < 20; q++)
			{
				inputride >> ride_service_id[q];
				inputride >> ride_passenger_id[q];
				inputride >> ride_psngr[q];
				inputride.getline(delivery_ride_tp[q], 20);
				inputride.getline(delivery_ride_tp[q], 20);
				inputride >> ride_distance[q];
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_dstination[q], 20);
				inputride >> ride_fuel[q];
				inputride >> ride_dvr_id[q];
				inputride >> ride_dvr_rank[q];
				inputride >> ride_vhl_id[q];
				inputride >> ride_vehicle_rank[q];
				inputride >> ride_date[q];
				inputride >> ride_month[q];
				inputride >> ride_year[q];
				inputride >> ride_hour[q];
				inputride >> ride_min[q];
				inputride >> ride_sec[q];
				inputride >> ride_status[q];
				inputride >> ride_fare_for_travel[q];
			}
			inputride.close();

			for (int a = 0; a < 15; a++)
			{
				if (check_customer_id == identity[a])
				{
					cout << endl << endl;
					cout << "Customer's First Name:  " << firstname[a] << endl;
					cout << "Customer's Last Name:  " << lastname[a] << endl;
					cout << "Customer's Age:  " << age[a] << endl;
					cout << "Customer's Date Of Birth:  " << date[a] << "/" << month[a] << "/" << year[a] << endl;
					cout << "Customer's ID:  " << identity[a] << endl;

					if (check_customer_id == identity[a])
					{
						cout << "Service ID:  " << ride_service_id[a] << endl;
						cout << "Passenger's ID:" << ride_passenger_id[a] << endl;
						cout << "Date Of Booking:  " << ride_date[a] << "/" << ride_month[a] << "/" << ride_year[a] << endl;
						cout << "Time Of Booking:  " << ride_hour[a] << ":" << ride_min[a] << ":" << ride_sec[a] << endl;
						cout << "Number Of Passengers:  " << ride_psngr[a] << endl;
						cout << "Ride Type:  " << delivery_ride_tp[a] << endl;
						cout << "Source Of Delivery:  " << ride_src[a] << endl;
						cout << "Destination Of Delivery:  " << ride_dstination[a] << endl;
						cout << "Status Of Booking:  " << ride_status[a] << endl;
						cout << "Fare For The Delivery:  " << ride_fare_for_travel[a] << endl;
						cout << "Rank of Driver:  " << ride_dvr_rank[a] << endl;
						cout << "Rank Of Vehicle:  " << ride_vehicle_rank[a] << endl;
						cout << endl << endl;
						check_cancel_requests++;
					}
				}

			}
		}
	}

	if (check_cancel_requests == 0)
	{
		cout << "First Enter Your Desired Customer By Pressing A  " << endl << endl;
	}

}

void TMS::driver_services()
{
	int check_dvr_id;
	char firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char lastname[10][10];
	int age[10], identity[10], dri_date[10], dri_month[10], dri_year[10], salary[10], exp[10], numberofliscence[10];
	int liscense_number[10];
	float ranking[10];

	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	int check_id = 0;
	int data;
	int check_service_requests = 0;


	ifstream input("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		input >> j;
		input >> firstname[t];
		input >> lastname[t];
		input >> age[t];
		input >> dri_date[t];
		input >> dri_month[t];
		input >> dri_year[t];
		input >> identity[t];
		input >> exp[t];
		input >> ranking[t];
		input >> salary[t];
		input >> numberofliscence[t];
		for (int r = 0; r < numberofliscence[t]; r++)
		{
			input >> liscense_number[t];
		}
	}
	input.close();

	cout << "Enter The ID To Check Service History" << endl << endl;
	cin >> check_dvr_id;
	cout << endl;


	for (int y = 0; y < 15; y++)
	{
		if (check_dvr_id == identity[y])
		{
			check_id++;
		}
	}

	cout << endl << endl;

	if (check_id != 0)
	{
		cout << "Enter 1 to get the Delivery Services History:  " << endl;
		cout << "Enter 2 to get the Ride Services History:  " << endl;

		cin >> data;

		if (data == 1)
		{
			ifstream input_delivery("Delivery_Services_List.txt");

			for (int a = 0; a < 20; a++)
			{
				input_delivery >> delivery_service_id[a];
				input_delivery >> delivery_goods_id[a];
				input_delivery >> delivery_wgt[a];
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery >> delivery_distance[a];
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_dstination[a], 20);
				input_delivery >> delivery_fuel[a];
				input_delivery >> delivery_dvr_id[a];
				input_delivery >> delivery_vhl_id[a];
				input_delivery >> delivery_date[a];
				input_delivery >> delivery_month[a];
				input_delivery >> delivery_year[a];
				input_delivery >> delivery_hour[a];
				input_delivery >> delivery_min[a];
				input_delivery >> delivery_sec[a];
				input_delivery >> delivery_status[a];
				input_delivery >> delivery_fare_for_travel[a];
			}
			input_delivery.close();

			cout << endl << endl;

			for (int a = 0; a < 15; a++)
			{
				if (identity[a] == check_dvr_id)
				{
					cout << "Driver's First Name:  " << firstname[a] << endl;
					cout << "Driver's Last Name:  " << lastname[a] << endl;
					cout << "Driver's Age:  " << age[a] << endl;
					cout << "Driver's Date Of Birth:  " << dri_date[a] << "/" << dri_month[a] << "/" << dri_year[a] << endl;
					cout << "Driver's ID:  " << identity[a] << endl;
					cout << "Driver's Experience:  " << exp[a] << endl;
					cout << "Driver's Ranking:  " << ranking[a] << endl;
					cout << "Driver's Salary:  " << salary[a] << endl;
					cout << "Driver's Number Of Liscences:  " << numberofliscence[a] << endl;
					cout << "Liscence Numbers:  ";
					for (int y = 0; y < numberofliscence[a]; y++)
					{
						cout << liscense_number[a] << "     ";
					}

					if (identity[a] == check_dvr_id)
					{
						cout << "Service ID:  " << delivery_service_id[a] << endl;
						cout << "Good's ID:" << delivery_goods_id[a] << endl;
						cout << "Date Of Booking:  " << delivery_date[a] << "/" << delivery_month[a] << "/" << delivery_year[a] << endl;
						cout << "Time Of Booking:  " << delivery_hour[a] << ":" << delivery_min[a] << ":" << delivery_sec[a] << endl;
						cout << "Good's Weight:  " << delivery_wgt[a] << endl;
						cout << "Good's Ride Type:  " << delivery_goods_tp[a] << endl;
						cout << "Source Of Delivery:  " << delivery_src[a] << endl;
						cout << "Destination Of Delivery:  " << delivery_dstination[a] << endl;
						cout << "Status Of Booking:  " << delivery_status[a] << endl;
						cout << "Fare For The Delovery:  " << delivery_fare_for_travel[a] << endl;
						cout << endl << endl;
						check_service_requests++;
					}
				}

			}
		}

		if (data == 2)
		{
			ifstream inputride("Ride_Services_List.txt");
			for (int q = 0; q < 20; q++)
			{
				inputride >> ride_service_id[q];
				inputride >> ride_passenger_id[q];
				inputride >> ride_psngr[q];
				inputride.getline(delivery_ride_tp[q], 20);
				inputride.getline(delivery_ride_tp[q], 20);
				inputride >> ride_distance[q];
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_dstination[q], 20);
				inputride >> ride_fuel[q];
				inputride >> ride_dvr_id[q];
				inputride >> ride_dvr_rank[q];
				inputride >> ride_vhl_id[q];
				inputride >> ride_vehicle_rank[q];
				inputride >> ride_date[q];
				inputride >> ride_month[q];
				inputride >> ride_year[q];
				inputride >> ride_hour[q];
				inputride >> ride_min[q];
				inputride >> ride_sec[q];
				inputride >> ride_status[q];
				inputride >> ride_fare_for_travel[q];
			}
			inputride.close();

			for (int a = 0; a < 15; a++)
			{
				if (check_dvr_id == identity[a])
				{
					cout << "Driver's First Name:  " << firstname[a] << endl;
					cout << "Driver's Last Name:  " << lastname[a] << endl;
					cout << "Driver's Age:  " << age[a] << endl;
					cout << "Driver's Date Of Birth:  " << dri_date[a] << "/" << dri_month[a] << "/" << dri_year[a] << endl;
					cout << "Driver's ID:  " << identity[a] << endl;
					cout << "Driver's Experience:  " << exp[a] << endl;
					cout << "Driver's Ranking:  " << ranking[a] << endl;
					cout << "Driver's Salary:  " << salary[a] << endl;
					cout << "Driver's Number Of Liscences:  " << numberofliscence[a] << endl;
					cout << "Liscence Numbers:  ";
					for (int y = 0; y < numberofliscence[a]; y++)
					{
						cout << liscense_number[a] << "     ";
					}


					if (check_dvr_id == identity[a])
					{
						cout << "Service ID:  " << ride_service_id[a] << endl;
						cout << "Passenger's ID:" << ride_passenger_id[a] << endl;
						cout << "Date Of Booking:  " << ride_date[a] << "/" << ride_month[a] << "/" << ride_year[a] << endl;
						cout << "Time Of Booking:  " << ride_hour[a] << ":" << ride_min[a] << ":" << ride_sec[a] << endl;
						cout << "Number Of Passengers:  " << ride_psngr[a] << endl;
						cout << "Ride Type:  " << delivery_ride_tp[a] << endl;
						cout << "Source Of Delivery:  " << ride_src[a] << endl;
						cout << "Destination Of Delivery:  " << ride_dstination[a] << endl;
						cout << "Status Of Booking:  " << ride_status[a] << endl;
						cout << "Fare For The Delivery:  " << ride_fare_for_travel[a] << endl;
						cout << "Rank of Driver:  " << ride_dvr_rank[a] << endl;
						cout << "Rank Of Vehicle:  " << ride_vehicle_rank[a] << endl;
						cout << endl << endl;
						check_service_requests++;
					}
				}

			}
		}
	}

	if (check_service_requests == 0)
	{
		cout << "First Enter Your Desired Customer By Pressing B  " << endl << endl;
	}
}

void TMS::cancel_request()
{
	int customer_id;
	int service_ID;
	int cancel;

	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];
	float fine_imposed[20];

	cout << endl << endl;

	cout << "================  CANCELLED SERVICES  ================" << endl << endl;

	cout << "Enter 1 To Cancel Delivery Services" << endl << endl;
	cout << "Enter 2 To Cancel Ride Services" << endl << endl;

	cin >> cancel;

	if (cancel == 1)
	{
		cout << "Enter Customer ID:  ";
		cin >> customer_id;
		cout << endl;
		cout << "Enter Service ID:  ";
		cin >> service_ID;
		cout << endl;

		ifstream input_delivery("Delivery_Services_List.txt");

		for (int a = 0; a < 20; a++)
		{
			input_delivery >> delivery_service_id[a];
			input_delivery >> delivery_goods_id[a];
			input_delivery >> delivery_wgt[a];
			input_delivery.getline(delivery_goods_tp[a], 20);
			input_delivery.getline(delivery_goods_tp[a], 20);
			input_delivery >> delivery_distance[a];
			input_delivery.getline(delivery_src[a], 20);
			input_delivery.getline(delivery_src[a], 20);
			input_delivery.getline(delivery_dstination[a], 20);
			input_delivery >> delivery_fuel[a];
			input_delivery >> delivery_dvr_id[a];
			input_delivery >> delivery_vhl_id[a];
			input_delivery >> delivery_date[a];
			input_delivery >> delivery_month[a];
			input_delivery >> delivery_year[a];
			input_delivery >> delivery_hour[a];
			input_delivery >> delivery_min[a];
			input_delivery >> delivery_sec[a];
			input_delivery >> delivery_status[a];
			input_delivery >> delivery_fare_for_travel[a];
		}
		input_delivery.close();

		cout << endl << endl;

		ofstream outputdelivery("Delivery_services_List.txt");
		for (int f = 0; f < 20; f++)
		{
			if (delivery_service_id[f] == service_ID)
			{
				fine_imposed[f] = delivery_fare_for_travel[f] * (0.15);//Imposes a fine of 15 percent on cancellation
				delivery_status[f] = 2;//As The delivery is cancelled on 2
				outputdelivery << delivery_service_id[f] << endl;
				outputdelivery << delivery_goods_id[f] << endl;
				outputdelivery << delivery_wgt[f] << endl;
				outputdelivery << delivery_goods_tp[f] << endl;
				outputdelivery << delivery_distance[f] << endl;
				outputdelivery << delivery_src[f] << endl;
				outputdelivery << delivery_dstination[f] << endl;
				outputdelivery << delivery_fuel[f] << endl;
				outputdelivery << delivery_dvr_id[f] << endl;
				outputdelivery << delivery_vhl_id[f] << endl;
				outputdelivery << delivery_date[f] << endl;
				outputdelivery << delivery_month[f] << endl;
				outputdelivery << delivery_year[f] << endl;
				outputdelivery << delivery_hour[f] << endl;
				outputdelivery << delivery_min[f] << endl;
				outputdelivery << delivery_sec[f] << endl;
				outputdelivery << delivery_status[f] << endl;
				outputdelivery << delivery_fare_for_travel[f] << endl;
			}
			else if (delivery_service_id[f] > 0)
			{
				outputdelivery << delivery_service_id[f] << endl;
				outputdelivery << delivery_goods_id[f] << endl;
				outputdelivery << delivery_wgt[f] << endl;
				outputdelivery << delivery_goods_tp[f] << endl;
				outputdelivery << delivery_distance[f] << endl;
				outputdelivery << delivery_src[f] << endl;
				outputdelivery << delivery_dstination[f] << endl;
				outputdelivery << delivery_fuel[f] << endl;
				outputdelivery << delivery_dvr_id[f] << endl;
				outputdelivery << delivery_vhl_id[f] << endl;
				outputdelivery << delivery_date[f] << endl;
				outputdelivery << delivery_month[f] << endl;
				outputdelivery << delivery_year[f] << endl;
				outputdelivery << delivery_hour[f] << endl;
				outputdelivery << delivery_min[f] << endl;
				outputdelivery << delivery_sec[f] << endl;
				outputdelivery << delivery_status[f] << endl;
				outputdelivery << delivery_fare_for_travel[f] << endl;
			}
		}
		outputdelivery.close();
	}

	if (cancel == 2)
	{
		cout << "Enter Customer ID:  ";
		cin >> customer_id;
		cout << endl;
		cout << "Enter Service ID:  ";
		cin >> service_ID;
		cout << endl;

		ifstream inputride("Ride_Services_List.txt");
		for (int q = 0; q < 20; q++)
		{
			inputride >> ride_service_id[q];
			inputride >> ride_passenger_id[q];
			inputride >> ride_psngr[q];
			inputride.getline(delivery_ride_tp[q], 20);
			inputride.getline(delivery_ride_tp[q], 20);
			inputride >> ride_distance[q];
			inputride.getline(ride_src[q], 20);
			inputride.getline(ride_src[q], 20);
			inputride.getline(ride_dstination[q], 20);
			inputride >> ride_fuel[q];
			inputride >> ride_dvr_id[q];
			inputride >> ride_dvr_rank[q];
			inputride >> ride_vhl_id[q];
			inputride >> ride_vehicle_rank[q];
			inputride >> ride_date[q];
			inputride >> ride_month[q];
			inputride >> ride_year[q];
			inputride >> ride_hour[q];
			inputride >> ride_min[q];
			inputride >> ride_sec[q];
			inputride >> ride_status[q];
			inputride >> ride_fare_for_travel[q];
		}
		inputride.close();

		ofstream outputdelivery("Ride_services_List.txt");
		for (int f = 0; f < 20; f++)
		{
			if (ride_service_id[f] == service_ID)
			{
				fine_imposed[f] = ride_fare_for_travel[f] * (0.15);//Imposes a fine of 15 percent on cancellation
				ride_status[f] = 2;//As The delivery is cancelled on 2
				outputdelivery << ride_service_id[f] << endl;
				outputdelivery << ride_passenger_id[f] << endl;
				outputdelivery << ride_psngr[f] << endl;
				outputdelivery << delivery_ride_tp[f] << endl;
				outputdelivery << ride_distance[f] << endl;
				outputdelivery << ride_src[f] << endl;
				outputdelivery << ride_dstination[f] << endl;
				outputdelivery << ride_fuel[f] << endl;
				outputdelivery << ride_dvr_id[f] << endl;
				outputdelivery << ride_dvr_rank[f] << endl;
				outputdelivery << ride_vhl_id[f] << endl;
				outputdelivery << ride_vehicle_rank[f] << endl;
				outputdelivery << ride_date[f] << endl;
				outputdelivery << ride_month[f] << endl;
				outputdelivery << ride_year[f] << endl;
				outputdelivery << ride_hour[f] << endl;
				outputdelivery << ride_min[f] << endl;
				outputdelivery << ride_sec[f] << endl;
				outputdelivery << ride_status[f] << endl;
				outputdelivery << ride_fare_for_travel[f] << endl;
			}
			else if (delivery_service_id[f] > 0)
			{
				fine_imposed[f] = ride_fare_for_travel[f] * (0.15);//Imposes a fine of 15 percent on cancellation
				ride_status[f] = 2;//As The delivery is cancelled on 2
				outputdelivery << ride_service_id[f] << endl;
				outputdelivery << ride_passenger_id[f] << endl;
				outputdelivery << ride_psngr[f] << endl;
				outputdelivery << delivery_ride_tp[f] << endl;
				outputdelivery << ride_distance[f] << endl;
				outputdelivery << ride_src[f] << endl;
				outputdelivery << ride_dstination[f] << endl;
				outputdelivery << ride_fuel[f] << endl;
				outputdelivery << ride_dvr_id[f] << endl;
				outputdelivery << ride_dvr_rank[f] << endl;
				outputdelivery << ride_vhl_id[f] << endl;
				outputdelivery << ride_vehicle_rank[f] << endl;
				outputdelivery << ride_date[f] << endl;
				outputdelivery << ride_month[f] << endl;
				outputdelivery << ride_year[f] << endl;
				outputdelivery << ride_hour[f] << endl;
				outputdelivery << ride_min[f] << endl;
				outputdelivery << ride_sec[f] << endl;
				outputdelivery << ride_status[f] << endl;
				outputdelivery << ride_fare_for_travel[f] << endl;
			}
		}
		outputdelivery.close();

		cout << "===============  CANCELLATION OF SERVICE IS DONE  ===============" << endl << endl;

		cout << "Imposed Fine:  ";

		for (int r = 0; r < 20; r++)
		{
			if (fine_imposed[r] > 0)
			{
				cout << fine_imposed[r] << endl;
			}

		}
	}

}

void TMS::complete_service()
{
	int complete_date, complete_month, complete_year;
	int service_ID;
	int complete;

	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];
	float fine_imposed[20];

	cout << endl << endl;

	cout << "===============  COMPLETE SERVICE  ===============" << endl << endl;

	cout << "Enter 1 for Delivery Complete Service" << endl;
	cout << "Enter 2 for Rides Complete Services" << endl;
	cin >> complete;

	if (complete == 1)
	{
		cout << "Enter The Service ID:  ";
		cin >> service_ID;
		cout << endl;

		ifstream input_delivery("Delivery_Services_List.txt");

		for (int a = 0; a < 20; a++)
		{
			input_delivery >> delivery_service_id[a];
			input_delivery >> delivery_goods_id[a];
			input_delivery >> delivery_wgt[a];
			input_delivery.getline(delivery_goods_tp[a], 20);
			input_delivery.getline(delivery_goods_tp[a], 20);
			input_delivery >> delivery_distance[a];
			input_delivery.getline(delivery_src[a], 20);
			input_delivery.getline(delivery_src[a], 20);
			input_delivery.getline(delivery_dstination[a], 20);
			input_delivery >> delivery_fuel[a];
			input_delivery >> delivery_dvr_id[a];
			input_delivery >> delivery_vhl_id[a];
			input_delivery >> delivery_date[a];
			input_delivery >> delivery_month[a];
			input_delivery >> delivery_year[a];
			input_delivery >> delivery_hour[a];
			input_delivery >> delivery_min[a];
			input_delivery >> delivery_sec[a];
			input_delivery >> delivery_status[a];
			input_delivery >> delivery_fare_for_travel[a];
		}
		input_delivery.close();

		cout << endl << endl;

		for (int f = 0; f < 20; f++)
		{
			if (delivery_service_id[f] == service_ID)
			{
				delivery_status[f] = 1;

				cout << "Rank The Vehicle ( 0--5 ):  ";
				cin >> delivery_vehicle_rank[f];
				cout << endl;

				cout << "Rank The Driver ( 0--5 ):  ";
				cin >> delivery_dvr_rank[f];
				cout << endl;

				cout << "Enter Date:  ";
				cin >> complete_date;
				cout << endl;
				cout << "Enter Month:  ";
				cin >> complete_month;
				cout << endl;
				cout << "Enter Year:  ";
				cin >> complete_year;
				cout << endl;

				ofstream completedoutput("Completed_Service.txt", ios::app);

				cout << endl;
				completedoutput << complete_date << endl;
				completedoutput << complete_month << endl;
				completedoutput << complete_year << endl;
				completedoutput.close();



				ofstream outputdelivery("Delivery_services_List.txt");
				for (int a = 0; a < 20; a++)
				{
					if (delivery_service_id[a] > 0)
					{
						outputdelivery << delivery_service_id[a] << endl;
						outputdelivery << delivery_goods_id[a] << endl;
						outputdelivery << delivery_wgt[a] << endl;
						outputdelivery << delivery_goods_tp[a] << endl;
						outputdelivery << delivery_distance[a] << endl;
						outputdelivery << delivery_src[a] << endl;
						outputdelivery << delivery_dstination[a] << endl;
						outputdelivery << delivery_fuel[a] << endl;
						outputdelivery << delivery_dvr_id[a] << endl;
						outputdelivery << delivery_vhl_id[a] << endl;
						outputdelivery << delivery_date[a] << endl;
						outputdelivery << delivery_month[a] << endl;
						outputdelivery << delivery_year[a] << endl;
						outputdelivery << delivery_hour[a] << endl;
						outputdelivery << delivery_min[a] << endl;
						outputdelivery << delivery_sec[a] << endl;
						outputdelivery << delivery_status[a] << endl;
						outputdelivery << delivery_fare_for_travel[a] << endl;
					}
				}
				outputdelivery.close();
			}

		}
	}

	else if (complete == 2)
	{
		cout << "Enter The Service ID:  ";
		cin >> service_ID;
		cout << endl;

		ifstream inputride("Ride_Services_List.txt");
		for (int q = 0; q < 20; q++)
		{
			inputride >> ride_service_id[q];
			inputride >> ride_passenger_id[q];
			inputride >> ride_psngr[q];
			inputride.getline(delivery_ride_tp[q], 20);
			inputride.getline(delivery_ride_tp[q], 20);
			inputride >> ride_distance[q];
			inputride.getline(ride_src[q], 20);
			inputride.getline(ride_src[q], 20);
			inputride.getline(ride_dstination[q], 20);
			inputride >> ride_fuel[q];
			inputride >> ride_dvr_id[q];
			inputride >> ride_dvr_rank[q];
			inputride >> ride_vhl_id[q];
			inputride >> ride_vehicle_rank[q];
			inputride >> ride_date[q];
			inputride >> ride_month[q];
			inputride >> ride_year[q];
			inputride >> ride_hour[q];
			inputride >> ride_min[q];
			inputride >> ride_sec[q];
			inputride >> ride_status[q];
			inputride >> ride_fare_for_travel[q];
		}
		inputride.close();

		ofstream outputdelivery("Ride_services_List.txt");
		for (int f = 0; f < 20; f++)
		{
			if (ride_service_id[f] == service_ID)
			{
				ride_status[f] = 1;

				cout << "Rank The Vehicle ( 0--5 ):  ";
				cin >> ride_vehicle_rank[f];
				cout << endl;

				cout << "Rank The Driver ( 0--5 ):  ";
				cin >> ride_dvr_rank[f];
				cout << endl;



				if (ride_service_id[f] > 0)
				{
					outputdelivery << ride_service_id[f] << endl;
					outputdelivery << ride_passenger_id[f] << endl;
					outputdelivery << ride_psngr[f] << endl;
					outputdelivery << delivery_ride_tp[f] << endl;
					outputdelivery << ride_distance[f] << endl;
					outputdelivery << ride_src[f] << endl;
					outputdelivery << ride_dstination[f] << endl;
					outputdelivery << ride_fuel[f] << endl;
					outputdelivery << ride_dvr_id[f] << endl;
					outputdelivery << ride_dvr_rank[f] << endl;
					outputdelivery << ride_vhl_id[f] << endl;
					outputdelivery << ride_vehicle_rank[f] << endl;
					outputdelivery << ride_date[f] << endl;
					outputdelivery << ride_month[f] << endl;
					outputdelivery << ride_year[f] << endl;
					outputdelivery << ride_hour[f] << endl;
					outputdelivery << ride_min[f] << endl;
					outputdelivery << ride_sec[f] << endl;
					outputdelivery << ride_status[f] << endl;
					outputdelivery << ride_fare_for_travel[f] << endl;
				}
			}
		}
		outputdelivery.close();
	}
}

void TMS::service_history_vehicle()
{
	int history;
	int id_check = 0;
	int check_vhl_id;
	int ride_status[20]; int delivery_status[20];
	int ride_date[20], ride_month[20], ride_year[20], ride_hour[20], ride_min[20], ride_sec[20];
	int delivery_date[20], delivery_month[20], delivery_year[20], delivery_hour[20], delivery_min[20], delivery_sec[20];
	int ride_fuel[20], ride_distance[20], ride_psngr[20], ride_passenger_id[20];
	int delivery_fuel[20], delivery_distance[20], delivery_wgt[20], delivery_goods_id[20];
	char ride_src[20][20], ride_dstination[20][20], delivery_ride_tp[20][20];
	char delivery_src[20][20], delivery_dstination[20][20], delivery_goods_tp[20][20];
	int ride_dvr_id[20], ride_vhl_id[20], ride_service_id[20];
	int delivery_dvr_id[20], delivery_vhl_id[20], delivery_service_id[20];
	float ride_dvr_rank[20], ride_vehicle_rank[20], ride_fare_for_travel[20];
	float delivery_dvr_rank[20], delivery_vehicle_rank[20], delivery_fare_for_travel[20];

	int num_of_feat[20], date[20], month[20], year[20], registration_number[20], identity[20];
	char list_of_features[20][10];
	float mlg[20]; char liscence_type[20][10]; char fuel_Type[20][10];
	float rank[20];
	char dstination[20][20][25];
	char feature_id[20][20][25];
	char cost_of_vhl[20][20][25];

	ifstream inputvehicle("Vehicle_List.txt");

	for (int e = 0; e < 20; e++)
	{
		inputvehicle >> k;
		inputvehicle >> mlg[e];
		inputvehicle >> num_of_feat[e];
		for (int i = 0; i < num_of_feat[e]; i++)
		{

			inputvehicle >> feature_id[e][i];
			inputvehicle.getline(dstination[e][i], 25);
			inputvehicle.getline(dstination[e][i], 25);
			inputvehicle >> cost_of_vhl[e][i];
		}
		inputvehicle >> fuel_Type[e];
		inputvehicle >> liscence_type[e];
		inputvehicle >> date[e];
		inputvehicle >> month[e];
		inputvehicle >> year[e];
		inputvehicle >> rank[e];
		inputvehicle >> registration_number[e];
		inputvehicle >> identity[e];
	}
	inputvehicle.close();


	cout << endl << endl;
	cout << "===============  VEHICLES COMPLETE DETAILS  ===============" << endl << endl;

	cout << "Enter Vehicle ID:  ";
	cin >> check_vhl_id;
	cout << endl;

	for (int y = 0; y < 20; y++)
	{
		if (check_vhl_id == identity[y])
		{
			id_check++;
		}
	}

	if (id_check != 0)
	{
		cout << "Enter 1 To Get Delivery Services Information" << endl;
		cout << "Enter 2 To Get Ride Services Information" << endl;

		cin >> history;

		if (history == 1)
		{
			ifstream input_delivery("Delivery_Services_List.txt");

			for (int a = 0; a < 20; a++)
			{
				input_delivery >> delivery_service_id[a];
				input_delivery >> delivery_goods_id[a];
				input_delivery >> delivery_wgt[a];
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery.getline(delivery_goods_tp[a], 20);
				input_delivery >> delivery_distance[a];
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_src[a], 20);
				input_delivery.getline(delivery_dstination[a], 20);
				input_delivery >> delivery_fuel[a];
				input_delivery >> delivery_dvr_id[a];
				input_delivery >> delivery_vhl_id[a];
				input_delivery >> delivery_date[a];
				input_delivery >> delivery_month[a];
				input_delivery >> delivery_year[a];
				input_delivery >> delivery_hour[a];
				input_delivery >> delivery_min[a];
				input_delivery >> delivery_sec[a];
				input_delivery >> delivery_status[a];
				input_delivery >> delivery_fare_for_travel[a];
			}
			input_delivery.close();
			cout << endl << endl;

			for (int o = 0; o < 20; o++)
			{
				if (identity[o] == check_vhl_id)
				{
					cout << "Vehicls's Registration Number:  " << registration_number[o] << endl;
					cout << "Vehicle's ID:  " << identity[o] << endl;
					cout << "Vehicle's Date Of Manufacture:  " << date[o] << "/" << month[o] << "/" << year[o] << endl;
					cout << "OverAll Ranking:  " << rank[o] << endl;
					cout << "Vehicle's Fuel Type:  " << fuel_Type[o] << endl;
					cout << "Vehicle's Category:  " << liscence_type[o] << endl;
					if (check_vhl_id == delivery_vhl_id[o] && date[o] > 0)
					{
						cout << "Driver ID:  " << delivery_dvr_id[o] << endl;
						cout << "Vehicle's Service Id:  " << delivery_service_id[o] << endl;
						cout << "Customer Id:  " << delivery_goods_id[o] << endl;
						cout << "Vehicle's Date Of Booking:  " << delivery_date[o] << "/" << delivery_month[o] << "/" << delivery_year[o] << endl;
						cout << "Vehicle's Time Of Booking:  " << delivery_hour[o] << ":" << delivery_min[o] << "/" << delivery_sec[o] << endl;
						cout << "Source Of Travel:  " << delivery_src[o] << endl;
						cout << "Destination Of Travel:  " << delivery_dstination[o] << endl;
						cout << "Distance Of Travel:  " << delivery_distance[o] << endl;
						cout << "Fare For Travel:  " << delivery_fare_for_travel[o] << endl;
					}
				}
			}
		}

		if (history == 2)
		{
			ifstream inputride("Ride_Services_List.txt");
			for (int q = 0; q < 20; q++)
			{
				inputride >> ride_service_id[q];
				inputride >> ride_passenger_id[q];
				inputride >> ride_psngr[q];
				inputride.getline(delivery_ride_tp[q], 20);
				inputride.getline(delivery_ride_tp[q], 20);
				inputride >> ride_distance[q];
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_src[q], 20);
				inputride.getline(ride_dstination[q], 20);
				inputride >> ride_fuel[q];
				inputride >> ride_dvr_id[q];
				inputride >> ride_dvr_rank[q];
				inputride >> ride_vhl_id[q];
				inputride >> ride_vehicle_rank[q];
				inputride >> ride_date[q];
				inputride >> ride_month[q];
				inputride >> ride_year[q];
				inputride >> ride_hour[q];
				inputride >> ride_min[q];
				inputride >> ride_sec[q];
				inputride >> ride_status[q];
				inputride >> ride_fare_for_travel[q];
			}
			inputride.close();

			cout << endl << endl;

			for (int o = 0; o < 20; o++)
			{
				if (identity[o] == check_vhl_id)
				{
					cout << "Vehicls's Registration Number:  " << registration_number[o] << endl;
					cout << "Vehicle's ID:  " << identity[o] << endl;
					cout << "Vehicle's Date Of Manufacture:  " << date[o] << "/" << month[o] << "/" << year[o] << endl;
					cout << "OverAll Ranking:  " << rank[o] << endl;
					cout << "Vehicle's Fuel Type:  " << fuel_Type[o] << endl;
					cout << "Vehicle's Category:  " << liscence_type[o] << endl;
					if (check_vhl_id == ride_vhl_id[o] && date[o] > 0)
					{
						cout << "Driver ID:  " << ride_dvr_id[o] << endl;
						cout << "Vehicle's Service Id:  " << ride_service_id[o] << endl;
						cout << "Customer Id:  " << ride_passenger_id[o] << endl;
						cout << "Vehicle's Date Of Booking:  " << ride_date[o] << "/" << ride_month[o] << "/" << ride_year[o] << endl;
						cout << "Vehicle's Time Of Booking:  " << ride_hour[o] << ":" << ride_min[o] << "/" << ride_sec[o] << endl;
						cout << "Source Of Travel:  " << ride_src[o] << endl;
						cout << "Destination Of Travel:  " << ride_dstination[o] << endl;
						cout << "Distance Of Travel:  " << ride_distance[o] << endl;
						cout << "Fare For Travel:  " << ride_fare_for_travel[o] << endl;
					}
				}
			}
		}
	}
}

void TMS::service_request()
{
	Ride* r;
	Delivery* d;
	r = new Ride;
	d = new Delivery;

	int Service_id;
	int ride_check_dvr_id;
	int ride_check_vhl_id;
	int book;
	int check_cus_id = 0;
	int cus_id;
	char dvr_firstname[10][10];//Total Number Of Drivers Are 10 And Max Length Is 10
	char dvr_lastname[10][10];
	int dvr_age[10], dvr_identity[10], dvr_date[10], dvr_month[10], dvr_year[10], dvr_salary[10], dvr_exp[10], dvr_numberofliscence[10];
	int dvr_liscense_number[10];
	float dvr_ranking[10];

	int status = 1;
	char cus_firstname[15][10];//15 Customers and 10 the Length of first Name
	char cus_lastname[15][10];//15 Customers and 10 the Length of second Name
	int cus_age[15], cus_date[15], cus_month[15], cus_year[15], cus_identity[15];

	int vhl_number_of_features[20];
	int vhl_cost[20][10];//20 are the number of vehicles and 10 is the cost of vehicle through features 
	char vhl_dscription[20][20][25];//20 are the number of vehicles , 20 are the lines of description and in each line it could be of 100 words
	int vhl_date[20], vhl_month[20], vhl_year[20];//20 for each of the vehicles manufacture date
	int vhl_identity[20];
	int vhl_feature_id[20][10];//10 is for different feature id's as inheriting from feature class
	int vhl_registration_number[20];
	float vhl_rank[20];
	char vhl_liscence_type[20][10];//20 for vehicles and 10 for the words in each line
	char vhl_fuel_type[20][10];//20 for vehicles and 10 for the words in each line
	float vhl_mlg[20];

	int dvl_goods_wgt; char dvl_dstination[20]; char dvl_src[20]; int dvl_distance, dvl_fuel_cost;
	char dvl_ride_tp[20];
	int dvl_date, dvl_month, dvl_year, dvl_hour, dvl_min, dvl_sec;
	float dvl_fare_for_travel;
	float dvl_dvr_rank[20], dvl_vhl_rank[20];


	int ride_no_of_passenger; char ride_dstination[20]; char ride_src[20]; int ride_distance, ride_fuel_cost;
	char ride_tp[20];
	int ride_date, ride_month, ride_year, ride_hour, ride_min, ride_sec;
	float ride_fare_for_travel;
	float ride_dvr_rank[20]; float ride_vhl_rank[20];


	ifstream inputcus("Customer_List.txt");
	for (int k = 0; k < 15; k++)
	{
		inputcus >> i;
		inputcus >> cus_firstname[k];
		inputcus >> cus_lastname[k];
		inputcus >> cus_age[k];
		inputcus >> cus_date[k];
		inputcus >> cus_month[k];
		inputcus >> cus_year[k];
		inputcus >> cus_identity[k];
	}
	inputcus.close();

	ifstream inputdvr("Driver_List.txt");

	for (int t = 0; t < 10; t++)
	{
		inputdvr >> j;
		inputdvr >> dvr_firstname[t];
		inputdvr >> dvr_lastname[t];
		inputdvr >> dvr_age[t];
		inputdvr >> dvr_date[t];
		inputdvr >> dvr_month[t];
		inputdvr >> dvr_year[t];
		inputdvr >> dvr_identity[t];
		inputdvr >> dvr_exp[t];
		inputdvr >> dvr_ranking[t];
		inputdvr >> dvr_salary[t];
		inputdvr >> dvr_numberofliscence[t];
		for (int r = 0; r < dvr_numberofliscence[t]; r++)
		{
			inputdvr >> dvr_liscense_number[t];
		}
	}
	inputdvr.close();


	ifstream inputvhl("Vehicle_List.txt");

	for (int b = 0; b < 20; b++)
	{
		inputvhl >> k;
		inputvhl >> vhl_mlg[b];
		inputvhl >> vhl_number_of_features[b];
		for (int h = 0; h < vhl_number_of_features[b]; h++)
		{
			inputvhl >> vhl_feature_id[b][h];
			inputvhl.getline(vhl_dscription[b][h], 50);
			inputvhl.getline(vhl_dscription[b][h], 50);
			inputvhl >> vhl_cost[b][h];
		}

		inputvhl.getline(vhl_fuel_type[b], 10);
		inputvhl.getline(vhl_liscence_type[b], 10);
		inputvhl.getline(vhl_liscence_type[b], 10);
		inputvhl >> vhl_date[b];
		inputvhl >> vhl_month[b];
		inputvhl >> vhl_year[b];
		inputvhl >> vhl_rank[b];
		inputvhl >> vhl_registration_number[b];
		inputvhl >> vhl_identity[b];
	}
	inputvhl.close();


	cout << endl << endl;
	cout << "===============  ADD A SERVICE REQUEST  ===============" << endl << endl;

	cout << "Enter The Customer ID:  ";
	cin >> cus_id;
	cout << endl;

	for (int f = 0; f < 15; f++)
	{
		if (cus_id == cus_identity[f])
		{
			check_cus_id++;
		}
	}

	if (check_cus_id == 0)
	{
		cout << "First Enter Customer By Pressing A" << endl;
	}
	else if (check_cus_id != 0)
	{
		cout << endl << endl;

		cout << "Press 1 For Booking A Ride" << endl << endl;
		cout << "Press 2 For Booking A Delivery" << endl << endl;

		cin >> book;

		if (book == 1)
		{
			cout << endl << endl;
			cout << "Enter Number Of Passengers:  ";
			cin >> ride_no_of_passenger;
			cout << endl;
			cout << "Enter Destination:  ";
			cin.ignore();
			cin.getline(ride_dstination, 20);
			cout << endl;
			cout << "Enter Source:  ";
			cin.ignore();
			cin.getline(ride_src, 20);
			cout << endl;
			cout << "Enter Types Of Ride:  ";
			cin.ignore();
			cin.getline(ride_tp, 20);
			cout << endl;
			cout << "Enter Distance:  ";
			cin >> ride_distance;
			cout << endl;
			cout << "Enter Booking Date" << endl;
			cout << "Enter Date:  ";
			cin >> ride_date;
			cout << endl;
			cout << "Enter Month:  ";
			cin >> ride_month;
			cout << endl;
			cout << "Enter Year:  ";
			cin >> ride_year;
			cout << endl;
			cout << "Enter Booking Time" << endl;
			cout << "Enter Hour:  ";
			cin >> ride_hour;
			cout << endl;
			cout << "Enter Minutes:  ";
			cin >> ride_min;
			cout << endl;
			cout << "Enter Seconds:  ";
			cin >> ride_sec;
			cout << endl;
			cout << "Enter Fuel Cost:  ";
			cin >> ride_fuel_cost;
			cout << endl;

			ride_fare_for_travel = ride_distance * ride_fuel_cost;

			for (int r = 0; r < 10; r++)
			{
				ride_dvr_rank[r] = dvr_ranking[r];
			}

			for (int r = 0; r < 10; r++)
			{
				ride_vhl_rank[r] = vhl_rank[r];
			}

			//Bubble Sorting Of Drivers According To Their Ranks
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9 - a; b++)
				{
					if (ride_dvr_rank[b] < ride_dvr_rank[b + 1])
					{
						float rnk;
						rnk = ride_dvr_rank[b];
						ride_dvr_rank[b] = ride_dvr_rank[b + 1];
						ride_dvr_rank[b + 1] = rnk;
					}
				}
			}

			//Bubble Sorting Of Vehicles According To Their Ranks
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9 - a; b++)
				{
					if (ride_vhl_rank[b] < ride_vhl_rank[b + 1])
					{
						float rnking;
						rnking = ride_vhl_rank[b];
						ride_vhl_rank[b] = ride_vhl_rank[b + 1];
						ride_vhl_rank[b + 1] = rnking;
					}
				}
			}
			//Printing Driver's Information
			cout << "Driver Id   " << "Driver Name   " << "Driver Ranking   " << endl << endl;



			for (int y = 0; y < 10; y++)
			{
				if (ride_dvr_rank[y] > 0)//If Rank Exists So Driver Exists
				{
					cout << dvr_identity[y] << " " << dvr_firstname[y] << " " << dvr_lastname[y] << " " << dvr_ranking[y] << endl << endl;

				}
			}

			cout << "Vehicle Id   " << "Vehicle Ranking   " << "Vehicle Category   " << endl << endl;



			for (int y = 0; y < 20; y++)
			{
				if (ride_vhl_rank[y] > 0)//If Rank Exists So Driver Exists
				{
					cout << vhl_identity[y] << " " << vhl_rank[y] << " " << vhl_fuel_type[y] << endl << endl;
				}
			}

			cout << "Enter The Driver ID:  ";
			cin >> ride_check_dvr_id;
			cout << endl << endl;

			cout << "Enter The Vehicle ID:  ";
			cin >> ride_check_vhl_id;
			cout << endl << endl;

			for (int f = 0; f < 10; f++)
			{
				if (dvr_identity[f] == ride_check_dvr_id)
				{
					ride_dvr_rank[0] = dvr_ranking[f];
				}
			}

			for (int f = 0; f < 10; f++)
			{
				if (vhl_identity[f] == ride_check_vhl_id)
				{
					ride_vhl_rank[0] = vhl_rank[f];
				}
			}

			ride_fare_for_travel = ride_fare_for_travel * ride_dvr_rank[0];
			ride_fare_for_travel = ride_fare_for_travel * ride_vhl_rank[0];

			mTime t1;
			t1.set_time(ride_hour, ride_min, ride_sec);
			Date d1;
			d1.setDOB(ride_date, ride_month, ride_year);

			r->set_customerID(cus_identity[i]);
			r->set_noofpassengers(ride_no_of_passenger);
			r->set_distance(ride_distance);
			r->set_bookingDate(d1);
			r->set_bookingTime(t1);
			r->set_source(ride_src);
			r->set_destination(ride_dstination);
			r->set_driverID(ride_check_dvr_id);
			r->set_driverranking(ride_dvr_rank[0]);
			r->set_vehicleranking(ride_vhl_rank[0]);
			r->set_vehicleID(ride_check_vhl_id);
			r->set_status(status);
			r->set_ridetype(ride_tp);

			srand((unsigned)time(NULL));

			Service_id = rand();

			cout << "Vehicle's Service ID:  " << Service_id << endl << endl;;

			ofstream outputride("Ride_Services_List.txt", ios::app);
			{
				outputride << Service_id << endl;
				outputride << r->get_customerID() << endl;
				outputride << r->get_noofpassengers() << endl;
				outputride << r->get_ridetype() << endl;
				outputride << r->get_distance() << endl;
				outputride << r->get_source() << endl;
				outputride << r->get_destination() << endl;
				outputride << r->get_fuelrate() << endl;
				outputride << r->get_driverID() << endl;
				outputride << r->get_driverranking() << endl;
				outputride << r->get_vehicleID() << endl;
				outputride << r->get_vehicleranking() << endl;
				outputride << ride_date << endl;
				outputride << ride_month << endl;
				outputride << ride_year << endl;
				outputride << ride_hour << endl;
				outputride << ride_min << endl;
				outputride << ride_sec << endl;
				outputride << r->get_status() << endl;
				outputride << ride_fare_for_travel << endl;
			}
		}


		if (book == 2)
		{
			cout << endl << endl;
			cout << "Enter Weight Of Goods:  ";
			cin >> dvl_goods_wgt;
			cout << endl;
			cout << "Enter Destination:  ";
			cin.ignore();
			cin.getline(dvl_dstination, 20);
			cout << endl;
			cout << "Enter Source:  ";
			cin.ignore();
			cin.getline(dvl_src, 20);
			cout << endl;
			cout << "Enter Types Of Ride:  ";
			cin.ignore();
			cin.getline(dvl_ride_tp, 20);
			cout << endl;
			cout << "Enter Distance:  ";
			cin >> dvl_distance;
			cout << endl;
			cout << "Enter Booking Date" << endl;
			cout << "Enter Date:  ";
			cin >> dvl_date;
			cout << endl;
			cout << "Enter Month:  ";
			cin >> dvl_month;
			cout << endl;
			cout << "Enter Year:  ";
			cin >> dvl_year;
			cout << endl;
			cout << "Enter Booking Time" << endl;
			cout << "Enter Hour:  ";
			cin >> dvl_hour;
			cout << endl;
			cout << "Enter Minutes:  ";
			cin >> dvl_min;
			cout << endl;
			cout << "Enter Seconds:  ";
			cin >> dvl_sec;
			cout << endl;
			cout << "Enter Fuel Cost:  ";
			cin >> dvl_fuel_cost;
			cout << endl;

			dvl_fare_for_travel = dvl_distance * dvl_fuel_cost;

			for (int r = 0; r < 10; r++)
			{
				dvl_dvr_rank[r] = dvr_ranking[r];
			}

			for (int r = 0; r < 10; r++)
			{
				dvl_vhl_rank[r] = vhl_rank[r];
			}

			//Bubble Sorting Of Drivers According To Their Ranks
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9 - a; b++)
				{
					if (dvl_dvr_rank[b] < dvl_dvr_rank[b + 1])
					{
						float rnk;
						rnk = dvl_dvr_rank[b];
						dvl_dvr_rank[b] = dvl_dvr_rank[b + 1];
						dvl_dvr_rank[b + 1] = rnk;
					}
				}
			}

			//Bubble Sorting Of Vehicles According To Their Ranks
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9 - a; b++)
				{
					if (dvl_vhl_rank[b] < dvl_vhl_rank[b + 1])
					{
						float rnking;
						rnking = dvl_vhl_rank[b];
						dvl_vhl_rank[b] = dvl_vhl_rank[b + 1];
						dvl_vhl_rank[b + 1] = rnking;
					}
				}
			}
			//Printing Driver's Information
			cout << "Driver Id   " << "Driver Name   " << "Driver Ranking   " << endl << endl;



			for (int y = 0; y < 10; y++)
			{
				if (dvl_dvr_rank[y] > 0)//If Rank Exists So Driver Exists
				{
					cout << dvr_identity[y] << " " << dvr_firstname[y] << " " << dvr_lastname[y] << " " << dvr_ranking[y] << endl << endl;

				}
			}

			cout << "Vehicle Id   " << "Vehicle Ranking   " << "Vehicle Category   " << endl << endl;



			for (int y = 0; y < 20; y++)
			{
				if (dvl_vhl_rank[y] > 0)//If Rank Exists So Driver Exists
				{
					cout << vhl_identity[y] << " " << vhl_rank[y] << " " << vhl_fuel_type[y] << endl << endl;
				}
			}

			cout << "Enter The Driver ID:  ";
			cin >> ride_check_dvr_id;
			cout << endl << endl;

			cout << "Enter The Vehicle ID:  ";
			cin >> ride_check_vhl_id;
			cout << endl << endl;

			for (int f = 0; f < 10; f++)
			{
				if (dvr_identity[f] == ride_check_dvr_id)
				{
					dvl_dvr_rank[0] = dvr_ranking[f];
				}
			}

			for (int f = 0; f < 10; f++)
			{
				if (vhl_identity[f] == ride_check_vhl_id)
				{
					dvl_vhl_rank[0] = vhl_rank[f];
				}
			}

			dvl_fare_for_travel = dvl_fare_for_travel * dvl_dvr_rank[0];
			dvl_fare_for_travel = dvl_fare_for_travel * dvl_vhl_rank[0];

			mTime t1;
			t1.set_time(dvl_hour, dvl_min, dvl_sec);
			Date d1;
			d1.setDOB(dvl_date, dvl_month, dvl_year);

			d->set_customerID(cus_identity[i]);
			d->set_goodsweight(dvl_goods_wgt);
			d->set_distance(dvl_distance);
			d->set_bookingDate(d1);
			d->set_bookingTime(t1);
			d->set_source(dvl_src);
			d->set_destination(dvl_dstination);
			d->set_driverID(ride_check_dvr_id);
			d->set_vehicleID(ride_check_vhl_id);
			d->set_status(status);
			d->set_goodstype(dvl_ride_tp);

			srand((unsigned)time(NULL));

			Service_id = rand();

			cout << "Vehicle's Service ID:  " << Service_id << endl << endl;;

			ofstream outputride("Delivery_Services_List.txt", ios::app);
			{
				cout << endl;
				outputride << Service_id << endl;
				outputride << d->get_customerID() << endl;
				outputride << d->get_goodsweight() << endl;
				outputride << d->get_goodstype() << endl;
				outputride << d->get_distance() << endl;
				outputride << d->get_source() << endl;
				outputride << d->get_destination() << endl;
				outputride << d->get_fuelrate() << endl;
				outputride << d->get_driverID() << endl;
				outputride << d->get_vehicleID() << endl;
				outputride << dvl_date << endl;
				outputride << dvl_month << endl;
				outputride << dvl_year << endl;
				outputride << dvl_hour << endl;
				outputride << dvl_min << endl;
				outputride << dvl_sec << endl;
				outputride << d->get_status() << endl;
				outputride << dvl_fare_for_travel << endl;
			}
		}
	}
}

TMS::~TMS()
{
	delete[]c;
	c = nullptr;
	delete[]d;
	d = nullptr;
	delete[]v;
	v = nullptr;

}
int main()
{
	char choose = 0;
	TMS t;


	while (1)
	{
		cout << "===========================================================================" << endl << endl;
		cout << "                           RIDE MANAGEMENT SYSTEM                          " << endl << endl;
		cout << "===========================================================================" << endl << endl;
		cout << "Press A For Adding New Customer" << endl;
		cout << "Press B For Adding New Driver" << endl;
		cout << "Press C For Removing Driver" << endl;
		cout << "Press D For Adding New Vehicle" << endl;
		cout << "Press E For Removing Vehicle" << endl;
		cout << "Press F For Printing The List Of Customers" << endl;
		cout << "Press G For Printing The List Of Drivers" << endl;
		cout << "Press H For Printing The List Of Vehicles" << endl;
		cout << "Press I For Printing The Service History Of Vehicles" << endl;
		cout << "Press J For Printing The Service History Of Customers" << endl;
		cout << "Press K For Printing The Service History Of Drivers" << endl;
		cout << "Press L For Printing The Best Drivers " << endl;
		cout << "Press M For Printing The Drivers With Multiple Liscenses" << endl;
		cout << "Press N For Updating The Salary Of Drivers With Above Ranking" << endl;
		cout << "Press O To Service The Request" << endl;
		cout << "Press P To Cancel The Request" << endl;
		cout << "Press Q To Complete The Service" << endl;
		cout << "Press R For Accesing The Customers Who Used The Same Vehicle On Different Dates" << endl;
		cout << "Press S To Access The Drivers Who Performed Service On The Same Day" << endl;
		cout << "Press T To Access Which Deliveries Are Pending On The Particular Date" << endl;
		cout << "Press U To Access The Drivers Who Have Pending Services" << endl;
		cout << "Press V To Access The Customers Who Cancelled The Services" << endl;

		cin >> choose;
		if (choose == 'a' || choose == 'A')
		{
			system("cls");
			t.new_customer();
		}
		if (choose == 'b' || choose == 'B')
		{
			system("cls");
			t.new_driver();
		}
		if (choose == 'c' || choose == 'C')
		{
			system("cls");
			t.remove_driver();
		}
		if (choose == 'd' || choose == 'D')
		{
			system("cls");
			t.add_vehicle();
		}
		if (choose == 'e' || choose == 'E')
		{
			system("cls");
			t.remove_vehicle();
		}
		if (choose == 'f' || choose == 'F')
		{
			system("cls");
			t.list_of_customers();
		}
		if (choose == 'g' || choose == 'G')
		{
			system("cls");
			t.list_of_drivers();
		}
		if (choose == 'h' || choose == 'H')
		{
			system("cls");
			t.vehicles_complete_data();
		}
		if (choose == 'i' || choose == 'I')
		{
			system("cls");
			t.service_history_vehicle();
		}
		if (choose == 'j' || choose == 'J')
		{
			system("cls");
			t.customer_services();
		}
		if (choose == 'k' || choose == 'K')
		{
			system("cls");
			t.driver_services();
		}
		if (choose == 'l' || choose == 'L')
		{
			system("cls");
			t.driver_ranking();
		}
		if (choose == 'm' || choose == 'M')
		{
			system("cls");
			t.multiple_lsc_drivers();
		}
		if (choose == 'n' || choose == 'N')
		{
			system("cls");
			t.salary_updated();
		}
		if (choose == 'o' || choose == 'O')
		{
			system("cls");
			t.service_request();
		}
		if (choose == 'p' || choose == 'P')
		{
			system("cls");
			t.cancel_request();
		}
		if (choose == 'q' || choose == 'Q')
		{
			system("cls");
			t.complete_service();
		}
		if (choose == 'r' || choose == 'R')
		{
			system("cls");
			t.same_vehicle();
		}
		if (choose == 's' || choose == 'S')
		{
			system("cls");
			t.same_day_delivery();
		}
		if (choose == 't' || choose == 'T')
		{
			system("cls");
			t.date_pending_delivery();
		}
		if (choose == 'u' || choose == 'U')
		{
			system("cls");
			t.driver_pending_delivery();
		}
		if (choose == 'v' || choose == 'V')
		{
			system("cls");
			t.cancelled_customer_services();
		}
	}

	return 0;
}