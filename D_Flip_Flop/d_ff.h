#include"systemc.h"

SC_MODULE(d_ff)
{
	sc_in<bool>d;
	sc_in<bool>clk;
	sc_in<bool>rst;
	sc_out<bool>q;
	
	void compute_ff_out()
	{
		if(rst.read())
		{
			q.write(0);
		}
		else
		{
			q.write(d.read());
		}
	}
	SC_CTOR(d_ff)
		{
			SC_METHOD(compute_ff_out);
			sensitive<<clk.pos();
			sensitive<<d<<rst;
		}
};
