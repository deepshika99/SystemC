#include"systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool>s0,s1,i0,i1,i2,i3,out;
	void mon()
	{
		cout<<"Inputs: s1:"<<s1<<" s0:"<<s0<<" i0:"<<i0<<" i1:"<<i1<<
		" i2:"<<i2<<" i3:"<<i3<<endl<<"Output:"<<out<<endl;
	}
	SC_CTOR(monitor)
	{
	SC_METHOD(mon);
	sensitive<<s0<<s1<<i0<<i1<<i2<<i3;
	}
};
