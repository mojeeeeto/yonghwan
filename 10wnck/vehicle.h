class vehicle
{
	protected:
		bool has_name;
		int wheel_number;
		int max_speed;
	public:
		vehicle();
		vehicle(int wheel,int max);
		vehicle(int wheel,int max, bool has);
		int get_wheel_number();
		int get_max_speed();
		bool get_has_name();
		const char* get_class_name();

		void set_wheel_number(int wheel);
		void set_max_speed(int max);
		void set_has_name(bool has);

};
