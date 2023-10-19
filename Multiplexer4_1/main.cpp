#include"systemc.h"
#include"mux41.h"
#include"driver.h"
#include"monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s0,s1,i0,i1,i2,i3,out;
	
	mux41 mux("mux41");
	driver drive("driver");
	monitor mont("monitor");
	
	
	mux.s0(s0);mux.s1(s1);mux.i0(i0);
	mux.i1(i1);mux.i2(i2);mux.i3(i3);mux.out(out);
	drive.s0(s0);drive.s1(s1);drive.i0(i0);
	drive.i1(i1);drive.i2(i2);drive.i3(i3);
	mont.s0(s0);mont.s1(s1);mont.i0(i0);
	mont.i1(i1);mont.i2(i2);mont.i3(i3);mont.out(out);
	
	sc_trace_file *Tf;
	Tf = sc_create_vcd_trace_file("traces");
	sc_trace(Tf,s0,"s0");
	sc_trace(Tf,s1,"s1");
	sc_trace(Tf,i0,"i0");
	sc_trace(Tf,i1,"i1");
	sc_trace(Tf,i2,"i2");
	sc_trace(Tf,i3,"i3");
	sc_trace(Tf,out,"out");
	sc_start(30,SC_NS);
	sc_close_vcd_trace_file(Tf);
	return 0;
	
};
