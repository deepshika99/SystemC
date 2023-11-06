/* SoC Lab Assignment:
Create and write a SystemC code for an 4-bit ALU to perform 4 different operations such as addition, subtraction, left shift, and right shift operations. 
Verify the functionality of design using sufficient test vectors and upload all the code and the results as a single pdf. */

#include<systemc.h>
#include"alu.h"
#include"driver.h"
#include"monitor.h"

int sc_main(int argc, char *argv[])
{
	sc_signal<sc_uint<4>>A,B,output;
	sc_signal<sc_uint<3>>op;
	sc_clock testclk("Clock",10,SC_NS,1,SC_NS);

	alu alu1("alu");
	alu1.A(A);alu1.B(B);alu1.op(op);alu1.output(output);

	driver drv("driver");
	drv.A(A);drv.B(B);drv.op(op);drv.clk(testclk);

	monitor mon("monitor");
	mon.A(A);mon.B(B);mon.op(op);mon.output(output); mon.clk(testclk);
	

	sc_trace_file *Tf;

	Tf = sc_create_vcd_trace_file("traces");
	sc_trace(Tf,A,"A");
	sc_trace(Tf,B,"B");
	sc_trace(Tf,op,"op");
	sc_trace(Tf,output, "output");
	sc_start(100,SC_NS);
	sc_close_vcd_trace_file;

	return 0;
}
