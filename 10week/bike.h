
class bike : public vehicle
{
private:
	const char* bike_name;
	int bike_number;
public:
	bike();
	bike(int wheel,int max);
	bike(int wheel,int max, const char* name);
	bike(int wheel,int max, const char* name,int number);
	bike(int wheel,int max, const char* name,int number, bool hasname);
	
	int get_bike_number();
	const char* get_bike_name();
	const char* get_class_name();
	void set_bike_number(int number);
	void set_bike_name(const char* name);
};
