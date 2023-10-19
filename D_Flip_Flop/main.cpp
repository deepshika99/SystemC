#include"systemc.h"
#include"d_ff.h"
#include"driver.h"
#include"monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> d,rst,clk,q;
	sc_clock clock("clk",1,SC_NS);
	
	d_ff dff1("dff");
	driver drive("driver");
	monitor mon("monitor");
	
	dff1.d(d);dff1.q(q);dff1.rst(rst);dff1.clk(clk);
	drive.d(d);drive.rst(rst);drive.clk(clk);
	mon.d(d);mon.rst(rst);mon.q(q);mon.clk(clk);
	
	sc_trace_file *Tf;
	Tf = sc_create_vcd_trace_file("trace");
	sc_trace(Tf,clk,"clk");
	sc_trace(Tf,d,"d");
	sc_trace(Tf,rst,"rst");
	sc_trace(Tf,q,"q");
	sc_start(300,SC_NS);
	sc_close_vcd_trace_file(Tf);
	return 0;
}
