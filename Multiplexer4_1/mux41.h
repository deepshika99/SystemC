#include<systemc.h>
SC_MODULE(mux41)
{
	sc_in<bool>i0;
	sc_in<bool>i1;
	sc_in<bool>i2;
	sc_in<bool>i3;
	sc_in<bool>s0;
	sc_in<bool>s1;
	sc_out<bool>out;
	void compute()
	{
		out.write( (!(s0.read()) && !s1.read() && i0.read()) || 
					(s0.read() && !s1.read() && i1.read())  || 
					(!(s0.read()) && s1.read() && i2.read())
					|| (s0.read() && s1.read() && i3.read()) );
	}
	SC_CTOR(mux41)
	{
		SC_METHOD(compute);
		sensitive<<i0<<i1<<i2<<i3<<s0<<s1;
	}
};
