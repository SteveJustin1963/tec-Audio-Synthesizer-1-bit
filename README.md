# tec-Audio-Synthesizer

```
Q: Now listen here Bond, the Tec-1 has only a 1-bit audio system, but I can make it produce more than a square wave. 
Bond: An audio-synthesizer on this, you've got to be joking ? 
Q: I never joke Bond!
Bond: And whats this thing do?
Q: Dont touch that, thats my lunch!
```



### 1-bit music generators 
from web; " PCs drive speaker with a PIT (programmable interval timer) , tec1 speaker is driven directly by the CPU via 1 transistor. our CPUs is more busy than PC's CPU to get sound. you have to sacrifice time from your main program to fit in your exact speaker clicks. stage 1 use 50-percent duty cycle, explore simple sounds with very narrow rectangular waves. As the duty cycle approaches 0% (or 100%), the harmonic components are more evenly distributed, without the fundamental one strongly dominating which, in turn, means that a long tail of harmonic components are lost beyond human hearing ability, and beyond hardware frequency response, so relatively less of the specific sound can be heard. 

To explore the behavior of very low-duty cycle rectangular waves at different frequencies, see simple assembly program a.z80 ... is able to modulate frequency of the continuous sound with a pair of keys (arrows left and right), and modulate the duty cycle with another pair of keys (A and Z). Here is what modulating the duty cycle sounds like, and how frequency distrubution changes. Pay attention to the tall red line to the very left of the image. It represents the fundamental harmonic, and it is less and less dominating as the pulse width gets thinner:















### Ref
- https://create.arduino.cc/projecthub/projects/tags/synthesizer
- https://github.com/luisllamasbinaburo/Arduino-SyncWaveforms
- https://sol.gfxile.net/z80/ch12.html
- https://github.com/jarikomppa/speccy/
- https://www.electronics-tutorial.net/finite-state-machines/Algorithmic-State-Machines/ASM-chart-for-signal-generator/
- https://scienceprog.com/avr-dds-signal-generator-in-line-asm-explained/
- https://www.chibiakumas.com/z80/platform3.php?noui=1
- https://www.gamejournal.it/the-sound-of-1-bit-technical-constraint-as-a-driver-for-musical-creativity-on-the-48k-sinclair-zx-spectrum/
- http://forgottencomputer.com/retro/sound/#zxspectrum
- 
