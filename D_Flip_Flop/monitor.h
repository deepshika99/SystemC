#include"systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool>d,rst,clk,q;
	
	void mon()
	{
		cout<<"rst= "<<rst<<"d = "<<d<<" output q = "<<q<<endl;
	}
	SC_CTOR(monitor)
	{
		SC_METHOD(mon);
		sensitive<<d<<rst<<clk.pos();
	}
};

