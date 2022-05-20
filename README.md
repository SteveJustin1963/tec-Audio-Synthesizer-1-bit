# tec-Audio-Synthesizer

```
Q: Now listen here Bond, the Tec-1 has only a 1-bit audio system, but I can make it produce more than a square wave. 
Bond: An audio-synthesizer on this, you've got to be joking ? 
Q: I never joke Bond!
Bond: And whats this thing do?
Q: Dont touch that, thats my lunch!
```



### 1-bit music generators 
The main difference between a PC and our speaker is that a PC can use a programmable interval timer to drive the speaker, while our speaker is driven directly by the CPU via one transistor. This means that our CPU is more busy than a PC's CPU in order to produce sound. In order to get accurate sound, you have to sacrifice time from your main program to fit in your exact speaker clicks. Stage 1 uses a 50-percent duty cycle, which produces simple sounds with very narrow rectangular waves. As the duty cycle approaches 0% (or 100%), the harmonic components are more evenly distributed, without the fundamental one strongly dominating. This means that a long tail of harmonic components are lost beyond human hearing ability, and beyond hardware frequency response, so relatively less of the specific sound can be heard. The simple assembly program a.z80 allows the user to modulate the frequency of a continuous sound by pressing the left and right arrow keys, and to modulate the duty cycle by pressing the A and Z keys. The sound of a rectangular wave with a very low duty cycle is very different from that of a square wave. The fundamental harmonic is less and less dominant as the pulse width gets thinner.


















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
