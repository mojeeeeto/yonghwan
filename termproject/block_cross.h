#include "block_tree.h"

class block_cross : public block
{
private:
	block* a;
	block* b;
	block* c;
	block* d;
	block* e;

public:
	block_cross();
	block* get_a();
	block* get_b();
	block* get_c();
	block* get_e();
	block* get_d();

};