class car : public vehicle
{
	private:
		const char* car_name;
	public:
		car();
		car(int wheel,int max);
		car(int wheel,int max,const char* name);
		car(int wheel,int max,const char* name, bool hasname);
		const char* get_car_name();
		const char* get_class_name();
		void set_car_name(const char* name);
		


};
