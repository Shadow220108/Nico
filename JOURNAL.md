

\## Nico

&#x09;Ultra-compact USB dongle with a 56-LED Charlieplexed visualizer and native CH552 8051 control.



\## Total Hours : 





\#### August 27, 2:33 am 

&#x09; Time Spent : 1.8 hours

&#x09; 

&#x09;Starting with the #dongle ysws, I found this pretty cool ysws to make my own dongle! On top of it, it is run by @Sophia ( fallout was so fun cause of her ), okay so now I need an idea, after scrolling through internet and braingstorming I came up with designing an LED matrix, using the CH32V003 chip 

&#x09;One of the inspo I found : 

&#x09; \[!\[Five Boards](https://github.com/limingjie/CH32V003-Tristate-Multiplexing-LED/raw/main/images/CH32V003\_Tristate\_Multiplexing\_LED\_Five\_Boards.webp)](https://github.com/limingjie/CH32V003-Tristate-Multiplexing-LED/blob/main/images/CH32V003\_Tristate\_Multiplexing\_LED\_Five\_Boards.webp)

&#x09; After talking with @Sophia on channel I found out that I should switch to a chip that supports native USB support, so I had to switch to a different chip ( CH552G ) and have a led matrix using that



\#### August 27, 4:22 am

&#x09;Time Spent : 1.6 hours

&#x09;

&#x09; I started by importing the CH552G symbol and footprint from lcsc using the easyeda2kicad library, looked up at the CH552G datasheet then got shocked that it was in Chinese and had to use a translator! I found out this very amazing \[blog](https://stkwans.blogspot.com/2012/05/designing-large-charlieplex.html) on internet explaining the charlieplexxed matrixes I used that to design my matrix and connected everything in the schematics! 

&#x09; !\[\[Pasted image 20260827042821.png]]



