#include "block_fold.h"

class block_tree : public block
{
private:
	block* a;
	block* b;
	block* c;
	int mode;

public:
	block_tree();
	block* get_a();
	block* get_b();
	block* get_c();

	int get_mode();
	void inc_mode();

};