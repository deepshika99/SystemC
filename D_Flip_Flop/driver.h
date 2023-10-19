#include "systemc.h"

SC_MODULE(driver)
{
	sc_out<bool>d,rst;
	sc_in<bool>clk;
	
	void inputs()
	{
		rst.write(true);
		d.write(true);
		wait(50,SC_NS);
		
		rst.write(false);
		d.write(false);
		wait(50,SC_NS);
		
		d.write(true);
		wait(50,SC_NS);
	}
	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive<<rst<<d<<clk.pos();
	}
};

