

## Nico

Ultra-compact USB dongle with a 56-LED Charlieplexed visualizer and native CH552 8051 control.



## Total Hours : 14.4 hours





#### August 27, 2:33 am 
 Time Spent : 1.8 hours  
Starting with the #dongle ysws, I found this pretty cool ysws to make my own dongle! On top of it, it is run by @Sophia ( fallout was so fun cause of her ), okay so now I need an idea, after scrolling through internet and braingstorming I came up with designing an LED matrix, using the CH32V003 chip 
One of the inspo I found : 
[![Five Boards](https://github.com/limingjie/CH32V003-Tristate-Multiplexing-LED/raw/main/images/CH32V003\_Tristate\_Multiplexing\_LED\_Five\_Boards.webp)](https://github.com/limingjie/CH32V003-Tristate-Multiplexing-LED/blob/main/images/CH32V003\_Tristate\_Multiplexing\_LED\_Five\_Boards.webp)

After talking with @Sophia on channel I found out that I should switch to a chip that supports native USB support, so I had to switch to a different chip ( CH552G ) and have a led matrix using that

---

#### August 27, 4:22 am

Time Spent : 1.6 hours  
I started by importing the CH552G symbol and footprint from lcsc using the easyeda2kicad library, looked up at the CH552G datasheet then got shocked that it was in Chinese and had to use a translator! I found out this very amazing [blog](https://stkwans.blogspot.com/2012/05/designing-large-charlieplex.html) on internet explaining the charlieplexxed matrixes I used that to design my matrix and connected everything in the schematics! 
<img width="1656" height="817" alt="Screenshot 2026-08-28 045420" src="https://github.com/user-attachments/assets/fa9ba4c4-cecf-4c7c-8323-ad81399f55c3" />

---

#### August 27, 10:01 pm
Time Spent : 2.2 hours  
In this journal, I placed the footprints for the components, I am using 0603 footprints making it easy to hand solder and still be compact! This is how it looked after importing the components 
<img alt="Screenshot 2026-08-27 044136" src="https://github.com/user-attachments/assets/00f14537-33d6-4393-aa57-eb4149bfc369" />  

then I started arranging everything, my first approach was to arrange everything manually, took a lot of time wasnt accurate 2/10, next method which I found was creating an array, it arranged the leds on what i wanted but randomly rather than in sequence, 5/10, after that my only hope was to arange them using precise move tool which worked fast, was accurate and yippee  
<img alt="Screenshot 2026-08-27 145012" src="https://github.com/user-attachments/assets/03b64927-2e40-45fa-9567-ef97ecb23082" />

--- 

#### August 28, 2:31 am 
Time spent : 3.8 hours  
After talking with sophia, I decided to rotate the LEDs by 45 degrees to make it look dope! then started routing everything, it was my first time routing a charlieplexxed matrix so it was tricky but I got all the horizontal traces on top layer and vertical ones on bottom, making it easier! 
<img  alt="Screenshot 2026-08-27 151842" src="https://github.com/user-attachments/assets/171e4e21-dffd-4d1e-8ff3-234efa5f5350" />  

<img  alt="Screenshot 2026-08-27 145918" src="https://github.com/user-attachments/assets/9df69eb7-acd5-4f38-9d9f-e15e1c9295b8" />  

--- 

### August 28, 6:30 am
Time spent : 3 hours  
After I finished routing, sophia told to bring the LEDs closer, now I agreed with her, thats why had to change the shape, bring my leds closer and route everything again! It was easier this time and took a lot less time! I also decided to add a keyring to it! makes it look cool
<img  alt="Screenshot 2026-08-28 045139" src="https://github.com/user-attachments/assets/a13bca7a-9a01-4830-a024-ab8f16b20330" />
After that I got some art from pinterest for my board! and since i am getting ENIG having it etched on solder mask makes it look pretty cool 
<img  alt="Screenshot 2026-08-28 031728" src="https://github.com/user-attachments/assets/be920ef2-087b-412e-91ed-17ee8b691f9a" />
<img  alt="Screenshot 2026-08-28 032648" src="https://github.com/user-attachments/assets/87bc61f6-23de-4806-9da5-21b59eb51216" />
Perfect to ship it now!

---
## August 29, 1:30 am

Time Spent : 2 hours   

Last but not the least, this is my final journal, uploading all the files to github, writing the readme and most importantly getting the BOM, the price of this dongle went crazy already in 100s but with coupons and hand soldering I brought it down to 74! ( Sorry Sophia for expensive PCB but its so cool ) 

---

#### If you are reading by here, thanks! I hope this inspires you to make one of your own! Special credits to Sophia ( I swear I have said Sophia so many times in my journal ) and HackClub!



