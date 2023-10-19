#include<systemc.h>

SC_MODULE(driver)
{
	sc_out<bool>s0,s1,i0,i1,i2,i3;
	
	void inputs()
	{
	i0.write(true);
	s0.write(false);
	s1.write(false);
	wait(5,SC_NS);
	
	i1.write(false);
	s0.write(true);
	s1.write(false);
	wait(5,SC_NS);
	
	i2.write(true);
	s0.write(false);
	s1.write(true);
	wait(5,SC_NS);
	
	i3.write(false);
	s0.write(true);
	s1.write(true);
	wait(5,SC_NS);
	}
	
	SC_CTOR(driver)
	{
		SC_THREAD(inputs);
		sensitive<<s0<<s1<<i0<<i1<<i2<<i3;
	}
};
	
