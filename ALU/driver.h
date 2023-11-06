#include<systemc.h>

SC_MODULE(driver)
{
	sc_out<sc_uint<4>> A,B;
	sc_out<sc_uint<3>> op;
	sc_in<bool> clk;

	void inputs()
	{
		op.write(1);
		A.write(0b1010);
		B.write(0b0101);
		wait(10,SC_NS);

		op.write(2);
		A.write(0b1011);
		B.write(0b0101);
		wait(10,SC_NS);

		op.write(3);
		A.write(0b1010);
		wait(10,SC_NS);

		op.write(4);
		B.write(0b1010);
		wait(10,SC_NS);

		sc_stop();

	}
	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		
	}
};
