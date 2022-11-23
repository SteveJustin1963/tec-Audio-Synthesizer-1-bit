// Pulse-Position Modulation (PPM) is a modulation method 
// that only makes every pulse in the carrier pulse sequence change with time 
// but without changing the shape and amplitude of the pulse signal.
// c code to do the above for a z80 cpu




 

void Z80_PPM(int carrier[], int data[])
{
 
    int i,j,k;
 
    for(i=0;i<carrier_length;i++)
    {
        for(j=0;j<data_length;j++)
        {
            if(i==(j*carrier_length/data_length))
            {
                for(k=0;k<8;k++)
                {
                    if((data[j]&(1<<k))!=0)
                    {
                        carrier[i]|=(1<<k);
                    }
                    else
                    {
                        carrier[i]&=~(1<<k);
                    }
                }
            }
        }
    }
}
