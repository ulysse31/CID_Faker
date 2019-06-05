This library is a fork of :

https://github.com/coryjfowler/MCP_CAN_lib


I needed to modify it a little bit for a timeout bug in the return value of sending message function:

TIMEOUTVALUE was originally 50, which might work correctly in various cases, but creates a bug when using the lib on a 100Kps CAN with a 8Mhz MCP oscillator.
Setting this value to 100 makes it retries enought to have a successful send.
