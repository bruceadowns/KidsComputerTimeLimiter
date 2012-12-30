KidsComputerTimeLimiter
=======================

The Downs Kids' Computer Time Limiter
A progressive experiment with limiting my kid's computer time.
Visual C++ 6.0 SP5

It will be built in a progressively more secure manner.

v1 - baseline
* Initiate system shutdown after N mins
* This can be thwarted by killing the process 
* via taskmgr.exe, pskill.exe, procexp.exe
* On reboot dkctl needs to be restarted

v2 - durable
* Make durable
* INI file
* Plaintext password
* Save password, time limit, start time
* RunOnce - start on logon, check time lapse

v3 - prevent kill
* Prevent killing process
* Options dialog - lapse period, action shutdown, logoff, master password
* Move INI to registry
* Obfuscate password - rot13

v4 - secure encryption
* Secure password with key
* Save key to protected file

vMisc
* Time left countdown
* Custom Icon
* New Name
* Cert/key based encryption
* User Mgr, Admin Mgr, Service

Why VC++ 6.0?
* No runtime required.
* msvcrt.dll available on all windows versions.
* Great development IDE
* Ease in debugging
