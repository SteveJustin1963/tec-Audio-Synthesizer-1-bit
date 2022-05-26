# tec-Audio-Synthesizer

```
Q: Now listen here Bond, the Tec-1 has only a 1-bit audio system, 
but I can make it produce more than a square wave. 
Bond: An audio-synthesizer on this, you've got to be joking ? 
Q: I never joke Bond!
Bond: And whats this thing do?
Q: Dont touch that, thats my lunch!
```



### 1-bit music generators 


The main difference between a PC and our speaker is that a PC can use a programmable interval timer to drive the speaker, while our speaker is driven directly by the CPU via one transistor. This means that our CPU is more busy than a PC's CPU in order to produce sound. In order to get accurate sound, you have to sacrifice time from your main program to fit in your exact speaker clicks. Stage 1 uses a 50-percent duty cycle, which produces simple sounds with very narrow rectangular waves. As the duty cycle approaches 0% (or 100%), the harmonic components are more evenly distributed, without the fundamental one strongly dominating. This means that a long tail of harmonic components are lost beyond human hearing ability, and beyond hardware frequency response, so relatively less of the specific sound can be heard. The simple assembly program a.z80 allows the user to modulate the frequency of a continuous sound by pressing the left and right arrow keys, and to modulate the duty cycle by pressing the A and Z keys. The sound of a rectangular wave with a very low duty cycle is very different from that of a square wave. The fundamental harmonic is less and less dominant as the pulse width gets thinner.

When one square is 50µs wide, so the leaning slope of the wave is somewhere around 10µs wide. That's 1/100,000 of a second. This means that the width of the pulse is only 1/100,000th of a second. This is incredibly fast, and explains why the pulse looks more like a triangle than a rectangle. The reason the pulse looks more like a triangle at higher frequencies is because the width of the pulse is so small compared to the wavelength of the sound that it starts to distort the shape of the pulse.

To achieve polyphony...to play multiple notes either be in high or in low state not altogether (high state + high state = also high state).  so switch between low-register melody and high-register melody frequently enough to create the impression of two separate melodies, but not frequently enough for our brain to be cheated into thinking each of these melodies is contiguous. Another method is fast arpeggios ...cheat our brain to accept notes are played at the same time.


more method for polyphonic sounds, using rectangular wave trains 
- PFM; pulse frequency modulation,  changes the instantenous frequency of individual pulses according to the current amplitude of the analog signal while keeping pulse width constant; 
- PWM; pulse width modulation, instead, keeps frequency of pulses constant while modulating their width; 
- PPM; pulse position modulation  — moving the position of the pulse within a constant time slot
- PPM; Pin Pulse Method, involves reducing the duty cycle of one frequency to a very low level (below 10%), and then introducing another frequency also at a very low duty cycle. The resulting pulses will likely not colide on the signal timeline (and if they do, then not frequently), but the two different pulse trains will successfully produce two frequencies which can be discerned by our brain as two notes playing at the same time.
- PIM; Pulse Interleaving Method. ...is ingenious ...the limit medium can be pushed...a special high frequency is used to between high and low states fast enough to not allow the speaker cone to fully extend or collapse and instead keep it in one or more in-between states. Given enough in-between states one can represent a complex sine wave summation as a "stepped" rectangular wave and effectively achieve polyphony. 

"square" wave doesn't really look square; close zoom where the "instant" switches between high and low show actual time delay, and also the switching itself is so rapid that the signal isn't reaching the fully high or the fully low state. Without modulating that base (or "carrier" or "phantom") frequency, we modulate the pulse width with such precision that the signal (and speaker) are maintained at the maximum high, minimum low, or at several levels in between. ...solution transforms digital signal (a stream of bytes in memory) to analog signal (frequency- and amplitude-modulated wave shape which, even though it isn't, can be approximated to a complex sine wave), and also that it is capable of 5-bit sampling resolution, and that the underlying switching frequency is 22kHz.

at highest zoom one can see the carrier frequency wave shaking up and down. By switching high and low states very fast, the programmer is controlling how far up or how far down the signal goes. When zoomed out, the purpose of that shaking becomes obvious: we are building a secondary wave made of small rectangular waves, and that secondary wave is already within human hearing frequency (the wave crests are 4.5ms apart which approximates to 220Hz, that is the note A3). ....able to refine their designs to achieve 5-bit resolution (32 discreet levels) at 22kHz carrier frequency. ...also can adjust more than just frequency. RT.Synth uses a wavetable to provide access to 8 different voices (shapes of waves), each of which also has their ADSR envelope defined. Interestingly enough, in addition to voices mimicking instruments like accoustic piano and banjo, Michael Mahon also included voices for triangle and... square wave. Here is how RT.Synth uses square waves to generate various instruments, includng square waves!

see [Electric Duet](https://github.com/SteveJustin1963/tec-Audio-Synthesizer/blob/main/docs/Electric%20Duet.pdf)
















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
