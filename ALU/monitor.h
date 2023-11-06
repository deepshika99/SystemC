#include<systemc.h>

SC_MODULE(monitor)
{
	sc_in<sc_uint<4>>A,B,output;
	sc_in<sc_uint<3>>op;
	sc_in <bool> clk;
	void mon()
	{
		cout << "Op :" << op<< " A :" <<A<< " B :" <<B<< " Output :" << output << endl;
	}
	SC_CTOR(monitor)
	{
		SC_THREAD(mon);
		sensitive<<clk.pos();
	}
};
