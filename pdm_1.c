//Produce s samples of p periods of a sine wave
 function sample(int s, int p)
   s := s - 1
   var real ω := p × π × 2 ÷ s
   var real[0..s] pcm
   for i from 0 to s
       pcm[i] := sin(ω × i)
   return pcm
 
 //Encode samples into pulse-density modulation
 function encode(int[0..s] pcm)
   var real[0..s] pdm
   var real r := 1
   for i from 0 to s
       r := pcm[i] - r
       if r > 0
           pdm[i] := 1
           r := 1 - r
       else
           pdm[i] := 0
           r := -1 - r
   return pdm

convert the above to c code


int sample(int s, int p)
{
   s = s - 1;
   float ω = p * π * 2 / s;
   float[] pcm;
   for (int i = 0; i <= s; i++)
       pcm[i] = sin(ω * i);


   return pcm;
}
 
int encode(float[] pcm)
{
   float[] pdm;
   float r = 1;
   for (int i = 0; i <= s; i++)
   {
       r = pcm[i] - r;
       if (r > 0)
       {
           pdm[i] = 1;
           r = 1 - r;
       }
       else
       {
           pdm[i] = 0;
           r = -1 - r;
       }
   }
   return pdm;
}


convert to forth 83 code


: sample ( s p -- pcm )
   1- s p π 2 f* p f/ s f/range sin
;
: encode ( pcm -- pdm )
   1.0 r>
   pdm 1
   r>
   pdm 0
   r>
;
