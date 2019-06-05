# CID_Faker
# WARNING ; THIS PROJECT IS A PATCH MADE BY MYSELF, FOR MYSELF, AND IT AIMS TO COMPENSATE
# THE LACK OF BUG CORRECTIONS IN THIRD PARTY REPLACEMENT SCREENS (CHINESE ANDROID BASED
# SCREENS) THAT DO NOT HAVE IMPLEMENTED THIS PARTICULAR CASE ON THEIR MCU FIRMWARE
# WE ARE TALKING ABOUT INJECTING DATA TO THE CAR NETWORK, THIS IS AT YOUR OWN RISK !!!
# I WILL NOT BE RESPONSIBLE FOR ANY HARM YOU MAY CAUSE TO YOUR CAR, YOURSELF, OR ANY OTHER
#   YOU HAVE BEEN WARNED !!!

A CID can bus simulator:

CID (Central Information Display) on BMW cars from 2004 to 2011 are the designation for the car LCD screen.
Some of those screens are connected to the can bus of the car (at least BMW flap screens).
If you try to replace the screen with something else (like an Android Head Unit) you'll loose the ability to 
interact with the BMW original menu (no actions from idrive interpreted).



This project supposes that this is because of the absence of the can message id from the screen : "why take into
account moves from idrive if no screen detected" ... thats what the engineer may have thought when implementing this
on the CCC controller ...


This little code will so generate fake CID id messages on the can bus of the car, to simulate the presence of the CID.
CID sends messages with id 0x33a (status) and 0x4f3 (network).
All the main job will be to find the right messages, their combinations and timings.


Project uses platformIO for easy compilation and development.

For now, I'm using a Pro Micro board 5V@16Mhz, and a well known MCP2515 CAN Controller module, more precisely the
MCP2515 CAN controller with a 8Mhz oscillator and TJA1050 CAN transceiver.


