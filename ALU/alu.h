#include<systemc.h>

SC_MODULE(alu)
{
	sc_in<sc_uint<4>>A,B; //operands
	sc_in<sc_uint<3>>op; //operation to perform. 1-addition, 2-subtraction,3-left shift, 4-right shift

	sc_out<sc_uint<4>>output;
  
	//local vars
	sc_uint<4> R1, R2, out_reg;
	
	void compute()
	{
		R1 = A.read();
		R2 = B.read();
		switch(op.read())
		{
			case 1: out_reg = R1 + R2;break; //to add the operands
			case 2: out_reg = R1 - R2;break; //to subtract the operands
			case 3: out_reg = R1>>1;break; //right shift the A operand
			case 4: out_reg = R2<<1;break; //left shift the B operand
      default: out_reg =0;
		}
		output.write(out_reg);
	}
	SC_CTOR(alu)
	{
		SC_METHOD(compute);
		sensitive<<A<<B<<op;
	}

};
