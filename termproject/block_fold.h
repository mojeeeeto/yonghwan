#include "board.h"

class block_fold : public block
{
private:
	block* a;
	block* b;
	block* c;
	int mode;

public:
	block_fold();
	block* get_a();
	block* get_b();
	block* get_c();
	int get_mode();
	void inc_mode();
	
};