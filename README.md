Lyrabar
=======

http://lyrabar.tech/

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2014 Vertcoin Developers
Copyright (c) 2015 Lyrabar Developers

What is Lyrabar?
----------------

Lyrabar is rock solid, rare cryptocoin bar using Lyra2REv2 as a proof-of-work algorithm.

 - Lyra2RE(v2) as algorithm
 - 2.5 minute block targets
 - 1971000 total LYB
 - PoW subsidy: 5 coins per block
 - Block reward will half at blocks 210240, 420480, 630720 (one year between each)
 - Last PoW block is 840960
 - Difficulty retargeting with Kimoto's Gravity Well
 - Stealth addresses (experimental, use at own risk)


Ports for client connectivity
-----------------------------
 
Mainnet RPC 4047
Mainnet P2P 4046

--

Testnet RPC 14047
Testnet P2P 14046


Compiling on Linux
------------------

Build the compilation environment with all needed dependencies to compile the wallet (use `sudo` if not as root)

	`apt-get install git automake autoconf libtool build-essential gcc`
	`apt-get install libqt5-dev libcurl4-openssl-dev libboost-all-dev libstdc++6 libssl-dev`
	`apt-get install libqrencode-dev libpng-dev libminiupnpc-dev libgmp-dev`
	
Download the BerkeleyDB 4.8.30 source package (use sudo if installing to `/opt`)

	`cd /opt`
	`wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz`

Check shasum of the downloaded package to make sure it is not a fake and downloaded completely. (Optional)

	`echo '12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef  db-4.8.30.NC.tar.gz' | sha256sum -c`

Extract the BerkeleyDB 4.8.30 source package and build it (use `sudo` if installing to `/opt`):

	`tar -xvf db-4.8.30.NC.tar.gz`
	`cd db-4.8.30.NC/build_unix`
	`mkdir -p build`
	`BDB_PREFIX=$(pwd)/build`
	`../dist/configure --disable-shared --enable-cxx --with-pic --prefix=$BDB_PREFIX`
	`make install`
	`cd ../..`

Also, we need to install the secp256k1 module (use sudo if installing to /opt):
	
	`cd /opt`
	`git clone https://github.com/bitcoin/secp256k1`
	`cd secp256k1`
	`git checkout 4c63780710351ffcc52341497e3ca0e518fbad79`
	`./autogen.sh`
	`./configure`
	`make`
	`make install`

Update the system LD cache to tell the environment about the freshly installed secp256k1 existence,

	`sudo ldconfig` (or `ld-config`, depends on system)

All dependencies should now be installed, next part is the wallet compilation itself.

Jump to current user's home directory and clone latest wallet source code from GitHub.

	`cd ~/`
	`git clone https://github.com/Lyrabar/Lyrabar`
	`cd Lyrabar`

Makefiles for the wallet source code are in `src/`. To build the Linux wallet daemon, type in Lyrabar directory:

	`cd src`
	`make -f makefile.unix`
	`strip lyrabard`
	
To run freshly compiled wallet daemon, type:
	
	`./lyrabard`

Makefiles for the Qt client are in `src/`. To compile and run them:

	`cd src`
    	`make -f makefile.linux-mingw`
	`strip lyrabar-qt`
	
To run freshly compiled wallet Qt client, type:
	
	`./lyrabar-qt`

Both freshly compiled clients should work at this point if both compilations ended without errors.
If you get stuck with errors and need to start compilation again, you can install missing dependencies and continue compilation where it ended with errors. This is useful to spare some time when finding needed dependencies or fixing problems related to compilation. Hitting Ctrl+C key combination kills compilation process. If you want to start the compilation from clear table, clear the compilation table by using a parameter "clean" after used makefiles name, for example `make -f makefile.unix clean`.

If you are facing issues when compiling and error comes with `stealth.h`, then fetching exact version of secp256k1 library from GitHub have been failed. If checking out the right commint and compiling again does not help make a difference, delete the cloned version from where you installed it. Here's a manual install guide for libsecp256k1 and a URL to right commit source code package. The installation follows similar steps like in earlier guide, but we change directory to the designed install directory and fetch manually source code there. (If use /opt, type these commands with sudo):

	`cd /opt`
	`wget https://github.com/bitcoin/secp256k1/archive/4c63780710351ffcc52341497e3ca0e518fbad79.zip -O secp256k1.zip`
	`unzip secp256k1.zip`
	`cd secp256k1`
	`./autogen.sh`
	...and follow the rest compilation steps with `./configure` etc. like at the earlier guide.
	
Recompile the wallet client again after successful libsecp256k1 installation.


Compiling on Windows
--------------------
Install Python 3.3 for Windows, Activeperl package (64-bits version is ok)
Use MSYS 32- or 64-bit environment installer with gcc 4.8.2 or gcc 4.6.2, both versions seem to work. Install as minimal environment. Select 64 bits MSYS version if you want to compile a 64-bit binary executable of the wallet.
Get source codes of Qt 5.3+, Berkeley DB 4.8, Boost 1.58+, libpng, libqrencode, libgmp, miniupnpc, openssl and protobuf. Most versions of the dependencies compiles without errors, but if not, try earlier version.
MSYS users maybe can't clone from git, use right secp256k1 source code version used at secp256k1 manual installation part.
Compile every dependency from MSYS or Windows shell, if MSYS (MingW) installer was for 64-bits, your dependencies will be compiled as 64 bits versions. After dependencies got successfully compiled, compile the wallet itself, open a Windows shell and type next including exact Qt library version number on Windows PATH you have installed:

Daemon wallet client

	`cd C:\lyrabar\src\`
	`mingw32-make -f makefile.mingw`
	`strip lyrabard.exe`

Graphical Qt wallet client

	`set PATH=%PATH%;C:\Qt\5.3.2\bin`
	`cd C:\lyrabar\`
	`qmake "USE_QRCODE=1" "USE_UPNP=-" "USE_IPV6=1" Lyrabar-qt.pro`
	`mingw32-make -f Makefile.Release`
	`strip lyrabar-qt.exe`

License
-------

Lyrabar is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

